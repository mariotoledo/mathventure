#include <allegro5/allegro.h>
#include "headers/character.h"
#include "headers/hero.h"
#include "headers/config.h"

struct Character character;
int animationSpeed = (int)(NUMBER_OF_FRAMES / ANIMATION_SPEED);

int animationFrameCount[] = {8, 8, 8, 8, 6, 3, 4, 3, 3, 3};
enum HeroStates currentState;

void initHero(int x, int y, struct Scale scale) {
    character.sprite = al_load_bitmap("./assets/hero.png");
    character.position.x = x;
    character.position.y = y;
    character.currentFrame = 0;
    character.size.width = SPRITE_WIDTH;
    character.size.height = SPRITE_HEIGHT;
    character.scale = scale;
    currentState = HERO_IDLE;
}

void updateHero(long long int timer) {
    //making sure the frame does not updates when the player is dead
    if(currentState == HERO_DEAD && character.currentFrame == animationFrameCount[(int)HERO_DEAD] - 1) {
        return;
    }

    if(timer % animationSpeed == 0) {
        character.currentFrame += 1;
    }

    if(character.currentFrame > animationFrameCount[(int)currentState] - 1) {
        character.currentFrame = 0;
        //in any case, besides being dead, the player goes back to idle state
        currentState = HERO_IDLE;
    }
}

void drawHero(void) {
    al_draw_tinted_scaled_rotated_bitmap_region(
        character.sprite, 
        character.currentFrame * character.size.width, 
        (int)currentState * character.size.height, 
        character.size.width, 
        character.size.height, 
        al_map_rgb(255, 255, 255),
        0,
        0,
        character.position.x, 
        character.position.y, 
        character.scale.x + 1,
        character.scale.y,
        0, 0
    );
}

void setHeroState(enum HeroStates newState) {
    character.currentFrame = 0;
    currentState = newState;
}