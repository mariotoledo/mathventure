#include <allegro5/allegro.h>
#include "headers/hero.h"
#include "headers/config.h"

int hero_animation_speed = (int)(NUMBER_OF_FRAMES / ANIMATION_SPEED);

int hero_animation_frame_count[] = {8, 8, 8, 8, 6, 3, 4, 3, 3, 3};
enum HeroStates current_hero_state;

void init_hero(int x, int y, struct Scale scale) {
    hero_character.sprite = al_load_bitmap("./assets/spritesheets/hero.png");
    hero_character.position.x = x - (SPRITE_WIDTH);
    hero_character.position.y = y - (SPRITE_HEIGHT);
    hero_character.current_frame = 0;
    hero_character.direction = DIRECTION_RIGHT;
    hero_character.size.width = SPRITE_WIDTH;
    hero_character.size.height = SPRITE_HEIGHT;
    hero_character.scale = scale;
    current_hero_state = HERO_IDLE;
}

void update_hero(long long int timer) {
    //making sure the frame does not updates when the player is dead
    if(current_hero_state == HERO_DEAD && hero_character.current_frame == hero_animation_frame_count[(int)HERO_DEAD] - 1) {
        return;
    }

    if(timer % hero_animation_speed == 0) {
        hero_character.current_frame += 1;
    }

    if(hero_character.current_frame > hero_animation_frame_count[(int)current_hero_state] - 1) {
        hero_character.current_frame = 0;
        
        if(current_hero_state != HERO_WALK &&
            current_hero_state != HERO_RUN) {
            current_hero_state = HERO_IDLE;
        }            
    }
}

void draw_hero(void) {
    int position_x = hero_character.position.x;

    //compensating scale diff when moving left
    if(hero_character.direction == DIRECTION_LEFT) {
        position_x += hero_character.scale.x * SPRITE_SCALE * hero_character.size.width; 
    }

    al_draw_tinted_scaled_rotated_bitmap_region(
        hero_character.sprite, 
        hero_character.current_frame * hero_character.size.width,   
        (int)current_hero_state * hero_character.size.height, 
        hero_character.size.width, 
        hero_character.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        position_x, 
        hero_character.position.y, 
        hero_character.scale.x * SPRITE_SCALE * hero_character.direction,
        hero_character.scale.y * SPRITE_SCALE,
        0, 0
    );
}

void set_hero_direction(enum SpriteDirection new_direction) {
    hero_character.direction = new_direction;
}

void set_hero_state(enum HeroStates new_state) {
    hero_character.current_frame = 0;
    current_hero_state = new_state;
}

void set_instant_idle() {
    if(current_hero_state == HERO_WALK || current_hero_state == HERO_RUN) {
        set_hero_state(HERO_IDLE);
    }
}