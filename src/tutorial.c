#include <allegro5/allegro.h>
#include "headers/tutorial.h"
#include "headers/common/point.h"
#include "headers/common/sprite.h"
#include "headers/config.h"

struct Point position;
ALLEGRO_FONT* font;

struct Sprite paper;

char tutorial_start_text[] = "WIP TUTORIAL, PRESS START TO CONTINUE";

void init_paper(int window_width, int window_height, struct Scale display_scale) {
    paper.sprite = al_load_bitmap("./assets/tutorial-bg.png");
    
    paper.size.width = al_get_bitmap_width(paper.sprite);
    paper.size.height = al_get_bitmap_height(paper.sprite);
    
    paper.scale = display_scale;
    paper.scale.y = window_height / paper.size.height;
    paper.scale.x = window_width / paper.size.width;

    paper.position.x = (window_width - (paper.size.width * paper.scale.x)) / 2;
    paper.position.y = (window_height - (paper.size.height * paper.scale.y)) / 2;
}

void init_tutorial(int window_width, int window_height, struct Scale display_scale, ALLEGRO_FONT* _font) {
    position.x = al_get_text_width(_font, tutorial_start_text);
    position.y = window_height / 2;
    font = _font;

    init_paper(window_width, window_height, display_scale);
}

void update_tutorial(long long int timer) {}

void draw_tutorial() {
    al_draw_tinted_scaled_rotated_bitmap_region(
        paper.sprite, 
        0, 
        0, 
        paper.size.width, 
        paper.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        paper.position.x, 
        paper.position.y, 
        paper.scale.x,
        paper.scale.y,
        0, 0
    );

    al_draw_text(font, al_map_rgb(0, 0, 0), position.x, position.y, 0, tutorial_start_text);
}