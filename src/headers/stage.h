#ifndef __STAGE_H__
#define __STAGE_H__

#include "common/scale.h"
#include <allegro5/allegro_font.h>

void init_stage(struct Scale scale, int window_width, int window_height, ALLEGRO_FONT* font);
void update_stage(long long int timer);
void draw_stage();
void on_key_press_stage(int keycode);
void on_key_up_stage();

#endif