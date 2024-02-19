#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

int main() {
    struct node* root = createEmptyTree();
    // root = insert(root, 4);
    // root = insert(root, 1);
    // root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 3);

    cout << "Before balancing: " << endl;
    printTree(root, "", true);
    if (isFullTree) {
        cout << "*Šitas medis pilnas." << endl;
    } else {
        cout << "*Šitas medis nepilnas." << endl;
    }


    root = balance(root);
    cout << "Balanced: " << endl;
    printTree(root, "", true);

    // cout << "Min = " << minValueNode(root)->key << endl;
    // cout << "Max = " << maxValueNode(root)->key << endl;

    root = deleteNode(root, 3);
    cout << "istryne 3" << endl;
    printTree(root, "", true);

    cout << "Viršūnių iš viso: " << countNodes(root) << endl;
    cout << "Medžio aukštis: " << height(root) << endl;
    isEmpty(root);
    if (isFullTree) {
        cout << "*Šitas medis pilnas." << endl;
    } else {
        cout << "*Šitas medis nepilnas." << endl;
    }

    cout << "Sunaikinus, medžio nebėra wowwwa: " << endl;
    root = destroy(root);
    printTree(root, "", true);

    isEmpty(root);
    return 0;
}

