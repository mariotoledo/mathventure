enum HeroStates {
    IDLE,
    WALK,
    RUN,
    JUMP,
    ATTACK1,
    ATTACK2,
    ATTACK3,
    IDLE2,
    HURT,
    DEAD
} animations;

void initHero(int x, int y, struct Scale scale);
void updateHero(long long int timer);
void drawHero(void);