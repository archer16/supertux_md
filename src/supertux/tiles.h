
void load_level(char *level_data, char level_height)
{
  
}


void supertux_bg_tile_set(int x,int y, char tile_id,short color_palette)
{
  put_str("\xA0\xA2",color_palette,(x*2),y);
  put_str("\xA1\xA3",color_palette,(x*2),y+1);
}
