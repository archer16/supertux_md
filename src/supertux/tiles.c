
void load_level(char *level_data, char level_height)
{
  
}

const unsigned char tiles[] =
{
  0x0090,
  0x00A0,
  0x00A4
};





void supertux_bg_tile_set(int x,int y, short tile_id,short color_palette)
{
  put_chr(tiles[tile_id],color_palette,(x*2),(y*2));
  put_chr(tiles[tile_id]+1,color_palette,(x*2),(y*2)+1);
  put_chr(tiles[tile_id]+2,color_palette,(x*2)+1,(y*2));
  put_chr(tiles[tile_id]+3,color_palette,(x*2)+1,(y*2)+1);
}
