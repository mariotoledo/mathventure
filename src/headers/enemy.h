#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "common/sprite.h"

enum EnemyStates {
    ENEMY_IDLE,
    ENEMY_WALK,
    ENEMY_RUN,
    ENEMY_JUMP,
    ENEMY_ATTACK1,
    ENEMY_ATTACK2,
    ENEMY_ATTACK3,
    ENEMY_IDLE2,
    ENEMY_HURT,
    ENEMY_DEAD
};

struct Sprite enemy_character;

void init_enemy(int x, int y, struct Scale scale);
void update_enemy(long long int timer);
void draw_enemy(void);
void set_enemy_state(enum EnemyStates new_state);

#endif