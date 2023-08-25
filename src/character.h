#include <allegro5/allegro.h>

struct Character {
    int x;
    int y;
    int width;
    int height;
};

void initCharacter(void);
void updateCharacter(void);
void drawCharacter(void);