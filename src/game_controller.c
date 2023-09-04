#include "headers/game_controller.h"
#include "headers/hero.h"
#include "headers/press_start_state.h"
#include <allegro5/allegro5.h>

enum GameStates {
    GAME_PRESS_START,
    GAME_TUTORIAL,
    GAME_RUNNING,
    GAME_GAME_OVER,
} current_game_state;

int game_window_width;
int game_window_height;

void init_game(struct Scale display_scale, int window_width, int window_height, ALLEGRO_FONT* font) {
    init_hero(window_width / 2, window_height / 2, display_scale);
    init_press_start(window_width / 2, window_height / 2, font);
    current_game_state = GAME_PRESS_START;
    game_window_width = window_width;
    game_window_height = window_height;
}

void update_game(long long int time_tick) {
    if (current_game_state == GAME_RUNNING) {
        update_hero(time_tick);
    }
}

void draw_game() {
    if(current_game_state == GAME_PRESS_START) {
        draw_press_start();
    } else if (current_game_state == GAME_RUNNING) {
        draw_hero();
    }
}

void on_key_press(int keycode) {
    switch(keycode) {
        case ALLEGRO_KEY_ENTER:
            if(current_game_state == GAME_PRESS_START) {
                current_game_state = GAME_TUTORIAL;
            } else if (current_game_state == GAME_TUTORIAL) {
                current_game_state = GAME_RUNNING;
            }
            break;
        case ALLEGRO_KEY_A:
            set_hero_state(HERO_ATTACK1);
            break;
        case ALLEGRO_KEY_S:
            set_hero_state(HERO_HURT);
            break;
        case ALLEGRO_KEY_D:
            set_hero_state(HERO_DEAD);
            break;
    }
}