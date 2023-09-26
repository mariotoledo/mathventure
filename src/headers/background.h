#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "common/sprite.h"

struct Sprite background;

void init_background(int window_width, int window_height, struct Scale scale, char stageName[]);
void update_background(long long int timer);
void draw_background(void);

#endif