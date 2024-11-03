#include "AVLTree.h"

int main() {
    AVLTree avl;
    avl.insert(20);
    avl.insert(4);
    avl.insert(15);
    avl.insert(70);
    avl.insert(50);

    cout << "In-order traversal: ";
    avl.inOrderTraversal();

    cout << "Pre-order traversal: ";
    avl.preOrderTraversal();

    cout << "Post-order traversal: ";
    avl.postOrderTraversal();

    cout << "Search for 15: " << (avl.search(15) ? "Found" : "Not found") << endl;
    cout << "Search for 99: " << (avl.search(99) ? "Found" : "Not found") << endl;

    avl.remove(15);
    cout << "In-order traversal after removing 15: ";
    avl.inOrderTraversal();

    return 0;
}
