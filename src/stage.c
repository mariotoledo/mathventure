#include "headers/stage.h"
#include "headers/hero.h"
#include "headers/enemy.h"
#include "headers/config.h"
#include "headers/background.h"
#include <allegro5/allegro5.h>

enum StageStates {
    STAGE_STARTING,
    STAGE_ENEMY_PRESENTATION,
    STAGE_IDLE,
    STAGE_HERO_ATTACK,
    STAGE_ENEMY_ATTACK,
} current_stage_state;

int hero_position;
int enemy_position;

int last_key_pressed = 0;

struct Scale current_display_scale;

void init_stage(struct Scale display_scale, int window_width, int window_height, ALLEGRO_FONT* font) {
    init_background(window_width, window_height, display_scale, "stage1");
    init_hero(-SPRITE_WIDTH, window_height / 3, display_scale);

    enemy_position = (window_width * 4) / 6;
    init_enemy(enemy_position, window_height / 3, display_scale);

    hero_position = window_width / 6;
    set_enemy_state(ENEMY_IDLE);

    current_stage_state = STAGE_STARTING;
    set_hero_state(HERO_RUN);

    current_display_scale = display_scale;
}

void update_stage(long long int time_tick) {
    update_background(time_tick);
    update_hero(time_tick);
    update_enemy(time_tick);

    switch(current_stage_state) {
        case STAGE_STARTING:
            if(hero_character.position.x < hero_position) {
                hero_character.position.x += (10 * current_display_scale.x);
            } else {
                current_stage_state = STAGE_IDLE;
                set_hero_state(HERO_IDLE);
            }
            break;
        case STAGE_IDLE:
            if(last_key_pressed == ALLEGRO_KEY_RIGHT) {
                hero_character.position.x += (10 * current_display_scale.x);
            } else if(last_key_pressed == ALLEGRO_KEY_LEFT) {
                hero_character.position.x -= (10 * current_display_scale.x);
            }
            break;
        case STAGE_HERO_ATTACK:
            break;
        case STAGE_ENEMY_ATTACK:
            break;      
    }
}

void draw_stage() {
    draw_background();
    draw_hero();
    draw_enemy();

    switch(current_stage_state) {
        case STAGE_STARTING:
            break;
        case STAGE_IDLE:
            break;
        case STAGE_HERO_ATTACK:
            break;
        case STAGE_ENEMY_ATTACK:
            break;      
    }
}

void on_key_press_stage(int keycode) {
    switch(keycode) {
        case ALLEGRO_KEY_ENTER:
            break;
        case ALLEGRO_KEY_A:
            set_hero_state(HERO_ATTACK1);
            last_key_pressed = keycode;
            break;
        case ALLEGRO_KEY_S:
            set_hero_state(HERO_HURT);
            last_key_pressed = keycode;
            break;
        case ALLEGRO_KEY_D:
            set_hero_state(HERO_DEAD);
            last_key_pressed = keycode;
            break;
        case ALLEGRO_KEY_RIGHT:
            set_hero_state(HERO_RUN);
            set_hero_direction(DIRECTION_RIGHT);
            last_key_pressed = keycode;
            hero_character.position.x += (10 * current_display_scale.x);
            break;
        case ALLEGRO_KEY_LEFT:
            set_hero_state(HERO_RUN);
            set_hero_direction(DIRECTION_LEFT);
            last_key_pressed = keycode;
            hero_character.position.x -= (10 * current_display_scale.x);
            break;
        default:
            set_hero_state(HERO_IDLE);
            break;
    }
}

void on_key_up_stage() {
    last_key_pressed = 0;
}