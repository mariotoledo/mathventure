#include <allegro5/allegro.h>
#include "headers/press_start_state.h"
#include "headers/common/point.h"

struct Point position;
ALLEGRO_FONT* font;

void init_press_start(int x, int y, ALLEGRO_FONT* _font) {
    position.x = x;
    position.y = y;
    font = _font;
}

void update_press_start(long long int timer) {

}

void draw_press_start() {
    al_draw_text(font, al_map_rgb(255, 255, 255), position.x, position.y, 0, "PRESS START");
}