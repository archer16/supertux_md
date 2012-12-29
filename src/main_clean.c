#define VDP_X  112
#define VDP_Y  112

#define u8      unsigned char
#define u16     unsigned short
#define u32     unsigned long

#define vu8     volatile u8
#define vu16    volatile u16
#define vu32    volatile u32
void jump_start(unsigned  int *y);
unsigned int jump_animate(unsigned  int *y);


u8 global_volume = 15;
unsigned int jump_base = 0;
unsigned int jump_max = 0;
unsigned int jump_loop = 0;
unsigned int jump_up_down = 0;

void sound_test(u8 channel,u8 value,u8 volume)
{
  //vu8 *psg;
  
  //psg = (u8 *) 0xC00000 + 0x0011;;
  
  //*psg = 0x90 | ((channel & 3) << 5) | (volume & 0xF);
  //*psg = 0x80 | ((channel & 3) << 5) | (value & 0xF);
  //*psg = (value >> 4) & 0x3F;
}

void set_sprite_attr(char sprite_index,int x, int y,short size_link, int misc1)
{
  //  word_1 = x
  //  word_2 = size + sprite link
  int word_3 = misc1;
  //  word_4 = y
  
  int addr = sprite_index * 8;
  
  vdp_set_sprite(x,y,size_link,word_3,addr);
}



/*
enum Sprite_Direction
{
  SPRITE_DIRECTION_LEFT = 1,
  SPRITE_DIRECTION_RIGHT = 2
}

struct PlayerInformation
{
  int level_x;
  int level_y;
  
  int jumping;
  int animation_counter;
  
  //Sprite_Direction direction;
  
} player_sprite;
*/

char center(char length)
{
  return (39 - length) / 2;
}

void debug_buttons(int buttons,char *background)
{
    if(buttons & SEGA_CTRL_UP)    {put_str("U",0,3,1);}   else {put_str(background,0,3,1);}
    if(buttons & SEGA_CTRL_DOWN)  {put_str("D",0,3,3);}   else {put_str(background,0,3,3);}
    if(buttons & SEGA_CTRL_LEFT)  {put_str("L",0,2,2);}   else {put_str(background,0,2,2);}
    if(buttons & SEGA_CTRL_RIGHT) {put_str("R",0,4,2);}   else {put_str(background,0,4,2);}
     
    if(buttons & SEGA_CTRL_A)     {put_str("A",0, 10,3);} else {put_str(background,0,10,3);}
    if(buttons & SEGA_CTRL_B)     {put_str("B",0, 11,2);} else {put_str(background,0,11,2);}
    if(buttons & SEGA_CTRL_C)     {put_str("C",0, 12,1);} else {put_str(background,0,12,1);}
    if(buttons & SEGA_CTRL_X)     {put_str("X",0,  8,3);} else {put_str(background,0,8,3);}
    if(buttons & SEGA_CTRL_Y)     {put_str("Y",0,  9,2);} else {put_str(background,0,9,2);}
    if(buttons & SEGA_CTRL_Z)     {put_str("Z",0, 10,1);} else {put_str(background,0,10,1);}
     
    if(buttons & SEGA_CTRL_START) {put_str("S",0,  6,1);} else {put_str(background,0,6,1);}
    if(buttons & SEGA_CTRL_MODE)  {put_str("M",0,  6,3);} else {put_str(background,0,6,3);}
}


void supertux_init()
{
  char loop_x,loop_y;

  for(loop_x = 0;loop_x < 20;loop_x++)
  {
    for(loop_y = 0;loop_y < 14;loop_y++)
    {
      supertux_bg_tile_set(loop_x,loop_y,1,CP_2);
    }
  }

  //supertux_bg_tile_set(0,0,0,CP_2);
  //supertux_bg_tile_set(1,0,1,CP_2);
  //supertux_bg_tile_set(2,0,2,CP_2);


  
  put_str("\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xAC",CP_3,0,19);
  put_str("\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xAA",CP_3,0,20);
  
  for(loop_x = 0;loop_x < 11;loop_x++)
  {
    for(loop_y = 10;loop_y < 14;loop_y++)
    {
      supertux_bg_tile_set(loop_x,loop_y,2,CP_1);
    }
  }
  
  for(loop_x = 15;loop_x < 20;loop_x++)
  {
    for(loop_y = 10;loop_y < 14;loop_y++)
    {
      supertux_bg_tile_set(loop_x,loop_y,2,CP_1);
    }
  }
  
  

  put_str("\xAA\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8\xA8",CP_3,30,19);

}

void supertux_mainloop()
{
    int buttons;
  unsigned int sp_x = 0;
  unsigned int sp_y = 0;

  char jump = 0;
  short flip = 0;
  short flip_m = 0;
  
  short anim_x[12];
  //short anim_y[12];
  
  //vdp_register_write(
  
  for(sp_x = 0;sp_x < 12;sp_x++)
  {
    anim_x[sp_x] = VDP_X + 112;
  }
  
   
  sp_x = VDP_X + (8 * 8);
  sp_y = VDP_Y + (8 * 19);





  jump = 0;
  char speed = 4;
  char walk_loop = 0;
  char last_jump = 0;
  while(1)
  {
    
    buttons = get_pad(0);

    //if(buttons & SEGA_CTRL_UP)    {sp_y-=3;flip_m = HF;}
    //if(buttons & SEGA_CTRL_DOWN)  {sp_y+=3;flip_m = 0;}
    if(buttons & SEGA_CTRL_LEFT)  {walk_loop=8;speed = -2;flip = HF;}
    if(buttons & SEGA_CTRL_RIGHT) {walk_loop=8;speed = 2;flip = 0;}
    
    if(walk_loop > 0)
    {
      //if(jump > 0) {if(speed > 0) {speed = 2;} else{speed = -2;}}
      sp_x += speed;
      walk_loop--;
    } else if(jump > 0) {
      if(speed > 0) {sp_x++;} else{sp_x--;}
    }
    
    if((buttons & SEGA_CTRL_A) && (jump == 0) && (last_jump==0))
    {
      jump_start(&sp_y);
      jump=9;
      last_jump=1;
      flip_m=1;
    }
    if(((buttons & SEGA_CTRL_A) == 0)) {last_jump=0;}
    
    if(jump > 0)
    {
        if(sp_y == jump_max) {jump_up_down=2;}
        if(sp_y > (jump_max + 24))
        {  
          if (jump_up_down == 1) {sp_y-=4;}
          if (jump_up_down == 2) {sp_y+=4;}
        } else if(sp_y > (jump_max + 8)){
          if (jump_up_down == 1) {sp_y-=2;}
          if (jump_up_down == 2) {sp_y+=2;}
        } else {
          if (jump_up_down == 1) {sp_y-=1;}
          if (jump_up_down == 2) {sp_y+=1;}
        }
        
        if(sp_y < jump_max) {sp_y=jump_max;}
        if(sp_y > jump_base) {sp_y = jump_base;jump=0;}
    }

    if(sp_x > 448) {sp_x = 100;}
    if(sp_x < 100) {sp_x = 448;}
    if(sp_y > 448) {sp_y = 100;}
    if(sp_y < 100) {sp_y = 448;}
    
    set_sprite_attr(0,sp_x,sp_y,0xA00 + 0,flip | (0x009A + jump) | CP_3);
     
    delay(1);
  }
  
  
  
}

void jump_start(unsigned int *y)
{
  jump_base = *y;
  jump_max  = *y - (4 * 16) - 8;
  jump_loop = 0;
  jump_up_down = 1; //1 = up, 2 = down, 0 = none
  
}

unsigned int jump_animate(unsigned int *y)
{
  jump_loop--;
  y-=1;
  
  /*
  if(*y == jump_max) {y++;jump_up_down=2;}
  if(*y > jump_max)
  {  
    if (jump_up_down == 1) {y-=1;}
    if (jump_up_down == 2) {y+=1;}
  }
  if(*y < jump_max) {*y=jump_max;}
  */
  return jump_loop;
}

