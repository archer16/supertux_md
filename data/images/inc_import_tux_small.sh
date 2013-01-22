#!/bin/bash
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
