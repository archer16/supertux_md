#define VDP_X  (112 + 16)
#define VDP_Y  (112 + 16)

#define u8      unsigned char
#define u16     unsigned short
#define u32     unsigned long

#define vu8     volatile u8
#define vu16    volatile u16
#define vu32    volatile u32
void jump_start(unsigned  int *y);
unsigned int jump_animate(unsigned  int *y);


u8 global_volume = 15;

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
