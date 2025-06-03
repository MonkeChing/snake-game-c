#ifndef CONSTANTS_H
#define CONSTANTS_H

#define board_length 70
#define breadth 30
#define back 3
#define VIEW_MOUSE_COORD 3
#define START_CASE 1
#define MENU_CASE 2
#define START_GAME_CASE 3
#define LEADERBOARD_CASE 4
#define LOG_MOUSE 1
#define MENU_MOUSE 2
#define by "by Raunak Solomon Bailey"
#define startX 34
#define startY 17
#define SCORE_FILE "Scores.txt"
#define USER_FILE "Users.txt"

enum DIRECTION {
    STOPPED = 1,
    UP,
    DOWN,
    RIGHT,
    LEFT
};

enum LEVEL {
    L0 = 0,
    L1 = 100,
    L2 = 200,
    L3 = 320,
    L4 = 460,
    L5 = 620,
    L6 = 800,
    L7 = 1000,
    L8 = 1220,
    L9 = 1460,
    L10 = 1720
};

struct food {
    int x;
    int y;
};

struct snake_node {
    int x;
    int y;
    int direction;
    int fruits;
    struct snake_node* next;
};

struct player {
    char username[70];
    char passwd[50];
    int UID;
};

struct score {
    int UID;
    int highscore;
    int position;
    int current_sore;
};

extern struct player p1;
extern struct score s_p1;
extern int cont;

#endif
