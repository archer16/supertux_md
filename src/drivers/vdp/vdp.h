#ifndef _VDP_H
#define _VDp_H

//Sprite attributes
#define HS_1   0x0000
#define HS_2   0x0400
#define HS_3   0x0800
#define HS_4   0x0C00
#define VS_1   0x0000
#define VS_2   0x0100
#define VS_3   0x0200
#define VS_4   0x0300

#define PRI    0x8000
#define CP_0   0x0000
#define CP_1   0x2000
#define CP_2   0x4000
#define CP_3   0x6000
#define VF     0x1000
#define HF     0x0800

void vdp_set_sprite(int x,int y,int hsvsld,int misc0,int sprite_index);
void vdp_register_write(int address,char value);


#endif
