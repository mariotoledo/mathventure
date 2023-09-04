#include "headers/game_controller.h"
#include "headers/hero.h"
#include "headers/press_start.h"
#include "headers/tutorial.h"
#include "headers/game_over.h"
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
    init_press_start(window_width / 2, window_height / 2, font);
    init_tutorial(window_width / 2, window_height / 2, font);
    init_hero(window_width / 2, window_height / 2, display_scale);

    current_game_state = GAME_PRESS_START;

    game_window_width = window_width;
    game_window_height = window_height;
}

void update_game(long long int time_tick) {
    switch(current_game_state) {
        case GAME_PRESS_START:
            update_press_start(time_tick);
            break;
        case GAME_TUTORIAL:
            update_press_start(time_tick);
            break;
        case GAME_RUNNING:
            update_hero(time_tick);
            break;
        case GAME_GAME_OVER:
            update_game_over(time_tick);
            break;      
    }
}

void draw_game() {
    switch(current_game_state) {
        case GAME_PRESS_START:
            draw_press_start();
            break;
        case GAME_TUTORIAL:
            draw_tutorial();
            break;
        case GAME_RUNNING:
            draw_hero();
            break;
        case GAME_GAME_OVER:
            draw_game_over();
            break;
    }
}

void on_key_press(int keycode) {
    switch(keycode) {
        case ALLEGRO_KEY_ENTER:
            if(current_game_state == GAME_PRESS_START) {
                current_game_state = GAME_TUTORIAL;
            } else if (current_game_state == GAME_TUTORIAL) {
                current_game_state = GAME_RUNNING;
            } else if (current_game_state == GAME_GAME_OVER) {
                current_game_state = GAME_PRESS_START;
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