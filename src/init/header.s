| SEGA MegaDrive support code
| by Chilly Willy
| modified by Archer

| Standard MegaDrive ROM header at 0x100

        .ascii  "SEGA            "      /* SEGA must be the first four chars for TMSS */
        .ascii  "(C)2011         "
        .ascii  "Supertux MD     "      /* export name */
        .ascii  "                "
        .ascii  "                "
        .ascii  "Supertux MD     "      /* domestic (Japanese) name */
        .ascii  "                "
        .ascii  "                "
        .ascii  "GM MK-0000 -00"
        .word   0x0000                  /* checksum - not needed */
        .ascii  "J6              "
        .long   0x00000000,0x0007FFFF   /* ROM start, end */
        .long   0x00FF0000,0x00FFFFFF   /* RAM start, end */

        .ifdef  HAS_SAVE_RAM
        .ascii  "RA"                    /* External RAM */
        .byte   0xF8                    /* don't clear + odd bytes */
        .byte   0x20                    /* SRAM */
        .long   0x00200001,0x0020FFFF   /* SRAM start, end */
        .else
        .ascii  "            "          /* no SRAM */
        .endif

        .ascii  "    "
        .ascii  "        "

        .ifdef  MYTH_HOMEBREW
        .ascii  "MYTH3900"              /* memo indicates Myth native executable */
        .else
        .ascii  "        "              /* memo */
        .endif

        .ascii  "                "
        .ascii  "                "
        .ascii  "F               "      /* enable any hardware configuration */
