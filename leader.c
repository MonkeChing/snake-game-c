#include "leader.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include "user_input.h"
#include <windows.h>
#include <string.h>
#include "snake_game.h"
#include "board.h"
#include <conio.h>

void leaderboard () {
    system("cls");
    drawBod(LEADERBOARD_CASE);

    set_position (1, 2);
    printf("Position");

    set_position (12, 2);
    printf("User ID");

    set_position (31, 2);
    printf("User Name");

    set_position (56, 2);
    printf("Highscore");
    
    FILE *score;

    score = fopen(SCORE_FILE, "r");

    fseek (score, 0, SEEK_END);
    int size_of_score_file = ftell (score);
    rewind(score);
	
    int no_of_data = size_of_score_file / sizeof (struct score), pos = 1, i = 0, j;

    if (no_of_data > 10)
    {
        struct score* leaderbaord_score = malloc (10 * sizeof (struct score));
        char display_names[10][70];
        
        fread (leaderbaord_score, sizeof (struct score), 10, score);

        for (i = 0; i < 10; i++)
		{
			find_username (display_names[i], (leaderbaord_score + i) -> UID);
		}

		j = 0;

        for (i = 5; i < 25; i += 2)
        {
            set_position (5, i);
            printf("%d", pos++);

			set_position (15, i);
            printf("%d", (leaderbaord_score + j) -> UID);

			set_position (25, i);
			printf("%s", display_names[j]);

			set_position (58, i);
            printf("%d", (leaderbaord_score + j) -> highscore);

			j++;
        }

        free (leaderbaord_score);
    }

    else
    {
        struct score* leaderbaord_score = malloc (no_of_data * sizeof (struct score));
        char display_names[no_of_data][70];

        fread(leaderbaord_score, sizeof (struct score), no_of_data, score);

		for (i = 0; i < no_of_data; i++)
		{
			find_username (display_names[i], (leaderbaord_score + i) -> UID);
		}
        
		j = 0;

        for (int i = 5; i < (no_of_data * 2) + 5; i += 2)
        {
            set_position (5, i);
            printf("%d", pos++);

			set_position (15, i);
            printf("%d", (leaderbaord_score + j) -> UID);

			set_position (25, i);
			printf("%s", display_names[j]);

			set_position (58, i);
            printf("%d", (leaderbaord_score + j) -> highscore);

			j++;
        }

        free (leaderbaord_score);
    }


    i = 27;

    set_position (5, i);
    printf("%d", s_p1.position);

    set_position (15, i);
    printf("%d", p1.UID);

    set_position (25, i);
    printf("%s", p1.username);

    set_position (58, i);
    printf("%d", s_p1.highscore);

    fclose(score);

    Sleep (2000);

    press_enter ();

    getch();
}

void find_username (char* username, int UID) {
    FILE* user;
    int i = 0;

    user = fopen (USER_FILE, "r");

    fseek (user, 0, SEEK_END);
    int size_of_user_file = ftell (user);
    rewind(user);

    int no_of_user_data = size_of_user_file / sizeof (struct player);

    struct player* p = (struct player *) calloc (no_of_user_data, sizeof (struct player));

    while (fread ((p + i), sizeof (struct player), 1, user) == 1)
    {
        i++;
    }
	for (i = 0; i < no_of_user_data; i++)
	{
		if (UID == (p + i) -> UID)
		{
			strcpy (username, (p + i) ->username);
			break;
		}
	}

    fclose (user);
    free (p);
}