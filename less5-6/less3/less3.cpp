#include <iostream>
using namespace std;

class My_array {
    int* arr;
    int size;
    My_array() : arr(nullptr), size(0) {}
    My_array(int _size) : size(_size), arr(new int[_size]) { }
    My_array(int* _arr, int _size) : size(_size), arr(new int[_size]) {
        for (int  i = 0; i < size; i++){ arr[i] = _arr[i]; }
    }
    void print() {
        for (int i = 0; i < size; i++) { cout << arr[i] << ','; }
    }

    void add(int element) 
    { 
        int* arr2 = new int[size + 1];
        for (int i = 0; i < size; i++) { arr2[i] = arr[i]; }
        arr2[size] = element;
        delete[] arr;
        arr = arr2;
        size++;
    }
};

// ������ 1. �������� ���� "��������� �����". � ���� ����� ����������
// ��� �����. ����� �� ���'����� ��� �����. ����� �� �������� ���� ������
// � ����� ����� ���� �� �����.
// 
// ������ 1.1. ����������� �� ������������� ������� ������ ������.
// ����������� � 1 ����� ������. ������� ������ ������ ��������� ������
// ����������� � �������� � ������� ������ ���� ������ � ��'���
// 
// ������ 2. ���������� ������ �� ��������� �������� �������� � �������
// (� ������������� ���'��). 
// 
// ������ 3. �����, �� ���� ������ ������� ������� �� ������� ���� ������. 
// ������� ����� ��������.
// 
// ������ 4. ������� ���������� �� ������������ ��������. 
// 
// ������ 5. �� ����� �� ������� ����� ����-���� �������.

int main()
{
    std::cout << "Hello World!\n";
}