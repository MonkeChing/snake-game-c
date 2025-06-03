#include "start.h"
#include "board.h"
#include "constants.h"
#include <stdio.h>
#include "user_input.h"
#include "login.h"
#include "game_menu.h"
#include <windows.h>

void boot_file () {
    printf("\033[?25l");

    FILE *f_user, *f_scores;

    system("cls");

    f_user = fopen ("Users.txt", "r+");
    f_scores = fopen ("Scores.txt", "r+");

    if (f_user == NULL)
    {
        fclose(f_user);
        f_user = fopen("Users.txt", "w");
        printf("Creating Files.....\n");
        fclose(f_user);
        Sleep(5000);
    }

    if (f_scores == NULL)
    {
        fclose(f_scores);
        f_scores = fopen("Scores.txt", "w");
        printf("Creating Files.....\n");
        fclose(f_scores);
        Sleep(5000);
    }

    if (f_user != NULL && f_scores != NULL)
    {
        printf("Game Starting......");
        Sleep(1000);
    }

    fclose(f_user);
    fclose(f_scores);
}

void start () {
    drawBod (START_CASE);

    log_screen ();

    proceed (log_choice (getUserChoiceByMouse (LOG_MOUSE)));
}

void log_screen () {
    set_position(30, 13);
    printf("Login");

    set_position(29, 15);
    printf("Sign Up");
}

void exit_program () {
    system("cls");
    set_position(24, 14);
    printf("THANKS FOR PLAYING");
    Sleep(3000);

    printf("\033[?25h");
}

void proceed (int exists) {
    if (exists == 1)
    {
        while (cont)
        {
            system ("cls");
            start_menu();
        }
    }
}