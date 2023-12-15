#include <iostream>
#include <conio.h>
#include "Headers.h"

int main()
{
    try
    {
        srand(time(0));
        // Зробити меню де дається вибір чи завантажувати інформацію з файлу на диску, чи створювати новий "рівень"
        Area a1(99, 24, ' ', full_symbol);
        a1.Move(0, 0);
        a1.Draw(); 
        Level l1(10, 10);
        
        for (int16_t i = 0; i < 1000; i++)
        {
            gameObject s3(rand() % (l1.width - 3) + 2, rand() % l1.height + 2, ",,,");
            s3.sprite->ReadColors("\12\12\12");
            l1.add(s3);
            gameObject s2(rand() % (l1.width - 5) + 4, rand() % (l1.height - 2) + 5, " ###\n##|##");
            s2.sprite->ReadColors(" \12\12\12 \12\12\44\12\12");
            l1.add(s2);
            gameObject s(rand() % (l1.width - 5) + 6, rand() % (l1.height - 3) + 6, " ***\n*****\n *|*\n  |");
            s.sprite->ReadColors(" \"\"\" \",\"\",\"\",D\"   D");
            l1.add(s);
        }
        l1.WriteToFile("E:/saves/file.bin");
        /*
        Player p(10, 10, "Pedro", " o\n-+-\n ^", 200);
        p.sprite->ReadColors(" \1 \1\1\1  \1");
        p.sprite->Move(10, 10);*/
        Player p;
        p.ReadFromFile("E:/saves/pedro.bin");
        p.sprite->Move(10, 10);

        //l1.ReadFromFile("E:/saves/file.bin");
        SetConsoleTextAttribute(hdl, 7);
        Table r(100, 1, 6, 5);
        
        int input = 0;
        while (true) {
            SetConsoleTextAttribute(hdl, 7);
            a1.Draw();
            l1.drawAll();
            SetConsoleTextAttribute(hdl, 7);
            SetConsoleCursorPosition(hdl, { 0, 29 });
            input = _getch();
            switch (input)
            {
            case 72: cout << "up      "; 
                l1.screen_y -= l1.screen_y - l1.screen_height < 0 ? 0 : l1.screen_height;       break;
            case 77: cout << "right   "; 
                l1.screen_x += l1.screen_x + l1.screen_width >= l1.width ? 0 : l1.screen_width;  break;
            case 80: cout << "down    "; 
                l1.screen_y += l1.screen_y + l1.screen_height >= l1.height ? 0 : l1.screen_height;   break;
            case 75: cout << "left    "; 
                l1.screen_x -= l1.screen_x - l1.screen_width < 0 ? 0 : l1.screen_width;    break;
            default: break;
            }
            cout << l1.screen_x << ' ' << l1.screen_y << "     ";
        }
    }
    catch (const char* error)
    {
        cout << "Error:" << error;
    }
/*  
    Задача 6. Реалізувати клас Chest. У якого будуте масив Items* і Area* де його виводить
    Зробити Draw щоб спочатку виводилась Area а потім всі Items*, але коодринати Items
    мають вважати за початок координат не точку 0,0 а координати Area.


*/
}
