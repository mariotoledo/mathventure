#include <allegro5/allegro.h>
#include "common/point.h"
#include "common/size.h"
#include "common/scale.h"

struct Character {
    struct Point position;
    struct Size size;
    ALLEGRO_BITMAP *sprite;
    int current_frame;
    struct Scale scale;
};