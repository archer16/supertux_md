#!/bin/bash
source=$(cat ../supertux_source.txt)
target=$(pwd)
#palette=$target/../genisis.palette.png
temp=/tmp
genpal=$target/../tools/genesis_palette.php

source ./inc.imagebuilder.sh

#==================================================[ create pack for small tux ]==================================================
  set_path creatures/tux/small
  palette=$target/creatures/tux/_palette.png
  import_colors=24
  
  tux_small=(
    "gameover-0.png" "gameover-1.png" "grow-0.png" "grow-1.png" "grow-2.png" "grow-3.png" "grow-4.png" "grow-5.png" "grow-6.png" "walk-0.png" "walk-1.png" 
    "walk-2.png" "walk-3.png" "walk-4.png" "walk-5.png" "walk-6.png" "walk-7.png" "idle-0.png" "idle-1.png" "jump-0.png" "kick-0.png" "skid-0.png" "stand-0.png"
  )
  import_loop "${tux_small[@]}"

  #change to image folder
  cd $target/$image_path

  echo "  * Building image pack"
  build_pack _small_pack.png "$line"

  create_palette _small_pack.png _small_palette.png

#Create demo animations
#  animate gameover 10
#  animate grow 6
#  animate walk 6

echo "------------------------------------------------------------"
exit 
#==================================================[ create pack for big tux ]==================================================
  set_path creatures/tux/big
  palette=$target/creatures/tux/_palette.png
  import_colors=24

  tux_big=(
    "walk-0.png" "walk-1.png" "walk-2.png" "walk-3.png" "walk-4.png" "walk-5.png" "idle-0.png" "idle-1.png" "kick-0.png" "stand-0.png"
    "jump-0.png" "skid-0.png" "duck-0.png" "backflip-0.png" "backflip-1.png" "backflip-2.png" "backflip-3.png" "backflip-4.png" "buttjump-0.png"
  )
  import_loop "${tux_big[@]}"

  #change to image folder
  cd $target/$image_path

  echo "  * Building image pack"
  build_pack _big_pack.png "$line"

  create_palette _big_pack.png _big_palette.png

#Create demo animations
#  animate backflip 11
#  animate walk 6
        
echo "------------------------------------------------------------"
#==================================================[ create pack for fire tux ]==================================================
  set_path creatures/tux/fire
  palette=$target/creatures/tux/_palette.png
  import_colors=32

  tux_fire=(
    "walk-0.png" "walk-1.png" "walk-2.png" "walk-3.png" "walk-4.png" "walk-5.png" "idle-0.png" "idle-1.png" "kick-0.png" "stand-0.png"
    "jump-0.png" "skid-0.png" "duck-0.png" "backflip-0.png" "backflip-1.png" "backflip-2.png" "backflip-3.png" "backflip-4.png" "buttjump-0.png"
  )
  import_loop "${tux_fire[@]}"

  #change to image folder
  cd $target/$image_path

  echo "  * Building image pack"
  build_pack _fire_pack.png "$line"

  create_palette _fire_pack.png _fire_palette.png

#Create demo animations
#  animate backflip 11
#  animate walk 6
  
echo "------------------------------------------------------------"
#==================================================[ create pack for ice tux ]==================================================
  set_path creatures/tux/ice

  tux_ice=(
    "walk-0.png" "walk-1.png" "walk-2.png" "walk-3.png" "walk-4.png" "walk-5.png" "idle-0.png" "idle-1.png" "kick-0.png" "stand-0.png"
    "jump-0.png" "skid-0.png" "duck-0.png" "backflip-0.png" "backflip-1.png" "backflip-2.png" "backflip-3.png" "backflip-4.png" "buttjump-0.png"
  )
  import_loop "${tux_ice[@]}"

  #change to image folder
  cd $target/$image_path

  echo "  * Building image pack"
  build_pack _ice_pack.png "$line"

  create_palette _ice_pack.png _ice_palette.png

#Create demo animations
#  animate backflip 11
#  animate walk 6

echo "------------------------------------------------------------"
#==================================================[ create pack for snow tile ]==================================================
  set_path tiles/snow
  
  build_pack $temp/1.png "convex.png"
  convert -size 352x128 canvas:none \
          -draw "image over 0,0,0,0 '$temp/1.png'" \
          $temp/4.png
  resize $temp/4.png 32 convex.png        

  #change to image folder
  cd $target/$image_path
  
  create_palette convex.png _snow_palette.png
  
  convert convex.png -crop 48x64+0+0 convex_1.png
  convert convex.png -crop 64x64+48+0 convex_2.png
  convert convex.png -crop 64x64+112+0 convex_3.png
  
  

#==================================================[ cleanup temporary images ]==================================================
rm -f $temp/1.png
rm -f $temp/2.png
rm -f $temp/3.png
rm -f $temp/4.png
