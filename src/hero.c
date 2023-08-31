#include <allegro5/allegro.h>
#include "headers/character.h"
#include "headers/hero.h"
#include "headers/config.h"

struct Character character;
int animation_speed = (int)(NUMBER_OF_FRAMES / ANIMATION_SPEED);

int animation_frame_count[] = {8, 8, 8, 8, 6, 3, 4, 3, 3, 3};
enum HeroStates current_state;

void init_hero(int x, int y, struct Scale scale) {
    character.sprite = al_load_bitmap("./assets/hero.png");
    character.position.x = x;
    character.position.y = y;
    character.current_frame = 0;
    character.size.width = SPRITE_WIDTH;
    character.size.height = SPRITE_HEIGHT;
    character.scale = scale;
    current_state = HERO_IDLE;
}

void update_hero(long long int timer) {
    //making sure the frame does not updates when the player is dead
    if(current_state == HERO_DEAD && character.current_frame == animation_frame_count[(int)HERO_DEAD] - 1) {
        return;
    }

    if(timer % animation_speed == 0) {
        character.current_frame += 1;
    }

    if(character.current_frame > animation_frame_count[(int)current_state] - 1) {
        character.current_frame = 0;
        //in any case, besides being dead, the player goes back to idle state
        current_state = HERO_IDLE;
    }
}

void draw_hero(void) {
    al_draw_tinted_scaled_rotated_bitmap_region(
        character.sprite, 
        character.current_frame * character.size.width, 
        (int)current_state * character.size.height, 
        character.size.width, 
        character.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        character.position.x, 
        character.position.y, 
        character.scale.x + 1,
        character.scale.y,
        0, 0
    );
}

void set_hero_state(enum HeroStates new_state) {
    character.current_frame = 0;
    current_state = new_state;
}