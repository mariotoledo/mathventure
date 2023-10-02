#include "headers/game.h"
#include "headers/stage.h"
#include "headers/press_start.h"
#include "headers/tutorial.h"
#include "headers/game_over.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "headers/config.h"

enum GameStates {
    GAME_PRESS_START,
    GAME_TUTORIAL,
    GAME_RUNNING,
    GAME_OVER,
} current_game_state;

enum GameFadeStates {
    GAME_FADE_IN,
    GAME_FADE_IN_FINISH,
    GAME_FADE_OUT,
    GAME_FADE_OUT_FINISH
} current_fade_state;

int game_window_width;
int game_window_height;

struct Scale game_display_scale;
ALLEGRO_FONT* game_font;

enum GameStates to_change_state;

int fade_count;

void init_game(struct Scale display_scale, int window_width, int window_height, ALLEGRO_FONT* font) {
    init_press_start(window_width, window_height, display_scale, font);

    current_game_state = GAME_PRESS_START;
    current_fade_state = GAME_FADE_IN;

    game_display_scale = display_scale;
    game_font = font;

    game_window_width = window_width;
    game_window_height = window_height;

    fade_count = 255 - FADE_SPEED;
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

    switch(current_fade_state) {
        case GAME_FADE_IN:
            if(fade_count > FADE_SPEED) {
                fade_count -= FADE_SPEED;
            } else {
                current_fade_state = GAME_FADE_IN_FINISH;
            }
            break;
        case GAME_FADE_OUT:
            if(fade_count < 255 - FADE_SPEED) {
                fade_count += FADE_SPEED;
            } else {
                current_fade_state = GAME_FADE_OUT_FINISH;
            }
            break;
        case GAME_FADE_OUT_FINISH:
            switch(to_change_state) {
                case GAME_PRESS_START:
                    init_press_start(game_window_width, game_window_height, game_display_scale, game_font);
                    break;
                case GAME_TUTORIAL:
                    init_tutorial(game_window_width, game_window_height, game_display_scale, game_font);
                    break;
                case GAME_RUNNING:
                    init_stage(game_display_scale, game_window_width, game_window_height, game_font);
                    break;
            }

            current_game_state = to_change_state;
            current_fade_state = GAME_FADE_IN;
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

    al_draw_filled_rectangle(0, 0, game_window_width, game_window_width, al_map_rgba(0, 0, 0, fade_count));
}

void change_state(enum GameStates newState) {
    current_fade_state = GAME_FADE_OUT;
    to_change_state = newState;
}

void on_key_press(int keycode) {
    if(current_fade_state != GAME_FADE_IN_FINISH) return;

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