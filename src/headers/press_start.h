#ifndef __PRESS_START_STATE_H__
#define __PRESS_START_STATE_H__

#include <allegro5/allegro_font.h>
#include "common/scale.h"

void init_press_start(int window_width, int window_height, struct Scale display_scale, ALLEGRO_FONT* _font);
void update_press_start(long long int timer);
void draw_press_start();

#endif