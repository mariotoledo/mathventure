#include <allegro5/allegro.h>

struct Character {
    int x;
    int y;
    int width;
    int height;
    ALLEGRO_BITMAP *sprite;
    int currentFrame;
};