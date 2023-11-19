#include <iostream>
#include "Headers.h"

int main()
{
    
    Area a1(100, 25, ' ', '@');
    a1.Move(0, 0);
    a1.Draw();
    for (int8_t i = 0; i < 10; i++)
    {
        Sprite s3(",,,");
        s3.ReadColors("***");
        s3.Move(rand() % 91 + 3, rand() % 15 + 2);
        s3.Draw();
        Sprite s2(" ***\n**|**");
        s2.ReadColors(" \"\"\" \"\"$\"\"");
        s2.Move(rand() % 91 + 2, rand() % 15 + 5);
        s2.Draw();
        Sprite s(" ***\n*****\n *|*\n  |");
        s.ReadColors(" \"\"\" \",\"\",\"\",D\"   D");
        s.Move(rand()%91+6, rand()%15+6);
        s.Draw();
    }
    Player p(10,10, "Player", " @\no+o\n |\n/ \\", 100);
    p.sprite->Move(10, 10);
    p.Draw();
    SetConsoleCursorPosition(hdl, { 0, 29 });
    system("pause");
}
