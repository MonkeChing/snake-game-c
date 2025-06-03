#include <stdio.h>
#include "user_input.h"
#include "constants.h"
#include <windows.h>

void drawBod (int scene) {

    system("cls");

    int i;

    for (i = 0; i < board_length; i++) 
    {
        set_position(i, 0);
        printf("-");
    }

    for (i = 0; i < board_length; i++) 
    {
        set_position(i, breadth - 1);
        printf("-");
    }

    for (i = 0; i < breadth; i++) 
    {
        if (i == 0 || i == breadth - 1)  
        {
            set_position(0, i);
            printf("+");
        }
        
        else 
        {
            set_position(0, i);
            printf("|");
        }
    }

    for (i = 0; i < breadth; i++) 
    {
        if (i == 0 || i == breadth - 1) 
        {
            set_position(board_length - 1, i);
            printf("+");
        }
        
        else 
        {
            set_position(board_length - 1, i);
            printf("|");
        }
    }

    if (scene == MENU_CASE)
    {
        for (i = 0; i < board_length; i++) 
        {
            set_position(i, 5);
            printf("-");
        }  

        set_position (0, 5);
        printf("+");
        
        set_position(board_length - 1, 5);
        printf("+");

        for (i = 0; i < board_length; i++) 
        {
            set_position(i, breadth - 7);
            printf("-");
        } 

        set_position (0, breadth - 7);
        printf("+");
        
        set_position(board_length - 1, breadth - 7);
        printf("+");
    }

    if (scene == START_GAME_CASE)
    {
        for (i = 0; i < board_length; i++) 
        {
            set_position(i, 5);
            printf("-");
        }  

        for (i = 1; i < board_length - 1; i++) 
        {
            set_position(i, 6);
            printf("-");

            set_position(i, breadth - 2);
            printf("-");
        }  

        for (i = 6; i < breadth - 1; i++) 
        {
            set_position(1, i);
            printf("|");

            set_position(board_length - 2, i);
            printf("|");
        } 

        set_position (0, 5);
        printf("+");
        
        set_position(board_length - 1, 5);
        printf("+");

        set_position(1, 6);
        printf("+");
        
        set_position(board_length - 2, 6);
        printf("+");

        set_position(1, breadth - 2);
        printf("+");

        set_position(board_length - 2, breadth - 2);
        printf("+");
    }

    if (scene == LEADERBOARD_CASE)
    {
        for (i = 0; i < board_length; i++) 
        {
            set_position(i, 4);
            printf("-");

            set_position(i, breadth - 5);
            printf("-");
        } 

        for (i = 0; i < breadth; i++) 
        {
            if (i == 0 || i == breadth - 1 || i == 4 || i == breadth - 5)
            {
                set_position (10, i);
                printf("+");

                set_position (20, i);
                printf("+");

                set_position (50, i);
                printf("+");

                set_position (0, i);
                printf("+");

                set_position(board_length - 1, i);
                printf("+");
            }

            else
            {
                set_position (10, i);
                printf("|");

                set_position (20, i);
                printf("|");

                set_position (50, i);
                printf("|");
            }
        }
        
        set_position(board_length - 1, 4);
        printf("+");
    }
}