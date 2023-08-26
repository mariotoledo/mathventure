#include <allegro5/allegro.h>
#include "headers/character.h"
#include "headers/hero.h"
#include "headers/config.h"

struct Character character;

void initHero(int x, int y, struct Scale scale) {
    character.sprite = al_load_bitmap("./assets/hero.png");
    character.position.x = x;
    character.position.y = y;
    character.currentFrame = 0;
    character.size.width = SPRITE_WIDTH;
    character.size.height = SPRITE_HEIGHT;
    character.scale = scale;
}

void updateHero(void) {
    character.currentFrame += 1;

    if(character.currentFrame > 3) {
        character.currentFrame = 0;
    }
}

void drawHero(void) {
    al_draw_tinted_scaled_rotated_bitmap_region(
        character.sprite, 
        character.currentFrame * character.size.width, 
        0, 
        character.size.width, 
        character.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        character.position.x, 
        character.position.y, 
        character.scale.x,
        character.scale.y,
        0, 0
    );
}