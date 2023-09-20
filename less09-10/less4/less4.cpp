#include <iostream>

class MyArray {
public:
    int* begin; // ������� �������
    int* end;   // ����� �������
    int getSize() { return end - begin; } // ����� ������� ������� (����� - �������)
    MyArray() : begin(nullptr), end(nullptr){} // ����������� �� �������������
    void Add(int n) { // ����� ��������� ��������
        int* newArr = new int[getSize() + 1]; // ����� ���������� ������ � ���'��
        for (int i = 0; i < getSize(); i++) { newArr[i] = begin[i]; } // ������� �������� � ����� �����
        newArr[getSize()] = n; // ��������� ���������� ��������
        end = newArr + getSize() + 1; // �����'������� ������ ���������� ��������
        delete[] begin; begin = newArr; // ������ ���'���, ��������� ������ ������� ��������
    }
    MyArray& operator=(const MyArray& other) { // �������� ������������, �� ���������� �����
        if (!(this == &other)) // ���� �� �� �� �������� ������������ ��� � ����
        {
            delete[] begin; // �������� ����� ������� ���'���
            begin = other.begin; // �����'������� ����� ������� ������
            end = other.end; // �����'������� ����� ����� ������
        }
        return *this; // � ��������� �������� ���� �� ������� ��������� �����
    }
    MyArray& operator+(int n) { Add(n); return *this; } // �������� ���������, �� ������� ���� �nt � ����� ������
    MyArray& operator+(MyArray& other) { // ���������� �������� ��������� ������ ������ �� ������
        MyArray arr;
        for (int* start = begin; start < end; start++) { arr.Add(*start); }
        for (int* start = other.begin; start < other.end; start++) { arr.Add(*start); }
        return arr;
    }
    MyArray& operator+=(MyArray& other) { // ���������� �������� ��������� ������ ������ �� ������
        for (int i = 0; i < other.getSize(); i++) {Add(other.begin[i]); }
        return *this;
    } 
    MyArray& operator+=(int n) { return *this + n; }
    int operator[](int n) { return *(begin + n); }
    void print() { for (int* start = begin; start < end; start++) { printf("%d, ", *start); } printf("\b\b \n"); }
};

int main()
{
    MyArray arr1;
    arr1 += 5;
    arr1 += 3;
    arr1 += 4;
    arr1.print();
    MyArray arr2;
    arr2 += 1;
    arr2 += 7;
    arr2 += 4;
    arr2.print();
    arr1 += arr2;
    arr1.print();
    MyArray arr3 = arr1 + arr2;
    printf("%d", arr3[0]);
}