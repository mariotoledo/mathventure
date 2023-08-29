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
} animations;

void initHero(int x, int y, struct Scale scale);
void updateHero(long long int timer);
void drawHero(void);
void setHeroState(enum HeroStates newState);