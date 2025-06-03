#include <windows.h>
#include "user_input.h"
#include "constants.h"
#include <stdio.h>

void set_position (int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getUserChoiceByMouse(int test) {
    HANDLE hInput;
    DWORD Events;
    INPUT_RECORD InputRecord;
    int mouseX, mouseY;

    hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

    while (1)
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);

        if (InputRecord.EventType == MOUSE_EVENT)
        {
            if (InputRecord.Event.MouseEvent.dwEventFlags == 0)
            {
                if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                {
                    mouseX = InputRecord.Event.MouseEvent.dwMousePosition.X;
                    mouseY = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    
                    if (test == VIEW_MOUSE_COORD)
                    {
                        set_position(31, 18);
                        printf("X = %d, Y = %d", mouseX, mouseY);
                    }
                    
                    if (LOG_MOUSE)
                    {
                        if (mouseX >= 30 && mouseX <= 34 && mouseY == 13)
                            return 1; 

                        if (mouseX >= 29 && mouseX <= 35 && mouseY == 15)
                            return 2; 
                    }

                    if (MENU_MOUSE)
                    {
                        if (mouseX >= 28 && mouseX <= 37 && mouseY == 12)
                            return 1; 

                        if (mouseX >= 24 && mouseX <= 41 && mouseY == 14)
                            return 2;  

                        if (mouseX >= 31 && mouseX <= 34 && mouseY == 16)
                            return 3; 
                    }
                }
            }
        }
    }
}

int get_user_keyboard_input (struct snake_node* head) {

    if (GetAsyncKeyState('W') & 0x8000 && head->direction != DOWN)
    {
        return UP;
    }

    if (GetAsyncKeyState('S') & 0x8000 && head->direction != UP)
    {
        return DOWN;
    }

    if (GetAsyncKeyState('D') & 0x8000 && head->direction  != LEFT)
    {
        return RIGHT;
    }

    if (GetAsyncKeyState('A') & 0x8000 && head->direction != RIGHT)
    {
        return LEFT;
    }    

    return head->direction;
}