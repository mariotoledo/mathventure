#include "headers/game.h"
#include "headers/stage.h"
#include "headers/press_start.h"
#include "headers/tutorial.h"
#include "headers/game_over.h"
#include <allegro5/allegro5.h>

enum GameStates {
    GAME_PRESS_START,
    GAME_TUTORIAL,
    GAME_RUNNING,
    GAME_OVER,
} current_game_state;

int game_window_width;
int game_window_height;

struct Scale game_display_scale;
ALLEGRO_FONT* game_font;

void init_game(struct Scale display_scale, int window_width, int window_height, ALLEGRO_FONT* font) {
    init_press_start(window_width, window_height, display_scale, font);

    current_game_state = GAME_PRESS_START;
    game_display_scale = display_scale;
    game_font = font;

    game_window_width = window_width;
    game_window_height = window_height;
}

void update_game(long long int time_tick) {
    switch(current_game_state) {
        case GAME_PRESS_START:
            update_press_start(time_tick);
            break;
        case GAME_TUTORIAL:
            update_tutorial(time_tick);
            break;
        case GAME_RUNNING:
            update_stage(time_tick);
            break;
        case GAME_OVER:
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
            draw_stage();
            break;
        case GAME_OVER:
            draw_game_over();
            break;
    }
}

void change_state(enum GameStates newState) {
    switch(newState) {
        case GAME_PRESS_START:
            init_press_start(game_window_width, game_window_height, game_display_scale, game_font);
            break;
        case GAME_TUTORIAL:
            init_tutorial(game_window_width / 2, game_window_height / 2, game_font);
            break;
        case GAME_RUNNING:
            init_stage(game_display_scale, game_window_width, game_window_height, game_font);
            break;
    }

    current_game_state = newState;
}

void on_key_press(int keycode) {
    if(current_game_state == GAME_RUNNING) {
        on_key_press_stage(keycode);
    } else {
        switch(keycode) {
            case ALLEGRO_KEY_ENTER:
                if(current_game_state == GAME_PRESS_START) {
                    change_state(GAME_TUTORIAL);
                } else if (current_game_state == GAME_TUTORIAL) {
                    change_state(GAME_RUNNING);
                } else if (current_game_state == GAME_OVER) {
                    change_state(GAME_PRESS_START);
                }
                break;
        }
    }
}