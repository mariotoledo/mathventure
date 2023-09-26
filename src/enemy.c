#include <allegro5/allegro.h>
#include "headers/enemy.h"
#include "headers/config.h"

int enemy_animation_speed = (int)(NUMBER_OF_FRAMES / ANIMATION_SPEED);

int enemy_animation_frame_count[] = {8, 8, 7, 10, 13, 4, 4, 5, 6, 3};
enum EnemyStates current_enemy_state;

void init_enemy(int x, int y, struct Scale scale) {
    enemy_character.sprite = al_load_bitmap("./assets/spritesheets/green_slime.png");
    enemy_character.position.x = x - (SPRITE_WIDTH);
    enemy_character.position.y = y - (SPRITE_HEIGHT);
    enemy_character.current_frame = 0;
    enemy_character.size.width = SPRITE_WIDTH;
    enemy_character.size.height = SPRITE_HEIGHT;
    enemy_character.scale = scale;
    current_enemy_state = ENEMY_IDLE;
}

void update_enemy(long long int timer) {
    //making sure the frame does not updates when the enemy is dead
    if(current_enemy_state == ENEMY_DEAD && enemy_character.current_frame == enemy_animation_frame_count[(int)ENEMY_DEAD] - 1) {
        return;
    }

    if(timer % enemy_animation_speed == 0) {
        enemy_character.current_frame += 1;
    }

    if(enemy_character.current_frame > enemy_animation_frame_count[(int)current_enemy_state] - 1) {
        enemy_character.current_frame = 0;
        
        if(current_enemy_state != ENEMY_WALK &&
            current_enemy_state != ENEMY_RUN) {
            current_enemy_state = ENEMY_IDLE;
        }            
    }
}

void draw_enemy(void) {
    al_draw_tinted_scaled_rotated_bitmap_region(
        enemy_character.sprite, 
        enemy_character.current_frame * enemy_character.size.width,   
        (int)current_enemy_state * enemy_character.size.height, 
        enemy_character.size.width, 
        enemy_character.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        enemy_character.position.x, 
        enemy_character.position.y, 
        enemy_character.scale.x * SPRITE_SCALE,
        enemy_character.scale.y * SPRITE_SCALE,
        0, 0
    );
}

void set_enemy_state(enum EnemyStates new_state) {
    enemy_character.current_frame = 0;
    current_enemy_state = new_state;
}