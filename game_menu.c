#include "game_menu.h"
#include <stdio.h>
#include "constants.h"
#include "user_input.h"
#include "board.h"
#include "snake_game.h"
#include "leader.h"
#include <windows.h>
#include <conio.h>


void start_menu () {
    system ("cls");

    printf("\033[?25l");

    drawBod(MENU_CASE);

    set_position(22, 2);
    printf("Welcome To the SNAKE GAME !");

    set_position(23, 4);
    printf(by); 

    set_position(27, breadth - 6);
    printf("PLAYER INFORMATION ");

    set_position(2, breadth - 4);
    printf("USERNAME: %s", p1.username);
    
    set_position(2, breadth - 2);
    printf("USER ID: %d", p1.UID);

    set_position(board_length - 16, breadth - 4);
    printf("HIGHSCORE: %d", s_p1.highscore);

    if (s_p1.position == 0)
    {
        set_position(board_length - 16, breadth - 2);
        printf("POSITION: NULL");
    }

    else
    {
        set_position(board_length - 16, breadth - 2);
        printf("POSITION: %d", s_p1.position);
    }

    set_position(30, 12);
    printf("START GAME");

    set_position(26, 14);
    printf("PLAYER LEADERBOARD");

    set_position(33, 16);
    printf("EXIT");
    
    menu_choice(getUserChoiceByMouse(MENU_MOUSE));
}

void menu_choice (int choice) {
    if (choice == 3)
    {
        cont = 0;
    }

    else if (choice == 1)
    {
        start_game();

    }

    else if (choice == 2)
    {
        leaderboard();
    }
}