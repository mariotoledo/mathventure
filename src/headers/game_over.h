#ifndef __GAMEOVER_STATE_H__
#define __GAMEOVER_STATE_H__

#include <allegro5/allegro_font.h>

void init_game_over(int x, int y, ALLEGRO_FONT* _font);
void update_game_over(long long int timer);
void draw_game_over();

#endif