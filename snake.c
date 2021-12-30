#include <gb/gb.h>
#include <stdio.h>
#include "brick.c"
#include "border_map.c"
#include "blankscreen.c"
#include "character_sprite.c"

UINT8 CHARACTER_SPRITE_ADDR = 0;

void init() {

    DISPLAY_ON;

    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;

    // Need to load bricksprite, used in border_map
    set_bkg_data(0, 1, brick);

    //Center Sprite Map on Screen
    set_bkg_tiles(0, 64, 20, 18, border_map);

    // Load the the character sprite tile into memory
	set_sprite_data(0, 1, character_sprite);

    //Put character sprite on map
    set_sprite_tile(0, 0);

    move_sprite(0, 75, 75);

    return;
}

void checkInput() {

    if (joypad() & J_A) {
        set_bkg_tiles(0,0,20,18,blankScreen);
    }

    else if (joypad() & J_UP) {
    
    }

    else if (joypad() & J_DOWN) {
    
    }

    else if (joypad() & J_LEFT) {
    
    }

    else if (joypad() & J_RIGHT) {
    
    }

}


void main(){
    init();

    while(1) {
        checkInput();
    }

}