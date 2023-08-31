#include "headers/game_controller.h"
#include "headers/hero.h"
#include <allegro5/allegro5.h>

enum GameStates {
    GAME_PRESS_START,
    GAME_TUTORIAL,
    GAME_RUNNING,
    GAME_GAME_OVER,
} current_state;

void init_game(struct Scale display_scale) {
    init_hero(0, 0, display_scale);
}

void update_game(long long int time_tick) {
    update_hero(time_tick);
}

void draw_game() {
    draw_hero();
}

void on_key_press(int keycode) {
    switch(keycode) {
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