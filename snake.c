#include <gb/gb.h>
#include <stdio.h>


unsigned char Brick[] =
{
  0xFF,0xFF,0x81,0xFF,0xBD,0xFF,0xBD,0xE7,
  0xBD,0xE7,0xBD,0xFF,0x81,0xFF,0xFF,0xFF
};

void draw_border() {

    SPRITES_8x8;    
    
    // set_sprite_data(0, 8, Brick);
    // set_sprite_tile(0, 0);
    // move_sprite(0, 8, 16);

    // set_sprite_data(1, 8, Brick);
    // set_sprite_tile(1, 0);
    // move_sprite(1, 16, 16);


    for (int i = 0; i <4; i++){
        set_sprite_data(i, 8, Brick);
        set_sprite_tile(i, 0);
        move_sprite(i, (i+1)*8, 16);
    }

    SHOW_SPRITES;

    return;
}

void checkInput() {

    if (joypad() & J_A) {
		printf("A");
        delay(100);
    }

}

void main(){
    draw_border();

    while(1) {
        checkInput();	
    }

    // printf("Hello World");
}