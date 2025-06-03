#include "login.h"
#include "snake_game.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "user_input.h"
#include "start.h"

int log_choice (int choice) {
    system ("cls");

    printf("\033[?25h");

    drawBod(START_CASE);

    if (choice == 1)
    {
        set_position(30, 10);
        printf("Login");

        set_position(20, 13);
        printf("Username: ");

        set_position(20, 14);
        printf("Password: ");

        set_position(30, 13);
        fgets(p1.username, 70, stdin);
        p1.username[strcspn(p1.username, "\n")] = 0;

        set_position(30, 14);
        fgets(p1.passwd, 50, stdin);
        p1.passwd[strcspn(p1.passwd, "\n")] = 0;

        int *UID = malloc(5 * sizeof(int));
        char *check_pass = malloc (50 * sizeof(char));

        if (free_uid_finder(2, p1.username, UID, check_pass))
        {
            if (strcmp (p1.passwd, check_pass) == 0)
            {
                printf("\033[?25l");

                s_p1 = (struct score) {*(UID + 0), *(UID + 2), *(UID + 3), *(UID + 4)};
                p1.UID = *(UID + 0);
                free(check_pass);
                free(UID);

                set_position(28, 16);
                printf("Logging In"); 
				update_score (s_p1.current_sore);
                Sleep(2000);

                return TRUE;
            }

            else
            {
                printf("\033[?25l");

                set_position(26, 17);
                printf("User Not Found");

                Sleep(2000);

                start ();
            }
        }
        
        else
        {
            printf("\033[?25l");

            set_position(26, 17);
            printf("User Not Found");

            Sleep(2000);

            start ();
        }
    }

    else if (choice == 2)
    {
        set_position(31, 10);
        printf("Sign Up");

        FILE *f_user, *f_score;

        set_position(17, 13);
        printf("Username: ");

        set_position(17, 14);
        printf("Password: ");

        set_position(27, 13);
        fgets(p1.username, 70, stdin);
        p1.username[strcspn(p1.username, "\n")] = 0;

        set_position(27, 14);
        fgets(p1.passwd, 50, stdin);
        p1.passwd[strcspn(p1.passwd, "\n")] = 0;

        int UID[2];

        free_uid_finder(1, p1.username, UID, NULL);
        p1.UID = UID[0];
        s_p1 = (struct score) { UID[0], 0, 0, 0};


        if (UID[1] == 1)
        {

            printf("\033[?25l");

            f_user = fopen("Users.txt", "a");
            fwrite(&p1, sizeof(struct player), 1, f_user);

            f_score = fopen("Scores.txt", "a");
            fwrite(&s_p1, sizeof(struct score), 1, f_score);

            set_position(29, 16);
            printf("User Created");
            Sleep(2000);

            fclose(f_user);
            fclose(f_score);

            return log_choice(1); 
        }

        else
        {
            printf("\033[?25l");

            set_position(22, 17);
            printf("Username Already Taken");

            Sleep(2000);

            start ();
        }
    }

    return FALSE;
}

int free_uid_finder (int type, char* name, int* return_int_array, char* return_char_array) { 
    FILE *f_user,  *f_score;
    int i = 0;

    f_user = fopen ("Users.txt", "r");

    if (f_user != NULL)
    {
        fseek(f_user, 0, SEEK_END);
        long uid_number = ftell(f_user);
        rewind(f_user);

        struct player *p = malloc (uid_number);

        if (p != NULL)
        {
            if (type == 1)
            {
                int available = 1;

                while (fread((p + i), sizeof(struct player), 1, f_user) == 1)
                {
                    if (strcmp(name, (p + i) -> username) == 0)
                    {
                        available = 0;
                        break;
                    }
                    
                    else
                    {
                        i++;
                    }
                }

                fclose(f_user);

                free(p);

                uid_number /= sizeof(struct player);
                uid_number++;

                *(return_int_array + 0) =  uid_number;
                *(return_int_array + 1) = available;
            }

            else if (type == 2)
            {
                int available = 0, i = 0;

                while (fread((p + i), sizeof(struct player), 1, f_user) == 1)
                {
                    if (strcmp(name, ( p + i) -> username) == 0)
                    {
                        available = 1;
                        break;
                    }

                    i++;
                }                

                fclose(f_user);

                if (!available) 
                {
                    free(p);
                    return 0; 
                }

                f_score = fopen("Scores.txt", "r");


                *(return_int_array + 0) =  (p + i) -> UID;
                *(return_int_array + 1) = available;

                strcpy(return_char_array, (p + i) -> passwd);


                i = 0;              

                if (f_score != NULL)
                {                    
                    fseek(f_score, 0, SEEK_END);
                    long file_size_score = ftell(f_score);
                    rewind(f_score);

                    struct score *p_score = malloc (file_size_score);

                    while (fread((p_score + i), sizeof(struct score), 1, f_score) == 1)
                    {
                        if (*(return_int_array + 0) == (p_score + i)->UID)
                        {
                            *(return_int_array + 2) = (p_score + i)->highscore;
                            *(return_int_array + 3) = (p_score + i)->position;
							*(return_int_array + 4) = 0;
                            break;
                        }

                        else
                        {
                            i++;
                        }
                    }

                    fclose(f_score);
                    free(p_score);
                    free(p);
                }
            }
        }
    }
}