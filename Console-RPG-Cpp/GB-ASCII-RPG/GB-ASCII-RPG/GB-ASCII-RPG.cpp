#include <iostream>
#include "Headers.h"

int main()
{
    for (int8_t i = 0; i < 10; i++)
    {
        Sprite s(" ***\n*****\n *|*\n  |");
        s.Move(rand() % 100 + 5, rand() % 25 + 5);
        s.Draw();
    }
    SetConsoleCursorPosition(hdl, { 0, 29 });
    system("pause");
}
