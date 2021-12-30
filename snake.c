#include <gb/gb.h>
#include <stdio.h>
#include "snake.h"
#include "brick.c"
#include "border_map.c"
#include "blankscreen.c"
#include "character_sprite.c"
#include "cherry_sprite.c"

UINT8 CHARACTER_SPRITE_X_COORD = X_OFFSET + 8 * 8;
UINT8 CHARACTER_SPRITE_Y_COORD = Y_OFFSET + 8 * 7;

UINT8 CHARACTER_SPRITE_MIN_X = X_OFFSET;
UINT8 CHARACTER_SPRITE_MAX_X = X_OFFSET + 8 * 17;
UINT8 CHARACTER_SPRITE_MIN_Y = Y_OFFSET;
UINT8 CHARACTER_SPRITE_MAX_Y = Y_OFFSET + 8 * 15;

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

    move_sprite(0, CHARACTER_SPRITE_X_COORD, CHARACTER_SPRITE_Y_COORD);
    
    //Spawn Cherry Sprites
    set_sprite_data(1, 1, cherry_sprite);
    set_sprite_tile(1, 1); 
    move_sprite(1, X_OFFSET + 2 * 8, Y_OFFSET + 2 * 8);

    return;
}

void checkInput() {

    if (joypad() & J_A) {
        set_bkg_tiles(0,0,20,18,blankScreen);
    }

    else if (joypad() & J_UP
        && CHARACTER_SPRITE_Y_COORD > CHARACTER_SPRITE_MIN_Y) {
        CHARACTER_SPRITE_Y_COORD -= 8;
    }

    else if (joypad() & J_DOWN
        && CHARACTER_SPRITE_Y_COORD < CHARACTER_SPRITE_MAX_Y) {
        CHARACTER_SPRITE_Y_COORD += 8;
    }

    else if (joypad() & J_LEFT
        && CHARACTER_SPRITE_X_COORD > CHARACTER_SPRITE_MIN_X) {
        CHARACTER_SPRITE_X_COORD -= 8;
    }

    else if (joypad() & J_RIGHT
        && CHARACTER_SPRITE_X_COORD < CHARACTER_SPRITE_MAX_X) {
        CHARACTER_SPRITE_X_COORD += 8;
    }
    move_sprite(0, CHARACTER_SPRITE_X_COORD, CHARACTER_SPRITE_Y_COORD);
    delay(200);
}


void main(){
    init();

    while(1) {
        checkInput();
    }

}