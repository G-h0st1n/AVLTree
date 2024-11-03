//
// Created by frpat on 11/2/2024.
//

// AVLTree.h
#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;


//USando como base codigo de clase de busqueda binaria...(?)
class Node {
public:
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int v);
};

class AVLTree {
private:
    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    void updateHeight(Node* node);

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* balance(Node* node);

    Node* insert(Node* node, int value);
    Node* findMin(Node* node);
    Node* removeMin(Node* node);
    Node* remove(Node* node, int value);
    bool search(Node* node, int value);

    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);

public:
    AVLTree();
    void insert(int value);
    void remove(int value);
    bool search(int value);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

#endif // AVLTREE_H
