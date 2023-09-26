#include <allegro5/allegro.h>
#include "headers/background.h"
#include "headers/config.h"
#include <string.h>

void init_background(int window_width, int window_height, struct Scale scale, char stageName[]) {
    char stageDestination[50] = "./assets/backgrounds/";
    strcat(stageDestination, stageName);
    strcat(stageDestination, ".png");

    background.sprite = al_load_bitmap(stageDestination);
    background.position.x = 0;
    background.position.y = 0;
    background.size.width = window_width * scale.x;
    background.size.height = window_height * scale.y;
    background.scale = scale;
}

void update_background(long long int timer) {}

void draw_background(void) {
    al_draw_tinted_scaled_rotated_bitmap_region(
        background.sprite, 
        0, 
        0, 
        background.size.width, 
        background.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        background.position.x, 
        background.position.y, 
        background.scale.x,
        background.scale.y,
        0, 0
    );
}