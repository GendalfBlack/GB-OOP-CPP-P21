#include <iostream>
#include "Headers.h"

int main()
{
    srand(time(0));
    Area a1(100, 25, ' ', full_symbol);
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
        s.Move(rand()%91+6, rand()%15+6);
        s.Draw();
    }
    Player p(10,10, "Player", " @\no+o\n |\n/ \\", 100);
    p.sprite->ReadColors("a");
    p.sprite->Move(10, 10);
    p.Draw();
    SetConsoleTextAttribute(hdl, 7);
    PanelVertical console(100, 0, 19, 25);
    console.Draw();
    console.Append("Hello");
    console.Append("World");
    Label button1("W - Go up", full_symbol);
    button1.Move(1, 26);
    button1.Draw();
    Label button2("A - Go left", full_symbol);
    button2.Move(3 + button1.w, 26);
    button2.Draw();
    Label button3("S - Go down", full_symbol);
    button3.Move(5 + button1.w + button2.w, 26);
    button3.Draw();
    Label button4("D - Go right", full_symbol);
    button4.Move(7 + button1.w + button2.w + button3.w, 26);
    button4.Draw();
    SetConsoleCursorPosition(hdl, { 0, 29 });
    system("pause");

/*  Задача 1. Реалізувати горизональну панель(нащадок Area), 
    щоб об'єкти друкувались один за одним тільки
    по горизонталі.

    Задача 2. Реалізувати клас Button (нащадок Label), в ньому 
    має бути два варіанти оформлення(кольору) і в залежності від
    змінної isPressed (true/false) функція Draw() відображає 
    її по різному

    Задача 3. Реалізувати клас NPC (нащадок Character), в ньому
    буде те саме що і у Player, тільки над його головою постійно
    має відображатись name.

    Задача 4. Реалізувати клас Level. Зробити Area* щоб в ньому відображати
    спрайти. В ньому зробити массив спрайтів що є на рівні, та реалізувати 
    методи додавання спрайтів. Метод має приймати Sprite* та запам'ятовувати їх.
    Реалізувати Draw() в якому буде викликано кожен спрайт і намальовані всі 
    з 0 (Тобто викликати system("cls") та відобразити Area і всі спрайти масиву)

    Задача 5. Реалізувати класс Item. У якого будуть ім'я, ціна, спрайт(зображення).
    Реалізувати його вивід через клас Label. Тобто конструктор приймає зображення
    у вигляді const char*, а клас створює у себе Label з цим зображенням
    
    Задача 6. Реалізувати клас Chest. У якого будуте масив Items* і Area* де його виводить
    Зробити Draw щоб спочатку виводилась Area а потім всі Items*, але коодринати Items
    мають вважати за початок координат не точку 0,0 а координати Area. (перед малюванням
    викликати Move відносно того де знаходиться Area)


*/
}
