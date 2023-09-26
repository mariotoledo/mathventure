#include <allegro5/allegro.h>
#include "headers/press_start.h"
#include "headers/common/point.h"
#include "headers/background.h"
#include "headers/common/sprite.h"
#include <stdlib.h>

struct Point press_start_position;
ALLEGRO_FONT* font;

struct Sprite logo;

char backgrounds[8][20] = {"stage1", "stage2", "stage3", "stage4", "stage5", "stage6", "stage7", "stage8"};

void init_logo(int window_width, int window_height, struct Scale display_scale) {
    logo.sprite = al_load_bitmap("./assets/logo.png");
    logo.position.x = (window_width - (al_get_bitmap_width(logo.sprite) * display_scale.x)) / 2;
    logo.position.y = window_height / 3;
    logo.size.width = window_width * display_scale.x;
    logo.size.height = window_height * display_scale.y;
    logo.scale = display_scale;
}

void init_press_start(int window_width, int window_height, struct Scale display_scale, ALLEGRO_FONT* _font) {
    int backgroundIndex = rand() % 8;
    
    init_background(window_width, window_height, display_scale, backgrounds[backgroundIndex]);
    press_start_position.x = window_width / 2;
    press_start_position.y = window_height / 2;
    font = _font;

    init_logo(window_width, window_height, display_scale);
}

void draw_logo() {
    al_draw_tinted_scaled_rotated_bitmap_region(
        logo.sprite, 
        0, 
        0, 
        logo.size.width, 
        logo.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        logo.position.x, 
        logo.position.y, 
        logo.scale.x,
        logo.scale.y,
        0, 0
    );
}

void update_press_start(long long int timer) {
    update_background(timer);
}

void draw_press_start() {
    draw_background();
    draw_logo();
    al_draw_text(font, al_map_rgb(255, 255, 255), press_start_position.x, press_start_position.y, 0, "PRESS START");
}