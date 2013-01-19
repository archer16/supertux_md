#!/bin/bash

#function set_path($path)
function set_path() {
  echo "Converting $1..."
  image_path=$1
  mkdir -p $target/$1
  cd $source/images/$1
}

#function build_pack($pack_file,$images)
function build_pack() {
  rm -f $1
  convert $2 -background none +append $1
}

#function scale($image)
function scale() {
#  convert \( \( $2 -channel alpha +dither -threshold 50% \) +dither -scale 50% \) -channel alpha +dither -threshold 50% $1
  convert $1 +dither -scale 50% $1
}

#function solid_colors($image)
function solid_colors() {
  #convert $1 -channel alpha +dither -threshold 75% $1
  convert $1 +dither -type TrueColorMatte png8:$1
}

#function recolor($image,$colors)
function recolor() {
  convert $1 +dither -colors $2 $1
}

#function recolor_staged($image,$colors)
function recolor_staged() {
  convert $1 +dither \( \( \( \( +dither -colors 1024 \) +dither -colors 256 \)  +dither -colors 64 \)  +dither -colors 32 \)  +dither -colors $2 $1
}

#function posterize($image,$level)
function posterize() {
  convert $1 +dither -posterize $2 $1
}

#function remap($image,$palette)
function remap() {
  convert $1 +dither -remap $2 $1
}

#function resize($image,$colors,$target_image)
function resize() {
  solid_colors $1
  scale $1
  solid_colors $1
  recolor_staged $1 $2
}

#function convert($image,$colors)
function import() {
  convert $1 $temp/1.mpc
  resize $temp/1.mpc $import_colors
  convert $temp/1.mpc $target/$image_path/$1
  #remap $target/$image_path/$1 $palette
}

#function import_loop($images)
function import_loop() {
  images=("$@")
  line=
  for image in "${images[@]}"
  do
    echo "  * Importing $image_path/$image"
    import $image
    line=$line" "$image
  done
}

function animate() { #($prefix,$delay)
  echo "  * Creating animation for $1*.png"
  convert -dispose background -delay $2 -loop 0 $1*.png _ani_$1.gif
}

function create_palette() { # ($image,$palette)
  echo "  * Creating color palette"
  #convert $1 -unique-colors -colors 16 -unique-colors -scale 1000% $2
  convert $1 -unique-colors txt:-|php $genpal|convert txt:- -unique-colors -scale 1000% $2
}

function create_tiles() { # $image,$size
  convert $1 -crop $2 $1
  #convert -crop $size $1.png $1_%d.png
}
