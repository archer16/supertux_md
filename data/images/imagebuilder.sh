#!/bin/bash
source=$(cat ../supertux_source.txt)
target=$(pwd)
#palette=$target/../genisis.palette.png
temp=/tmp
genpal=$target/../tools/genesis_palette.php

source $target/inc.imagebuilder.sh

#import tux sprites
source $target/inc_import_tux_small.sh
source $target/inc_import_tux_big.sh
source $target/inc_import_tux_fire.sh
source $target/inc_import_tux_ice.sh

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
