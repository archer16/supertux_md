
void load_level(char *level_data, char level_height)
{
  
}

const unsigned char level_data[] =
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  1,  2,  3,  0,  0,  1,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  4,  5,  6,  0,  0,  4,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  7,  8,  9,  0,  0, 10, 12,  0,  0,  1,  3,  0,  0,  0,  0,  0,  0,  0,
    0,  0, 10, 11, 12,  0,  0,  0,  0,  0,  0,  4,  6,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 12,  0,  0,  1,  3,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  6,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 12,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  0,  0,  0,  0,  1,  2,  2,  2,  2,  3,
    4,  5,  5,  5,  5,  5,  5,  5,  5,  6,  0,  0,  0,  0,  4,  5,  5,  5,  5,  6,
    7,  8,  8,  8,  8,  8,  8,  8,  8,  9,  0,  0,  0,  0,  7,  8,  8,  8,  8,  9,
    7,  8,  8,  8,  8,  8,  8,  8,  8,  9,  0,  0,  0,  0,  7,  8,  8,  8,  8,  9,
    7,  8,  8,  8,  8,  8,  8,  8,  8,  9,  0,  0,  0,  0,  7,  8,  8,  8,  8,  9
};

const unsigned char level_collision[] =
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  1,  1,  1,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  9,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,
};


//start_address = 0x0090
#define TILE_OFFSET   0x00A0
#define SPRITE_OFFET  0x0090
const unsigned short tiles[] =
{
  TILE_OFFSET,      //0  = cross-filler-background
  TILE_OFFSET + 4,  //1  = snow_01
  TILE_OFFSET + 8,  //2  = snow_02
  TILE_OFFSET + 12, //3  = snow_03
  TILE_OFFSET + 16, //4  = snow_04
  TILE_OFFSET + 20, //5  = snow_05
  TILE_OFFSET + 24, //6  = snow_06
  TILE_OFFSET + 28, //7  = snow_07
  TILE_OFFSET + 32, //8  = snow_08
  TILE_OFFSET + 36, //9  = snow_09
  TILE_OFFSET + 40, //10 = snow_10
  TILE_OFFSET + 44, //11 = snow_11
  TILE_OFFSET + 48, //12 = snow_12

  SPRITE_OFFET + 36, //13 = tux-small-idle-0
  SPRITE_OFFET + 36 + 9, //14 = tux-small-jump
  SPRITE_OFFET + 36 + 9 + 9  //15 = tux-small-skid
};

char map_solid_top(int x,int y)
{
  short col_x = (x - VDP_X) / 16;
  short col_y = (y - VDP_Y) / 16;
  
  if((col_x <= 19) && (col_y <= 13))
  {
    return level_collision[(col_y*20)+col_x];
  } else {
    return 0;
  }
}

char map_solid_left(int x,int y)
{
  short col_x = (x - VDP_X) / 16;
  short col_y = (y - VDP_Y) / 16;
  
  if((col_x <= 19) && (col_y <= 13))
  {
    return level_collision[(col_y*20)+col_x];
  } else {
    return 0;
  }
}

void supertux_bg_tile_set(int x,int y, short tile_id,short color_palette)
{
  put_chr(tiles[tile_id],color_palette,(x*2),(y*2));
  put_chr(tiles[tile_id]+1,color_palette,(x*2),(y*2)+1);
  put_chr(tiles[tile_id]+2,color_palette,(x*2)+1,(y*2));
  put_chr(tiles[tile_id]+3,color_palette,(x*2)+1,(y*2)+1);
}
