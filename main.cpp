#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

int main() {
    struct node* root = createEmptyTree();
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    // root = insert(root, 7);
    // root = insert(root, 8);
    // root = insert(root, 9);
    // root = insert(root, 10);
    // root = insert(root, 11);
    // root = insert(root, 12);
    // root = insert(root, 13);

    cout << "Before balancing: " << endl;
    printTree(root, "", true);

    root = balance(root);
    cout << "Balanced: " << endl;
    printTree(root, "", true);

    // cout << "Min = " << minValueNode(root)->key << endl;
    // cout << "Max = " << maxValueNode(root)->key << endl;

    root = deleteNode(root, 3);
    // root = deleteNode(root, 11);
    cout << "istryne 3" << endl;
    printTree(root, "", true);

    cout << "Viršūnių iš viso: " << countNodes(root) << endl;


    cout << "Sunaikinus, medžio nebėra wow: " << endl;
    // destroy(root);
    // root = NULL; // gal kažkaip galima įdėti į funkciją??
    // printTree(root, "", true);
    root = destroy(root); // gal kažkaip galima įdėti į funkciją??
    printTree(root, "", true);

    return 0;
}

