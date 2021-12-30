#include <gb/gb.h>
#include <stdio.h>
#include "brick.c"
#include "border_map.c"
#include "blankscreen.c"

void init() {

    DISPLAY_ON;

    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;

    // Need to load bricksprite, used in border_map
    set_bkg_data(0, 1, brick);

    //Center Sprite Map on Screen
    set_bkg_tiles(0, 64, 20, 18, border_map);

    return;
}

void checkInput() {

    if (joypad() & J_A) {
        set_bkg_tiles(0,0,20,18,blankScreen);
    }

}


void main(){
    init();

    while(1) {
        checkInput();
    }

}