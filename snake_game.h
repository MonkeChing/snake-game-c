#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "constants.h"

void game_level_detection (int current_score);

void add_snake_node (struct snake_node** tail);

int check_snake_collision (int x, int y, struct snake_node* head);

int display_snake (struct snake_node* head);

void generate_food (struct food* food_location, struct snake_node* head);

void exit_game (struct snake_node* head, struct food* destroy_food, int current_score);

void destroy_snake (struct snake_node* head, struct food* destroy_food);

void update_score (int current_score);

void sort_scores (struct score* arr, int n);

void add_snake_node (struct snake_node** tail);

void remove_previous_snake (struct snake_node* head);

void update_snake_position (struct snake_node* head);

void change_direction (struct snake_node* head);

int check_collision (int* food_x, int* food_y, struct snake_node* check_snake_location);

void start_game ();

void press_enter ();

#endif