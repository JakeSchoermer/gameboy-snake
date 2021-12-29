CC	= lcc -Wa-l -Wl-m -Wl-j -Wm-ys

BINS	= snake.gb

all:	$(BINS)

make.bat: Makefile
	@echo "REM Automatically generated from Makefile" > make.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> make.bat

# Compile and link single file in one pass
%.gb:	%.c
	$(CC) -o bin/$@ $<

clean:
	rm -f bin/*.o bin/*.lst bin/*.map bin/*.gb bin/*~ bin/*.rel bin/*.cdb bin/*.ihx bin/*.lnk bin/*.sym bin/*.asm bin/*.noi bin/*.sav

run:
	make && ./emulicious/Emulicious.jar bin/snake.gb -scale 8