#include <iostream>
using namespace std;
// ������ 1. �������� ���� ����, �� ���� ��������� � ����-���� ����� �����. ���������� 
// �� ������ �� ����� � ������. push, pull �.�.

template <typename T>
class Stack
{
private:
	int size;
	T* arr;
public:
	Stack():size(0), arr(nullptr){ }
	void push(T element) {
		T* new_arr = new T[size + 1];
		for (int i = 0; i < size; i++) { new_arr[i] = arr[i]; }
		new_arr[size] = element; delete[]arr; arr = new_arr; size++;
	}
	T pop() {
		T result = 0; size--;
		T* new_arr = new T[size];
		for (int i = 0; i < size; i++) { new_arr[i] = arr[i]; }
		result = arr[size]; delete[]arr; arr = new_arr;	
		return result;
	}
};

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.pop() << ' ';
	cout << s.pop() << ' ';
}

// ������ 2. �������� ���� �����, �� ���� ��������� � ����-���� ����� �����. ���������� 
// �� ������ �� ����� � ������. push, pull �.�.

