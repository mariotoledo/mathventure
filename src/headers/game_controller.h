#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "common/scale.h"

void init_game(struct Scale scale);
void update_game(long long int timer);
void draw_game();
void on_key_press(int keycode);

#endif