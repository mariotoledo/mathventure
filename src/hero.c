#include <allegro5/allegro.h>
#include "headers/character.h"
#include "headers/hero.h"
#include "headers/config.h"

struct Character character;

void initHero(int x, int y) {
    character.sprite = al_load_bitmap("./assets/hero.png");
    character.x = x;
    character.y = y;
    character.currentFrame = 0;
    character.width = SPRITE_WIDTH;
    character.height = SPRITE_HEIGHT;
}

void updateHero(void) {
    character.currentFrame += 1;

    if(character.currentFrame > 3) {
        character.currentFrame = 0;
    }
}

void drawHero(void) {
    al_draw_bitmap_region(
        character.sprite, 
        character.currentFrame * character.width, 
        0, 
        character.width, 
        character.height, 
        character.x, 
        character.y, 
        0
    );
}