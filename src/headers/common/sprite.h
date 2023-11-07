#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <allegro5/allegro.h>
#include "point.h"
#include "size.h"
#include "scale.h"

enum SpriteDirection {
    DIRECTION_RIGHT = 1,
    DIRECTION_LEFT = -1
};

struct Sprite {
    struct Point position;
    struct Size size;
    ALLEGRO_BITMAP *sprite;
    int current_frame;
    enum SpriteDirection direction;
    struct Scale scale;
};

#endif