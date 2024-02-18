#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

Node *createEmptyTree() { // kaip (?) Constructor Create() - sukuria tuščią ADT
    return NULL;
}

Node *createNewNode(int item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printTree(Node *root, string indent = "", bool last = true) { // toString() atitikmuo
    // rood - nuo kurio mazgo pradės spausdinti medį
    // indent - įtraukos eil.
    // last - ar mazgas paskutinis savo lygyje
    // čia root (pats pirmas žymimas kaip R)
    if (root != NULL) {
        // Nes jei medis būtų tuščias, nieko nespausdintų
        cout << indent;
        // Ar tai paskutinis to lygio node (lapas)
        if (last) {
            cout << "R-----";
            indent += "    ";
        } else {
            cout << "L-----";
            indent += "|   ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        return createNewNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *maxValueNode(Node *node) {
    Node *current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else { // Rasta viršūnė, kurią reikia ištrinti (ir ji turi tik 1 pomedį)
        if (root->left == NULL) {
            Node *temp = root->right; // Laikina viršūnė, kad neprarasti pomedžio reikšmės
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Jei turi du pomedžius
        Node *temp = minValueNode(root->right);
        // Ištrintos viršūnės vietą užima mažiausia reikšmė dešiniajame pomedyje
        root->key = temp->key;
        // Ta reikšmė pašalinama iš dešiniojo pomedžio, kad nesikartotų
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Visų šitų fuunkcijų reikės subalansavimo funkcijai
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
// Čia In-order traversal - kairės reikšmės, viršūnė, dešinės reikšmės
void storeNodes(Node* root, Node* nodes[], int* index) {
    if (root == NULL) return;
    storeNodes(root->left, nodes, index);
    nodes[*index] = root; // Susideda viršūnes į masyvą
    ++(*index);
    storeNodes(root->right, nodes, index);
}
Node* buildTree(Node* nodes[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = nodes[mid]; // Paima vidurinį el. masyve
    root->left = buildTree(nodes, start, mid-1); // Jo kairys pomedis
    root->right = buildTree(nodes, mid+1, end); // Dešinys pomedis
    return root;
}
Node* balance(Node* root) { 
    int n = countNodes(root);
    Node* nodes[n];
    int index = 0;
    storeNodes(root, nodes, &index);
    return buildTree(nodes, 0, n - 1);
}
// Iki čia buvo funkcijos, skirtos medžiui subalansuoti

// void destroy(Node *root) { // kaip Destructor Done() - sunaikina ADT
//     if (root != NULL) {
//         destroy(root->left);
//         destroy(root->right);
//         free(root); // Atlaisviname atmintį, skirtą dabartiniam mazgui
//     }
// }
Node* destroy(Node *root) { // kaip Destructor Done() - sunaikina ADT
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root); // Atlaisviname atmintį, skirtą dabartiniam mazgui
    }
    return NULL;
}