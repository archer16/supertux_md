<?php
  $lines = explode("\n",file_get_contents('php://stdin'));
  //print_r( $lines);
  echo $lines[0]."\n";

  $vdp_level[0] = 0;
  $vdp_level[1] = 36;
  $vdp_level[2] = 73;
  $vdp_level[3] = 108;
  $vdp_level[4] = 144;
  $vdp_level[5] = 180;
  $vdp_level[6] = 216;
  $vdp_level[7] = 252;
  $vdp_level[8] = 255;
  
  build_vdp_list();
  
  for($x=1;$x<count($lines);$x++)
  {
    if(!$lines[$x]=='')
    {
      $base    = strpos($lines[$x],'(');
      $comment = strpos($lines[$x],'#') -2;
      $pixel   = substr($lines[$x],0,$comment);
      
      $rgba = explode(',',substr($pixel,$base+1,$comment - $base - 2));
      $rgba[0] = find_vdp_color($rgba[0]);
      $rgba[1] = find_vdp_color($rgba[1]);
      $rgba[2] = find_vdp_color($rgba[2]);
      echo substr_replace($pixel,join(',',$rgba),$base+1,15)."\n";
    }
  }

  function find_vdp_color($value)
  {
    global $vdp_levels;
    
    return substr('   '.$vdp_levels[trim($value)],-3,3);
  }

  function build_vdp_list()
  {
    global $vdp_level;
    global $vdp_levels;
    
    for($x=0;$x<256;$x++)
    {
      $vdp_levels[$x] = $vdp_level[round((8.0 / 255) * $x,PHP_ROUND_HALF_UP)];
    }
  }
?>
