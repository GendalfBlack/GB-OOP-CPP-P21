#include <iostream>
#include "Headers.h"

int main()
{
    try
    {
        srand(time(0));
        Area a1(99, 24, ' ', full_symbol);
        a1.Move(0, 0);
        a1.Draw();
        for (int8_t i = 0; i < 10; i++)
        {
            Sprite s3(",,,");
            s3.ReadColors("***");
            s3.Move(rand() % 91 + 3, rand() % 15 + 2);
            s3.Draw();
            Sprite s2(" ***\n**|**");
            s2.ReadColors(" \42\42\42 \42\42\44\42\42");
            s2.Move(rand() % 91 + 2, rand() % 15 + 5);
            s2.Draw();
            Sprite s(" ***\n*****\n *|*\n  |");
            s.ReadColors(" \"\"\" \",\"\",\"\",D\"   D");
            s.Move(rand() % 91 + 6, rand() % 15 + 6);
            s.Draw();
        }
        SetConsoleTextAttribute(hdl, 7);
        Table r(100, 1, 6, 5);
        SetConsoleCursorPosition(hdl, { 0, 29 });
        system("pause");
    }
    catch (const char* error)
    {
        cout << "Error:" << error;
    }
/*  
    Задача 4. Реалізувати клас Level. Зробити Area* щоб в ньому відображати
    спрайти. В ньому зробити массив спрайтів що є на рівні, та реалізувати 
    методи додавання спрайтів. Метод має приймати Sprite* та запам'ятовувати їх.
    Реалізувати Draw() в якому буде викликано кожен спрайт і намальовані всі 
    з 0 (Тобто викликати system("cls") та відобразити Area і всі спрайти масиву)
        
    Задача 6. Реалізувати клас Chest. У якого будуте масив Items* і Area* де його виводить
    Зробити Draw щоб спочатку виводилась Area а потім всі Items*, але коодринати Items
    мають вважати за початок координат не точку 0,0 а координати Area.


*/
}
