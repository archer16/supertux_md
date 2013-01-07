#!/bin/bash
source=$(cat ../supertux_source.txt)
target=$(pwd)
palette=$target/../genisis.palette.png
temp=/tmp

#function set_path($path)
function set_path() {
  echo Converting $1...
  image_path=$1
  mkdir -p $target/$1
  cd $source/images/$1
}

#function build_pack($images,$pack_file)
function build_pack() {
  convert $2 +append $1
}

#function scale($image)
function scale() {
#  convert \( \( $2 -channel alpha +dither -threshold 50% \) +dither -scale 50% \) -channel alpha +dither -threshold 50% $1
  convert $1 +dither -scale 50% $1
}

#function solid_colors($image)
function solid_colors() {
  convert $1 -channel alpha +dither -threshold 50% $1
}

#function recolor($image,$colors)
function recolor() {
  convert $1 +dither -colors $2 $1
}

#function posterize($image,$level)
function posterize() {
  convert $1 +dither -posterize $2 $1
}

#function remap($image)
function remap() {
  convert $1 +dither -remap $palette $1
}

#function recolor($image,$colors,$target)
function resize() {
  solid_colors $1
  scale $1
  solid_colors $1
  #posterize $1 6
  recolor $1 1024
  recolor $1 256
  recolor $1 64
  recolor $1 32
  recolor $1 $2
  #remap $1
  cp $temp/4.png $target/$image_path/small.png
}


#==================================================[ create pack for small tux ]==================================================
set_path creatures/tux/small

build_pack $temp/1.png "walk-0.png walk-1.png walk-2.png walk-3.png walk-4.png walk-5.png walk-6.png walk-7.png idle-0.png idle-1.png stand-0.png jump-0.png skid-0.png"
build_pack $temp/2.png "gameover-0.png gameover-1.png" 
build_pack $temp/3.png "grow-0.png grow-1.png grow-2.png grow-3.png grow-4.png grow-5.png grow-6.png"
convert -size 637x128 canvas:none \
        -draw "image over 0,0,0,0 '$temp/1.png'" \
        -draw "image over 448,48,0,0 '$temp/2.png'" \
        -draw "image over 0,48,0,0 '$temp/3.png'" \
        -draw "image over 562,48,0,0 'kick-0.png'" \
        $temp/4.png
        
resize $temp/4.png 16 small.png

#        -remap $palette \)
exit

#==================================================[ create pack for big tux ]==================================================
set_path creatures/tux/big

build_pack $temp/1.png "walk-0.png walk-1.png walk-2.png walk-3.png walk-4.png walk-5.png idle-0.png idle-1.png kick-0.png stand-0.png"
build_pack $temp/2.png "jump-0.png skid-0.png duck-0.png backflip-0.png backflip-1.png backflip-2.png backflip-3.png backflip-4.png buttjump-0.png" 
convert -size 320x80 canvas:magenta \
        -draw "image over 0,0,0,0 '$temp/1.png'" \
        -draw "image over 0,40,0,0 '$temp/2.png'" \
        $temp/4.png
recolor $temp/4.png 16 big.png        
        
#==================================================[ create pack for fire tux ]==================================================
set_path creatures/tux/fire

build_pack $temp/1.png "walk-0.png walk-1.png walk-2.png walk-3.png walk-4.png walk-5.png idle-0.png idle-1.png kick-0.png stand-0.png"
build_pack $temp/2.png "jump-0.png skid-0.png duck-0.png backflip-0.png backflip-1.png backflip-2.png backflip-3.png backflip-4.png buttjump-0.png" 
convert -size 320x80 canvas:magenta \
        -draw "image over 0,0,0,0 '$temp/1.png'" \
        -draw "image over 0,40,0,0 '$temp/2.png'" \
        $temp/4.png
recolor $temp/4.png 16 fire.png        

#==================================================[ create pack for ice tux ]==================================================
set_path creatures/tux/ice

build_pack $temp/1.png "walk-0.png walk-1.png walk-2.png walk-3.png walk-4.png walk-5.png idle-0.png idle-1.png kick-0.png stand-0.png"
build_pack $temp/2.png "jump-0.png skid-0.png duck-0.png backflip-0.png backflip-1.png backflip-2.png backflip-3.png backflip-4.png buttjump-0.png" 
convert -size 320x80 canvas:magenta \
        -draw "image over 0,0,0,0 '$temp/1.png'" \
        -draw "image over 0,40,0,0 '$temp/2.png'" \
        $temp/4.png
recolor $temp/4.png 16 ice.png        

#==================================================[ create pack for snow tile ]==================================================
set_path tiles/snow

build_pack $temp/1.png "convex.png"
convert -size 320x80 canvas:magenta \
        -draw "image over 0,0,0,0 '$temp/1.png'" \
        $temp/4.png
recolor $temp/4.png 8 convex.png        








#cleanup temporary images
rm $temp/1.png
rm $temp/2.png
rm $temp/3.png
rm $temp/4.png
