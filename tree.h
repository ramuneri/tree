#ifndef TREE_H
#define TREE_H

#include <string>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *createEmptyTree();
struct node *createNewNode(int item);
void printTree(struct node *root, std::string indent, bool last);
struct node *insert(struct node *node, int key);
struct node *minValueNode(struct node *node);
struct node *maxValueNode(struct node *node);
struct node *deleteNode(struct node *root, int key);
int countNodes(struct node* root);
void storeBSTNodes(struct node* root, struct node* nodes[], int* index);
struct node* buildTreeUtil(struct node* nodes[], int start, int end);
struct node* balance(struct node* root);
void destroy(struct node *root);

#endif // TREE_H