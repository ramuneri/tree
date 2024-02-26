#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

Node *createEmptyTree() {
    return NULL;
}

Node *createNewNode(int item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key) {
    if (node == NULL) { // Medis tuščias/pasiektas lapas
        return createNewNode(key);
    }  // negali būti vienodų reikšmių
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } 
    return node;
}
// Kažką įterpus vėl reiktų subalansuoti

Node *minValue(Node *node) {
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node *maxValue(Node *node) {
    Node *current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

Node *cloneTree(Node *root) {
    if (root == NULL) {
        return NULL;
    } else {
        Node *newNode = createNewNode(root->key);
        newNode->left = cloneTree(root->left);
        newNode->right = cloneTree(root->right);
        return newNode;
    }
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
        Node *temp = minValue(root->right);
        // Ištrintos viršūnės vietą užima mažiausia reikšmė dešiniajame pomedyje
        root->key = temp->key;
        // Ta reikšmė pašalinama iš dešiniojo pomedžio, kad nesikartotų
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Visų šitų funkcijų reikės subalansavimo funkcijai
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
// Čia In-order traversal - kairės reikšmės, viršūnė, dešinės reikšmės
void storeNodes(Node* root, Node* nodes[], int* index) {
    if (root == NULL) {
        return;
    }
    storeNodes(root->left, nodes, index);
    nodes[*index] = root; 
    ++(*index);
    storeNodes(root->right, nodes, index);
    // Susideda viršūnes į masyvą (nuo maž. iki didž.)
}
Node* buildTree(Node* nodes[], int start, int end) {
    if (start > end) {
        return NULL;
    }
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

Node* destroy(Node *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
    return NULL;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int findLevel(Node* root, int key, int level) { //Jei viršūnė yra medžio šaknis, tai jos lygis 1
    if (root == NULL) {
        return -1; // Jei neegzistuoja
    }
    if (root->key == key) {
        return level; // Jei randam reikiamą, grąžinam jo lygį
    }

    // Ieškome kiekvieno vaiko mazgo lygį, padidindami esamą lygį vienetu
    int leftLevel = findLevel(root->left, key, level+1);
    if (leftLevel != -1) {
        return leftLevel;
    }
    int rightLevel = findLevel(root->right, key, level+1);
    return rightLevel;
}

bool isFull(Node* root) { 
    if (root == NULL) {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return false;
    }
    // Tikriname rekursyviai kiekvieną vaikų šaknį
    return isFull(root->left) && isFull(root->right);
}

bool isEmpty(Node* root) {
    int n = countNodes(root);
    if (n == 0) {
        return true;
    } else {
        return false;
    }
}

bool isComplete(Node* root) { // Visi lygiai, išskyrus galbūt paskutinįjį, yra pilni
    if (root == NULL || (root->left == NULL && root->right == NULL) ) {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return false;
    }
    return isFull(root->left) && isFull(root->right);
}

void printTree(Node *root, string indent = "", bool last = true) {
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






