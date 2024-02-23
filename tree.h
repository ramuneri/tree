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
Node *insert(Node *node, int key);
Node *minValueNode(Node *node);
Node *maxValueNode(Node *node);
Node *deleteNode(Node *root, int key);
Node *balance(Node* root);
Node *destroy(Node *root);
int countNodes(Node* root);
int height(Node* root);
int findLevel(Node* root, int key, int level);
bool isFull(Node* root);
void isEmpty(Node* root);
void printTree(Node *root, std::string indent, bool last);

Node *cloneTree(Node *root);

#endif // TREE_H