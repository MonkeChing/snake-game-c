#include "snake_game.h"
#include "constants.h"
#include "user_input.h"
#include "board.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void start_game () {
    system("cls");
    drawBod(START_GAME_CASE);

    struct snake_node* head = NULL;
    struct snake_node* tail = NULL;

    struct snake_node* snake = (struct snake_node *) malloc (sizeof (struct snake_node));

    snake->x = startX;
    snake->y = startY;
    snake->direction = STOPPED;
    snake->fruits = 0;
    snake->next = NULL;

    head = snake;
    tail = snake;

    set_position(2, 2);
    printf("SCORE: ");

    set_position(2, 4);
    printf("LEVEL: ");

    set_position(board_length - 19, 2);
    printf("FRUITS EATEN: ");

    set_position(board_length - 19, 4);
    printf("TO LEVEL UP: ");

    display_snake (head);

    struct food* food_location = (struct food*) malloc (sizeof (struct food));

    generate_food(food_location, head);

    while (1)
    {        
        srand(time(NULL));

        set_position(board_length - 5, 2);
        printf("%d", snake -> fruits);

        set_position(9, 2);
        printf("%d", s_p1.current_sore);

        if (check_snake_collision (head -> x, head -> y, head)) 
        {
            display_snake(head);
            set_position(board_length / 2 - 5, (breadth / 2) + 2);
            printf("GAME OVER");
            Sleep(3000);

            break;
        }

        if (snake->x == 1 || snake->x == board_length - 2 || snake->y == 6 || snake->y == breadth - 2)
        {
            display_snake(head);
            set_position(board_length / 2 - 5, breadth / 2);
            printf("GAME OVER");
            Sleep(3000);

            break;
        }

        if (snake -> x == food_location -> x && snake -> y == food_location -> y)
        {
            add_snake_node (&tail);
            generate_food(food_location, head);
            snake ->fruits++;
            s_p1.current_sore += 20;
        }

        snake->direction = get_user_keyboard_input(head);

        remove_previous_snake (head);
        update_snake_position(head);
        display_snake(head);

        game_level_detection (s_p1.current_sore);
    }

    getch();

    exit_game (head, food_location, s_p1.current_sore);

    getch();

    press_enter ();

    Sleep (4000);

    getch();
}

void game_level_detection (int current_score) {
    if (current_score < L1)
    {
        set_position(9, 4);
        printf("Tutorial");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L1 - current_score);

        Sleep (100);
    }

    else if (current_score < L2)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Beginner");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L2 - current_score);

        Sleep (80);
    }

    else if (current_score < L3)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Rookie");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L3 - current_score);

        Sleep (60);
    }
    
    else if (current_score < L4)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Learner");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L4 - current_score);

        Sleep (50);
    }

    else if (current_score < L5)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Trainee");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L5 - current_score);

        Sleep (40);
    }

    else if (current_score < L6)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Skilled");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L6 - current_score);

        Sleep (30);
    }

    else if (current_score < L7)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Expert");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L7 - current_score);

        Sleep (20);
    }

    else if (current_score < L8)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Veteran");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L8 - current_score);

        Sleep (15);
    }

    else if (current_score < L9)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Master");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L9 - current_score);

        Sleep (10);
    }

    else if (current_score < L10)
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Elite");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("%d", L10 - current_score);

        Sleep (5);
    }

    else
    {
        set_position(9, 4);
        printf("                  ");

        set_position(9, 4);
        printf("Champion");

        set_position(board_length - 6, 4);
        printf("    ");

        set_position(board_length - 6, 4);
        printf("; )");

        Sleep (2);
    }
}

void exit_game (struct snake_node* head, struct food* destroy_food, int current_score) {

    destroy_snake (head, destroy_food);

    update_score(current_score);
}

void destroy_snake (struct snake_node* head, struct food* destroy_food) {
    struct snake_node* the_destroyer;

    while (head != NULL)
    {
        the_destroyer = head;
        head = head -> next;
        free(the_destroyer);
    }

    free(destroy_food);
}

void update_score (int current_score) {
    FILE* f_score, *f_score_write, *f;

    f_score = fopen ("Scores.txt", "rb");

    fseek (f_score, 0, SEEK_END);
    int size_of_file = ftell(f_score);
    rewind (f_score);

    struct score* s = malloc (size_of_file);

    int i = 0;

    while (fread ((s + i), sizeof (struct score), 1, f_score) == 1)
    {
        if ( (s + i) -> UID == p1.UID && (s + i) -> highscore < s_p1.current_sore)
        {
            (s + i) -> highscore = s_p1.current_sore;
            s_p1.highscore = s_p1.current_sore;
        }  

        i++;
    }
    
    sort_scores(s, i);

    fclose (f_score);

    f_score_write = fopen ("Scores.txt", "w");
    fwrite(s, sizeof (struct score), i, f_score_write);

    fclose(f_score_write);

	i = 0;

	f = fopen (SCORE_FILE, "r");

	while (fread ((s + i), sizeof (struct score), 1, f) == 1)
	{
		if ((s + i) -> UID == p1.UID)
		{
			s_p1.position = (s + i) -> position;
		}
	}

	fclose(f);
	free(s);

}

void sort_scores (struct score* arr, int n) {
    int c, v;

    for (c = 0; c < n - 1; c++)
    {
        for (v = 0; v < n - c - 1; v++) 
        {
            if (arr[v].highscore < arr[v + 1].highscore || arr[v].highscore == arr[v + 1].highscore && arr[v].UID > arr[v + 1].UID) 
            {
                struct score temp = arr[v];
                arr[v] = arr[v + 1];
                arr[v + 1] = temp;
            }
        }
    }

    for (c = 0; c < n; c++) 
    {
        arr[c].position = c + 1;
    }
}

int display_snake (struct snake_node* head) {
    struct snake_node* current_position = head;

    int is_head = 1;

    while (current_position != NULL)
    {
        set_position (current_position -> x, current_position -> y);
        
        if (is_head)
        {
            switch (current_position -> direction)
            {
                case STOPPED:
                    printf("%c", 94);
                    break;

                case UP:
                    printf("%c", 94);
                    break;

                case DOWN:
                    printf("%c", 118);
                    break;
                
                case RIGHT:
                    printf("%c", 62);
                    break;

                case LEFT:
                    printf("%c", 60);
                    break;
            
                default:
                    break;
            }

            is_head = 0;
        }

        else
        {
            printf("0");
        }

        current_position = current_position->next;
    }
}

void add_snake_node (struct snake_node** tail) {
    struct snake_node* new_snake_node = (struct snake_node*) malloc (sizeof (struct snake_node));

    new_snake_node -> x = (*tail) -> x;
    new_snake_node -> y = (*tail) -> y;
    new_snake_node -> direction = (*tail) -> direction;
    new_snake_node -> next = NULL;

    (*tail) -> next = new_snake_node;
    *tail = new_snake_node;
}

void remove_previous_snake (struct snake_node* head) {
    struct snake_node* previous_snake_position = head;

    while (previous_snake_position != NULL)
    {
        set_position(previous_snake_position->x, previous_snake_position->y);
        printf("%c", 32);

        previous_snake_position = previous_snake_position->next;
    }
}

void update_snake_position (struct snake_node* head) {
    struct snake_node* current = head;
    int previous_x = current -> x;
    int previous_y = current -> y;
    int previous_direction = current -> direction;

    change_direction (head);

    current = head -> next;

    while (current != NULL)
    {
        int temp_x = current -> x;
        int temp_y = current -> y;
        int temp_direction = current -> direction;

        current -> x = previous_x;
        current -> y = previous_y;
        current -> direction = previous_direction;

        previous_x = temp_x;
        previous_y = temp_y;
        previous_direction = temp_direction;

        current = current -> next;
    }

}

void change_direction (struct snake_node* head) {
    switch (head -> direction)
    {
        case UP:
            head->y -= 1;
            break;

        case DOWN:
            head->y += 1;
            break;

        case LEFT:
            head->x -= 1;
            break;

        case RIGHT:
            head->x += 1;
            break;
    }
}

void generate_food (struct food* food_location, struct snake_node* head) {
    struct snake_node* check_snake_location = head;
    //struct food* now_food = food_location;

    //struct food* food_location, 

    int collide = 1, x, y, *food_x = &x, *food_y = &y;

    while (collide)
    {
        collide = check_collision (food_x, food_y, check_snake_location);
    }

    food_location -> x = x;
    food_location -> y = y;

    set_position (x, y);
    printf("8"); 
}

int check_collision (int* food_x, int* food_y, struct snake_node* check_snake_location) {
    *food_x = rand() % (board_length - 4) + 2;
    *food_y = rand() % (breadth - 9) + 7;   

    while (check_snake_location != NULL)
    {
        if (check_snake_location -> x == *food_x && check_snake_location -> y == *food_y)
        {
            return 1;
        }

        check_snake_location = check_snake_location -> next;
    }

    return 0;
}

int check_snake_collision (int x, int y, struct snake_node* head) {
    struct snake_node* checker = head->next;


    while (checker != NULL)
    {
        if (checker -> x == x && checker -> y == y)
        {
            return 1;
        }

        checker = checker -> next;
    }

    return 0;
}

void press_enter () {
    set_position (24, 33);
    printf("PRESS ENTER TO CONTINUE");
}