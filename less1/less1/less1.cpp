#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
// Задача 1. Програма просить користувача ввести прізвище, ім'я та по-батькові, 
// вік та стать студента. Після чого виводить на екран його характеристики у вигляді
// таблички(рівно по відступам). Після чого програма має дати на вибір поміняти
// будь-яку з властивостей одного студента.

void cut(char* string) {
    while (*string != '\0' && *string != '\n') { string++; }
    *string = '\0';
}
// Клас - це користувацький тип даних. По певному шаблону. Який містить змінні(поля класу) та 
// функціїї(методи класу). Змінні доступні у всіх функціях. Клас являється комбінацією структури та 
// підлеглих їй функцій.
class Student {
public:
    // поля класу
    char gender;
    int age;
    char* name;
    char* middle_name;
    char* last_name;
    // Конструктор. Метод(функція) класу, що викликається автоматично при створенні об'єкта 
    // класа(екземпляр класу). Тут можна зробити всі дії по ініціалізації та початкових значень полів.
    Student() {
        name = new char[30];
        last_name = new char[30];
        middle_name = new char[30];
    }
    // Метод(функція) класу. В неї є доступ до усіх полів одного екземпляру класу з яким він був створений. Не треба писати 
    // назву об'єкту щоб використовувати інформацію записану в цьому об'єкті.
    void printStudent() {
        printf("ПІБ: %s %s %s\nСтать: %c\tВік: %d\n", name, last_name, middle_name, gender, age);
    }

    void fillStudentInfo() {
        printf("Введіть ім'я студента: ");
        cin.ignore(); fgets(name, 30, stdin); cut(name);
        printf("Введіть прізвище студента: ");
        fgets(last_name, 30, stdin); cut(last_name);
        printf("Введіть по-батькові студента: ");
        fgets(middle_name, 30, stdin); cut(middle_name);

        printf("Введіть вік студента: ");
        cin >> age;
        printf("Введіть стать студента: ");
        cin >> gender;
    }
    void changeName() {         printf("Введіть ім'я студента: ");        cin.ignore(); fgets(name, 30, stdin);        cut(name); }
    void changeLastName() {     printf("Введіть прізвище студента: ");    cin.ignore(); fgets(last_name, 30, stdin);   cut(last_name); }
    void changeMiddleName() {   printf("Введіть по-батькові студента: "); cin.ignore(); fgets(middle_name, 30, stdin); cut(middle_name); }
    void changeAge() {          printf("Введіть вік студента: ");         cin >> age; }
    void changeGender() {       printf("Введіть стать студента: ");       cin >> gender; }
    // Деструктор. Метод класу що автоматично викликається коли змінна вже не потрібна(під час 
    // закінчення роботи функціїб тощо). І тут можна звільнити пам'ять чи зробити будь-які зв'язані
    // з закінченням роботи з об'єктом дії.
    ~Student() {
        delete[] name;
        delete[] last_name;
        delete[] middle_name;
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student arr[5];
    Student s;
    while (true)
    {
        printf("Введіть номер студента(1-5) щоб заповнити інформацію, або f щоб завершити");
        char a;
        cin >> a;
        switch (a)
        {
        case '1': arr[0] = Student(); arr[0].fillStudentInfo(); break;
        case '2': arr[1] = Student(); arr[1].fillStudentInfo(); break;
        case '3': arr[2] = Student(); arr[2].fillStudentInfo(); break;
        case '4': arr[3] = Student(); arr[3].fillStudentInfo(); break;
        case '5': arr[4] = Student(); arr[4].fillStudentInfo(); break;
        case 'f': break;
        default: break;
        }
        if (a == 'f') { break; }
        for (int i = 0; i < 5; i++) { cout << i+1 << ". "; arr[i].printStudent(); }
    }
    while (true)
    {
        printf("\nВиберіть студента для редагування(1-5):");
        
        int a;
        cin >> a;
        s = arr[a - 1];

        printf("\n1. Поміняти ім'я\n2. Поміняти прізвище\n3. Поміняти по-батькові\n4. Поміняти вік\n5. Поміняти стать\n");
        char b;
        cin >> b;
        switch (b)
        {
        case '1': s.changeName();       break;
        case '2': s.changeLastName();   break;
        case '3': s.changeMiddleName(); break;
        case '4': s.changeAge();        break;
        case '5': s.changeGender();     break;
        default:  break;
        }
        for (int i = 0; i < 5; i++) { cout << i+1 << ". "; arr[i].printStudent(); }
    }
}