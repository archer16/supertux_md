|-----------------------------------------------------------------------------------------------------------------------
| VDP data
|-----------------------------------------------------------------------------------------------------------------------

    .align 2
    .global vdp_default_cp0
vdp_default_cp0:
        .word 0x0E0E
        .word 0x0CCC
        .word 0x000E
        .word 0x00E0
        .word 0x0E00
        .word 0x00EE
        .word 0x0EE0
        .word 0x0000
        .word 0x0EEE
        .word 0x0666
        .word 0x0006
        .word 0x0060
        .word 0x0600
        .word 0x0066
        .word 0x0660
        .word 0x0606


|-----------------------------------------------------------------------------------------------------------------------
| VDP C library
|-----------------------------------------------------------------------------------------------------------------------


|===============================================================================
|  void set_sprite(int sprite_x, int sprite_y,int hsvsld,int misc0, int misc1)
|===============================================================================
    .align 2
    .global vdp_set_sprite
vdp_set_sprite:
    lea     0xC00000,a0         /* setup a0,a1 to pint to VDP ports */
    lea     0xC00004,a1
    
    move.l  20(sp),d0           /* Get Address from stack, and convert to VDP command */
    move.w  #0x2800,d1
    add.w d0,d1
    or.w #0x4000,d1
    |bset #14,d1
    move.w d1, (a1)            /* Write VDP Command */
    move.w #0x0002, (a1)
    
    move.l  8(sp),d0           /* get sprite_x from stack and write to VDP */
    move.w  d0,(a0)
    
    move.l  12(sp),d0          |get hsvsld from stack and write to VDP
    move.w  d0,(a0)
    
    move.l  16(sp),d0          |get misc0 from stack
    move.w  d0,(a0)
    
    move.l  4(sp),d0           |get sprite_y from stack and write to VDP
    move.w  d0,(a0)
    rts

|===============================================================================
|  void vdp_register_write(int address,char value)
|===============================================================================
    .align 2
    .global vdp_register_write
vdp_register_write:
    lea     0xC00000,a0         /* setup a0,a1 to pint to VDP ports */
    lea     0xC00004,a1
    
    move.l  20(sp),d0           /* Get Address from stack, and convert to VDP command */
    move.w  #0x2800,d1
    add.w d0,d1
    or.w #0x4000,d1
    |bset #14,d1
    move.w d1, (a1)            /* Write VDP Command */
    move.w #0x0002, (a1)
 
    move.l  8(sp),d0           /* get sprite_x from stack and write to VDP */
    move.w  d0,(a0)


    rts

