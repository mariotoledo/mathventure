#ifndef __TUTORIAL_STATE_H__
#define __TUTORIAL_STATE_H__

#include <allegro5/allegro_font.h>

void init_tutorial(int x, int y, ALLEGRO_FONT* _font);
void update_tutorial(long long int timer);
void draw_tutorial();

#endif