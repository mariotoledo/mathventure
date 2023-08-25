#include <allegro5/allegro.h>
#include "character.h"

ALLEGRO_BITMAP *sprite;
struct Character character;

int currentFrame;

void initCharacter(void) {
    sprite = al_load_bitmap("./assets/hero.png");
    character.x = 0;
    character.y = 0;
    currentFrame = 0;
    character.width = 128;
    character.height = 128;
}

void updateCharacter(void) {
    currentFrame += 1;

    if(currentFrame > 3) {
        currentFrame = 0;
    }
}

void drawCharacter(void) {
    al_draw_bitmap_region(sprite, currentFrame * character.width, 0, character.width, character.height, character.x, character.y, 0);
}