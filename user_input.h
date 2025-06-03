#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "constants.h"

void set_position (int x, int y);
int getUserChoiceByMouse(int test);
int get_user_keyboard_input (struct snake_node* head);

#endif