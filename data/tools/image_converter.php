<?php
  $tux_source = file_get_contents('../supertux_source.txt');
  $images     = $tux_source.'/images';

  // Load tux sprite data
  $tux = new tux_sprite_reader($images.'/creatures/tux/tux.sprite');

  class tux_sprite_reader
  {
    var $data;
    
    function tux_sprite_reader($filename)
    {
      
      $this->data = file_get_contents($filename);
      print_r($this->tokenize($this->data));
    }
    
    
    //Code from https://igor.io/2012/12/07/sexpr-lexer.html
    private $whitespace = array(' ', "\t", "\r", "\n");
    private $nonAtom = array('(', ')', ' ', "\t", "\r", "\n");

    public function tokenize($code)
    {
        //$tokens = [];

        for ($i = 0, $length = strlen($code); $i < $length; $i++) {
            $char = $code[$i];

            // kill whitespace
            if (in_array($char, $this->whitespace)) {
                continue;
            }

            // parens are single tokens
            if (in_array($char, array('(', ')'))) {
                $tokens[] = $char;
                continue;
            }

            // quote token (just the quote character)
            if ("'" === $char) {
                $tokens[] = $char;
                continue;
            }

            // atom token
            $atom = '';
            $next = $char;
            do {
                $atom .= $next;
                $next = ($length > $i+1) ? $code[$i+1] : null;
            } while (null !== $next && !in_array($next, $this->nonAtom) && ++$i);
            $tokens[] = $atom;
        }

        return $tokens;

    }
    


  }
  
  
  function verify($path,$exclude='')
  {
    $parts = explode("/",$path);
    $part_count = count($parts);
     
    for($part_loop = 1;$part_loop < $part_count;$part_loop++)
    {
      $test_path = $test_path.'/'.$parts[$part_loop];
      if(!is_dir($test_path)) {mkdir($test_path, 0777);}
    }
     
    return $path;
  }

?>
