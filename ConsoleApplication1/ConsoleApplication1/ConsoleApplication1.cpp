#include <iostream>
#include "List.h"
using namespace std;
// бінарні дерева

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(): value(0), left(nullptr), right(nullptr){ }
    Node(int value_new): value(value_new), left(nullptr), right(nullptr) { }
    void print() { cout << value << ' '; }
    operator int() const { return value; }
    Node operator =(int value_new) { return Node(value_new); }
    void addValue(int value_new) {
        if (value > value_new) {
            if (left == nullptr) { left = new Node(value_new); }
            else { left->addValue(value_new); }
        }
        else if (value < value_new) {
            if (right == nullptr) { right = new Node(value_new); }
            else { right->addValue(value_new); }
        }
    }
    void Show() {
        print();
        if (left != nullptr) { left->Show(); }
        if (right != nullptr) { right->Show(); }
    }
    Node* find(int value_search) {
        Node* element = nullptr;
        if (this == nullptr) { return nullptr; }
        if (value == value_search) { return this; }
        if (value > value_search) { 
            element = left->find(value_search); 
            if (element != nullptr) { return element; }
        }
        if (value < value_search) { 
            element = right->find(value_search); 
            if (element != nullptr) { return element; }
        }
    }
    void getElements(List<Node*>& list) {
        list.append(this);
        if (left != nullptr) { left->getElements(list); }
        if (right != nullptr) { right->getElements(list); }
    }
};

class BinaryTreeNoRepeat {
    Node* root;
public:
    BinaryTreeNoRepeat(): root(nullptr) { }
    BinaryTreeNoRepeat(int value) : root(new Node(value)){ }
    void addValue(int value_add) {
        if (root == nullptr) { root = new Node(value_add); return; }
        else { root->addValue(value_add); }
    }
    void print() {
        if (root == nullptr) { cout << "Empty tree"; }
        else { root->Show(); }
    }
    Node* find(int value_search) {
        Node* element = nullptr;
        if (root != nullptr) { element = root->find(value_search); }
        return element;
    }
    void removeValue(int value_remove) {
        List<Node*> list;
        if (root == nullptr) { cout << "Empty tree"; return; }
        root->getElements(list);
        list.remove(find(value_remove));
        
    }
};

int main()
{
    BinaryTreeNoRepeat b;
    b.addValue(1);
    b.addValue(7);
    b.addValue(9);
    b.addValue(2);
    b.addValue(6);
    b.addValue(5);
    b.addValue(11);
    b.print();
    Node* n = b.find(100);
    cout << n;
}
