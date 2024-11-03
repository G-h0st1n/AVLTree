//
// Created by frpat on 11/2/2024.
//

#include "AVLTree.h"

// Implementación del constructor del nodo
Node::Node(int v) : value(v), height(1), left(nullptr), right(nullptr) {}

// Implementación de AVLTree
AVLTree::AVLTree() : root(nullptr) {}

//Usando apoyo de stack overflow
int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void AVLTree::updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}


//Las rotaciones teoricamnte deberian de ser iguales nomas cambiando localizacion de nodos
Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* AVLTree::balance(Node* node) {
    updateHeight(node);
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}


//Segun el nodo, agarrarlo e insertarlo (?)
Node* AVLTree::insert(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return balance(node);
}

Node* AVLTree::findMin(Node* node) {
    while (node->left) node = node->left;
    return node;
}

Node* AVLTree::removeMin(Node* node) {
    if (!node->left) return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

Node* AVLTree::remove(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        if (!right) return left;
        Node* min = findMin(right);
        min->right = removeMin(right);
        min->left = left;
        return balance(min);
    }
    return balance(node);
}

bool AVLTree::search(Node* node, int value) {
    if (!node) return false;
    if (value < node->value) return search(node->left, value);
    if (value > node->value) return search(node->right, value);
    return true;
}

void AVLTree::inOrderTraversal(Node* node) {
    if (!node) return;
    inOrderTraversal(node->left);
    cout << node->value << " ";
    inOrderTraversal(node->right);
}

void AVLTree::preOrderTraversal(Node* node) {
    if (!node) return;
    cout << node->value << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void AVLTree::postOrderTraversal(Node* node) {
    if (!node) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->value << " ";
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

void AVLTree::remove(int value) {
    root = remove(root, value);
}

bool AVLTree::search(int value) {
    return search(root, value);
}

void AVLTree::inOrderTraversal() {
    inOrderTraversal(root);
    cout << endl;
}

void AVLTree::preOrderTraversal() {
    preOrderTraversal(root);
    cout << endl;
}

void AVLTree::postOrderTraversal() {
    postOrderTraversal(root);
    cout << endl;
}
