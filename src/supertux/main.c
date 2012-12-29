//includes come from "../main.c"

#define PLAYER_IDLE 13
#define PLAYER_JUMP 14
#define PLAYER_SKID 15

#define MOVE_LEFT    1
#define MOVE_RIGHT   2


//void player_animate();

float player_x;
float player_y;
char  player_jump;
char  player_jump_lock;
float player_jump_velocity_x;
float player_jump_velocity_y;
char  player_walk;
char  player_direction;
short player_sprite;


float map_gravity = 0.5;
float run_speed   = 0.5;

void player_update(char move_left,char move_right,char jump,char falling)
{
  
  
}

void player_reset()
{
  player_sprite = PLAYER_IDLE;

  player_x = VDP_X + (16 * 1);
  player_y = VDP_Y + (16 * 5);
  player_jump_lock = 0;
  player_jump = 0;
  player_jump_velocity_x = 0;
  player_jump_velocity_y = 0;
}


void supertux_init()
{
  //draw the playfield
  char loop_x,loop_y;
   
  for(loop_x = 0;loop_x < 20;loop_x++)
  {
    for(loop_y = 0;loop_y < 28;loop_y++)
    {
      supertux_bg_tile_set(loop_x,loop_y,level_data[(loop_y * 20)+loop_x],CP_1);
    }
  }
}

void supertux_mainloop()
{
  int buttons;
  //unsigned int sp_x = 0;
  //unsigned int sp_y = 0;

  char jump = 0;
  char falling = 0;
  short flip = 0;
  
  player_reset();

  jump = 0;
  char walk = 0;
  float speed = 0;
  
  map_gravity = 0.19;
  run_speed   = 0.19;

  while(1)
  {
    buttons = get_pad(0);
    
    
    //reset defaults for this loop
    player_sprite = PLAYER_IDLE;
    falling       = 0;
    jump          = 0;
    walk          = 0;


    //Read buttons and set action variables
    if(buttons & SEGA_CTRL_LEFT)  {speed += run_speed;walk = 1;flip = HF;player_direction = MOVE_LEFT;}
    if(buttons & SEGA_CTRL_RIGHT) {speed += run_speed;walk = 1;flip = 0 ;player_direction = MOVE_RIGHT;}

    if(buttons & SEGA_CTRL_A) {jump=1;}

//----------------------------------------------------------------------------------------------------------------------
//  React to buttons
//----------------------------------------------------------------------------------------------------------------------

    //check for collision on the left or right with the level map
    //if(player_direction == MOVE_RIGHT && (map_solid_left(player_x+20,player_y + 16) & 8)) {walk = 0;}
    //if(player_direction == MOVE_LEFT  && (map_solid_left(player_x+5 ,player_y + 16) & 4)) {walk = 0;}

    if(speed > 0)
    {
      if(speed > 2) {speed = 2;}
      if((walk != 1) && (jump == 0)) {speed -=0.1;}

      if(player_direction == MOVE_LEFT)  {player_x -= speed;}
      if(player_direction == MOVE_RIGHT) {player_x += speed;}
      player_sprite = PLAYER_IDLE;
    }


    //jump and gravity
    if((player_jump_lock == 0) && !(map_solid_top(player_x+10,player_y + 24) & 1))
    {
      falling = 1;
      player_sprite = PLAYER_JUMP;
    } else if (map_solid_top(player_x+10,player_y + 24) & 1) {
      falling = 0;
      player_jump_velocity_y = 0;
    }
    if (falling == 1)
    {
      player_jump_velocity_y += map_gravity;
      player_y += player_jump_velocity_y;
      if(player_jump_velocity_y > 4) {player_jump_velocity_y = 4;}
      jump = 0;
    }
    if ((jump == 1) && (player_jump_lock == 0))
    {
      player_jump            = 1;
      player_jump_lock       = 1;
      player_jump_velocity_y = 5;
      player_jump_velocity_x = speed;
    }
    if(player_jump == 1)
    {
      player_sprite = PLAYER_JUMP;
      player_y -= player_jump_velocity_y;
      player_jump_velocity_y -= map_gravity;
      if(player_jump_velocity_y < 0)
      {
        player_jump_velocity_y = 0;
        player_jump_lock = 0;
        player_jump = 0;
      }
    }
    

     
//----------------------------------------------------------------------------------------------------------------------
    if(buttons & SEGA_CTRL_C) {player_reset();}
//----------------------------------------------------------------------------------------------------------------------
     
    //keep player on the screen and reset if falling of. Replace later with level map code.
        if(player_x < (VDP_X - 9)) {player_x = VDP_X + ((16*20) - 5);}
        if(player_x > (VDP_X + ((16*20)+5))) {player_x = VDP_X - 5;}
        if(player_y < 100) {player_y = 100;}
        if(player_y > (VDP_Y + (16 * 14))) {player_reset();}
    //-------------------------------------------------------------------------------------
     
    //Draw player sprite and  
    set_sprite_attr(0,player_x,player_y,0xA00 + 1,flip | tiles[player_sprite] | CP_3);
    set_sprite_attr(1,VDP_X+(16 * 1),VDP_Y +(16 * 5),0x500 + 2,(tiles[0] - (4 * 8)) | CP_2);

    //Used to visualize the collision border on the player
    set_sprite_attr(2,player_x,player_y,0x000 + 3,(tiles[0] - (4 * 8)) | CP_0);
    set_sprite_attr(3,player_x+16,player_y,0x000 + 0, (tiles[0] - ((4 * 8)) + 2) | CP_0);
     
     
    delay(1);
  }
}




