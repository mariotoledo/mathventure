#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "common/scale.h"
#include <allegro5/allegro_font.h>

void init_game(struct Scale scale, int window_width, int window_height, ALLEGRO_FONT* font);
void update_game(long long int timer);
void draw_game();
void on_key_press(int keycode);

#endif