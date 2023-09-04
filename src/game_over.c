#include <allegro5/allegro.h>
#include "headers/game_over.h"
#include "headers/common/point.h"

struct Point position;
ALLEGRO_FONT* font;

void init_game_over(int x, int y, ALLEGRO_FONT* _font) {
    position.x = x;
    position.y = y;
    font = _font;
}

void update_game_over(long long int timer) {

}

void draw_game_over() {
    al_draw_text(font, al_map_rgb(255, 255, 255), position.x, position.y, 0, "GAME OVER");
}