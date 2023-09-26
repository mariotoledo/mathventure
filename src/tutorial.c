#include <allegro5/allegro.h>
#include "headers/tutorial.h"
#include "headers/common/point.h"
#include "headers/common/sprite.h"
#include "headers/config.h"

int book_animation_speed = (int)(NUMBER_OF_FRAMES / ANIMATION_SPEED);
int book_animation_frame_count[] = {6, 6, 6, 6, 6, 6};

struct Point position;
ALLEGRO_FONT* font;

int book_scale;
int book_width = 28;
int book_height = 35;

struct Sprite book;

enum BookStates current_book_state;

bool is_book_idle;

enum BookStates {
    BOOK_OPENING,
    BOOK_FIRST_PAGE,
    BOOK_PAGE_TURN_RIGHT,
    BOOK_PAGE_TURN_LEFT,
    BOOK_LAST_PAGE,
    BOOK_CLOSING,
    BOOK_TURN
};

void init_tutorial(int window_width, int window_height, struct Scale display_scale, ALLEGRO_FONT* _font) {
    position.x = window_width / 2;
    position.y = window_height / 2;
    font = _font;

    book.sprite = al_load_bitmap("./assets/book.png");

    int expected_book_height = window_height - (150 * display_scale.y);
    book_scale = expected_book_height / book_height;
    int expected_book_width = book_width * book_scale * display_scale.x;

    book.position.x = (window_width - expected_book_width) / 2;
    book.position.y = (window_height - (expected_book_height * display_scale.y));
    book.size.width = book_width;
    book.size.height = book_height;
    book.scale = display_scale;

    current_book_state = BOOK_OPENING;
    is_book_idle = false;
}

void update_tutorial(long long int timer) {
    if(timer % book_animation_speed == 0 && !is_book_idle) {
        book.current_frame += 1;
    }

    if(book.current_frame > book_animation_frame_count[(int)current_book_state] - 1) {
        book.current_frame = 0;
        current_book_state = BOOK_FIRST_PAGE;
        
        is_book_idle = true;          
    }
}

void draw_tutorial() {
    al_draw_tinted_scaled_rotated_bitmap_region(
        book.sprite, 
        book.current_frame * book.size.width,   
        (int)current_book_state * book.size.height, 
        book.size.width, 
        book.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        book.position.x, 
        book.position.y, 
        book.scale.x * book_scale,
        book.scale.y * book_scale,
        0, 0
    );

    al_draw_text(font, al_map_rgb(255, 255, 255), position.x, position.y, 0, "WIP TUTORIAL, PRESS START TO CONTINUE");
}