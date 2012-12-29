#include <stdlib.h>
#include <stdio.h>

#include "misc/hw_md.h"
#include "drivers/vdp/vdp.h"

#include "supertux/tiles.c"
#include "main_clean.c"



void supertux_init();
void supertux_mainloop();

int main(void)
{
  supertux_init();

  supertux_mainloop();

  return 0;
}


