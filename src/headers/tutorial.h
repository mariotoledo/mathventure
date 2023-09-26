#ifndef __TUTORIAL_STATE_H__
#define __TUTORIAL_STATE_H__

#include <allegro5/allegro_font.h>
#include "common/scale.h"

void init_tutorial(int window_width, int window_height, struct Scale display_scale, ALLEGRO_FONT* _font);
void update_tutorial(long long int timer);
void draw_tutorial();

#endif