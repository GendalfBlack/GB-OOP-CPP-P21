#include <iostream>
#include <fstream>

using namespace std;

// �������������� ������� ��������� (������� �������� �� ��������, �� ������ � ����� ���������)

class MyArray {
public:
    char** names; // ������ ���
    int* values; // ������ �����
    int size; // ����� ��� ���� ������
    MyArray() : names(nullptr), values(nullptr), size(0) { } // ����������� �� �������������
    void Add(const char* name, int value) { // ����� ��� ��������� ��������
        char** new_names = new char* [size + 1]; // ���������� ������ ���
        int* new_values = new int[size + 1]; // ���������� ������ �����
        for (int i = 0; i < size; i++) { new_names[i] = names[i]; new_values[i] = values[i]; } // ��������� � �������� ������
        int i = 0; // �������� ��� ������� ������ �����
        for (const char* pointer = name; *pointer != '\0' && *pointer != '\n'; pointer++){ i++; } i++; // ������ �����, ���� \0
        char* new_word = new char[i]; // �������� ���'�� ��� ������ �����
        for (int k = 0; k < i; k++) { new_word[k] = name[k]; } // ������������� ����� � ���������� � �������
        new_names[size] = new_word; // ��������� ������ ����� � ����� ���
        new_values[size] = value; // ��������� ������ ����� � ����� �����
        delete[] names; delete[] values; // ��������� ���������� ������ ���'��
        names = new_names; values = new_values; // ��������� ��������� �� ������ �� ��� �������� ������
        size++; // ��������� ������
    }
    // ���� ���� ������
    void print() { for (int i = 0; i < size; i++) { printf("%s : %d, ", names[i], values[i]); } cout << '\n'; } 
    int& operator[](const char*);
};
int& MyArray::operator[](const char* key) { // ��� ���������������� ���������
    int index = 0; // �� ������������� ��������� ������ 0 
    for (int i = 0; i < size; i++) // ��� ������� ����� � ����� names
    {
point:
        char* name = names[i]; // ������ �������� �� ����� ����� ����� � �������� "�"
        for (const char* pointer = key; *pointer != '\0'; pointer++) // ��� ��� ���� ���������� ����� "key"
        { if (*pointer != *name) // ���� ����� �� �������
        { i++; goto point; } // ���������� �� ���������� �����
        name++; } // �������� � ����� ������
        index = i; break; // ������ �����'������� ������ � �������� � �����
    }
    return values[index]; // ��������� ������� � ������ ����� �� ��� �� �������� �� 
                          // � ������� � ������ ��� � ������ �� �������� � �������
}
int main()
{
    MyArray m;
    m.Add("Danil", 1);
    m.Add("Denis", 12);
    cout << m["Denis"];
}
