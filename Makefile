CC     = m68k-elf-gcc
AS     = m68k-elf-as
OBJC   = m68k-elf-objcopy
RM     = rm -f
ASMZ80 = zasm
BINTOC = bin2c

#-save-temps
OPTION    =
INCS      = -I. -I$(GENDEV)/m68k-elf/include -I$(GENDEV)/m68k-elf/m68k-elf/include
CCFLAGS   = $(OPTION) -m68000 -Wall -O2 -c -fomit-frame-pointer
HWCCFLAGS = $(OPTION) -m68000 -Wall -O1 -c -fomit-frame-pointer
Z80FLAGS  = -vb2
ASFLAGS   = -m68000 --register-prefix-optional
LIBS      = -L$(GENDEV)/m68k-elf/lib -L$(GENDEV)/m68k-elf/m68k-elf/lib -lc -lgcc -lnosys
LINKFLAGS = -T $(GENDEV)/ldscripts/md.ld -Wl,-Map=output.map -nostdlib
TMPFOLDER = /tmp


ASC  = $(AS) $(ASFLAGS)
CCC = $(CC) $(CCFLAGS) $(INCLUDE) -c

#init.o hw_md.o main.o fonts.0 sprites.o
OBJS = ./obj/init.o ./obj/hw_md.o ./obj/vdp.o ./obj/main.o ./obj/fonts.o ./obj/sprites.o


all: supertux_md.bin

# Extract binary from ELF and rename to final .BIN
supertux_md.bin: ./obj/supertux_md.elf
	$(OBJC) -O binary $< $(TMPFOLDER)/temp.bin
	dd if=$(TMPFOLDER)/temp.bin of=$@ bs=2K conv=sync
	$(RM) *.i $(TMPFOLDER)/temp.bin output.map

# Link all object files into ELF
./obj/supertux_md.elf: $(OBJS)
	$(CC) $(LINKFLAGS) $(OBJS) $(LIBS) -o ./obj/supertux_md.elf

# MegaDrive header and startup code
./obj/init.o: ./src/init/init.s
	$(ASC) -I ./src/init ./src/init/init.s -o ./obj/init.o

# Hardware interface functions, copied from Chilly Willy TicTacToe
./obj/hw_md.o: ./src/misc/hw_md.s
	$(ASC) -I ./src/misc ./src/misc/hw_md.s -o ./obj/hw_md.o

# Hardware drivers
./obj/vdp.o: ./src/drivers/vdp/vdp.s
	$(ASC) -I ./src/drivers/vdp ./src/drivers/vdp/vdp.s -o ./obj/vdp.o


# Main program entry
./obj/main.o: ./src/main.c ./src/main_clean.c ./src/supertux/tiles.c
	$(CCC) ./src/main.c -o ./obj/main.o

# Fonts
./obj/fonts.o: ./data/fonts/font.c
	$(CCC) ./data/fonts/font.c -o ./obj/fonts.o

# Sprites
./obj/sprites.o: ./data/sprites/sprites.c
	$(CCC) ./data/sprites/sprites.c -o ./obj/sprites.o

# cleanup all temorary files
clean:
	$(RM) ./obj/*.o *.bin *.map *.i ./obj/*.elf



#%.o80: %.s80
#	$(ASMZ80) $(Z80FLAGS) -o $@ $<
#
#%.c: %.o80
#	$(BINTOC) $<
#
#%.o: %.c
#	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@
#
#%.o: %.s
#	$(AS) $(ASFLAGS) $< -o $@
