#!/bin/bash
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
