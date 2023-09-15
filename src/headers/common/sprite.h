#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <allegro5/allegro.h>
#include "point.h"
#include "size.h"
#include "scale.h"

struct Sprite {
    struct Point position;
    struct Size size;
    ALLEGRO_BITMAP *sprite;
    int current_frame;
    struct Scale scale;
};

#endif