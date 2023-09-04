#include <allegro5/allegro.h>
#include "headers/tutorial.h"
#include "headers/common/point.h"

struct Point position;
ALLEGRO_FONT* font;

void init_tutorial(int x, int y, ALLEGRO_FONT* _font) {
    position.x = x;
    position.y = y;
    font = _font;
}

void update_tutorial(long long int timer) {

}

void draw_tutorial() {
    al_draw_text(font, al_map_rgb(255, 255, 255), position.x, position.y, 0, "WIP TUTORIAL, PRESS START TO CONTINUE");
}