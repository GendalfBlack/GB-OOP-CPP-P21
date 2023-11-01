#pragma once
#include <iostream>
#include "List.h"
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr) { }
    Node(int value_new) : value(value_new), left(nullptr), right(nullptr) { }
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
    void getElements(DobleList<Node*>& list) {
        list.append(this);
        if (left != nullptr) { left->getElements(list); }
        if (right != nullptr) { right->getElements(list); }
    }
    void findDeepest(int& level, int& depths) {
        if (this == nullptr) { level--; return; }
        level++;
        if (depths < level) { depths = level; }
        if (left != nullptr) { left->findDeepest(level, depths); }
        if (right != nullptr) { right->findDeepest(level, depths); }
        level--;
    }
};

class BinaryTreeNoRepeat {
public:    
    Node* root;
    int depths;
    BinaryTreeNoRepeat() : root(nullptr), depths(0) { }
    BinaryTreeNoRepeat(int value) : root(new Node(value)), depths(0) { }
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
        DobleList<Node*> list;
        if (root == nullptr) { cout << "Empty tree"; return; }
        root->getElements(list);
        list.remove(find(value_remove));
        //list.bubbleSort();
        root = nullptr;
        for (int i = 0; i < list.getSize(); i++) { addValue(list[i]->value); }
    }
    int findDeepest() {
        if (root == nullptr) { return depths; }
        int level = 0;
        root->findDeepest(level, depths);
        return depths;
    }

};