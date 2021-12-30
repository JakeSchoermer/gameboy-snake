#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>
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
    
    // Spawn Cherry Sprites - Occupy sprite addresses 1 to 5 (inclusive);
    set_sprite_data(1, 1, cherry_sprite);

    initrand(1);

    for (int i = 0; i < 5; i++) {

        // rand function generates between -127 and 128, so we need to add
        // 127 and divide by 2 to ensure a positive number
        INT8 x = (rand() + 127) / 2;
        INT8 y = (rand() + 127) / 2;

        // Convert to x or y coord and divide by sprite width/height
        x = (x * 144 / 128) / 8;
        y = (y * 160 / 128) / 8;

        set_sprite_tile(i + 1, 1); 
        move_sprite(i + 1 , X_OFFSET + x * 8, Y_OFFSET + y * 8);
    }


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