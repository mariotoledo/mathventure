#ifndef __HERO_H__
#define __HERO_H__

#include "character.h"

enum HeroStates {
    HERO_IDLE,
    HERO_WALK,
    HERO_RUN,
    HERO_JUMP,
    HERO_ATTACK1,
    HERO_ATTACK2,
    HERO_ATTACK3,
    HERO_IDLE2,
    HERO_HURT,
    HERO_DEAD
};

struct Character hero_character;

void init_hero(int x, int y, struct Scale scale);
void update_hero(long long int timer);
void draw_hero(void);
void set_hero_state(enum HeroStates new_state);

#endif