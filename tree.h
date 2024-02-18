#ifndef TREE_H
#define TREE_H

#include <string>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *createEmptyTree();
Node *createNewNode(int item);
void printTree(Node *root, std::string indent, bool last);
Node *insert(Node *node, int key);
Node *minValueNode(Node *node);
Node *maxValueNode(Node *node);
Node *deleteNode(Node *root, int key);
int countNodes(Node* root);
// void storeNodes(Node* root, Node* nodes[], int* index);
// Node* buildTree(Node* nodes[], int start, int end);
Node* balance(Node* root);
// void destroy(Node *root);
Node* destroy(Node *root);

#endif // TREE_H