#ifndef __PRESS_START_STATE_H__
#define __PRESS_START_STATE_H__

#include <allegro5/allegro_font.h>

void init_press_start(int x, int y, ALLEGRO_FONT* _font);
void update_press_start(long long int timer);
void draw_press_start();

#endif