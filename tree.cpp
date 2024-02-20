#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

Node *createEmptyTree() { // kaip (?) Constructor Create() - sukuria tuščią ADT
    return NULL;
}

void isEmpty(Node* root) {
    int n = countNodes(root);
    if (n == 0) {
        cout << "Medis yra tuščias." << endl; 
    } else {
        cout << "Medis nėra tuščias ir turi " << n << " viršūnes/(ių)." << endl; 
    }
}

bool isFull(Node* root) {
    if (root == NULL) {
        return true;
    }
    // Jeigu nėra abiejų vaikų arba yra abu vaikai
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return false;
    }
    // Tikriname rekursyviai kiekvieną vaikų šaknį
    return isFull(root->left) && isFull(root->right);
}


bool isComplete(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL) ) {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return false;
    }
    return isFull(root->left) && isFull(root->right);
}

Node *createNewNode(int item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printTree(Node *root, string indent = "", bool last = true) { // toString() atitikmuo
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

Node *insert(Node *node, int key) { // node - rodyklė į dabartinę viršūnę, kuriai vyksta įterpimas
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
        // // Jei turi du pomedžius
        // Node *temp = minValueNode(root->right);
        // // Ištrintos viršūnės vietą užima mažiausia reikšmė dešiniajame pomedyje
        // root->key = temp->key;
        // // Ta reikšmė pašalinama iš dešiniojo pomedžio, kad nesikartotų
        // root->right = deleteNode(root->right, temp->key);
        // ARBA
        // Jei turi du pomedžius
        Node *temp = maxValueNode(root->left);
        // Ištrintos viršūnės vietą užima did. reikšmė kair. pomedyje
        root->key = temp->key;
        // Ta reikšmė pašalinama iš kair. pomedžio, kad nesikartotų
        root->left = deleteNode(root->left, temp->key);
    }
    return root;
}

int height(Node* root) {
  if (root == NULL) return 0;
  return 1 + max(height(root->left), height(root->right));
}

int findLevel(Node* root, int key, int level) {
    if (root == nullptr)
        return -1; // Jei mazgas neegzistuoja, grąžiname -1

    if (root->key == key)
        return level; // Jei esame pasiekę ieškomą mazgą, grąžiname jo lygį

    // Ieškome kiekvieno vaiko mazgo lygį, padidindami esamą lygį vienetu
    int left_level = findLevel(root->left, key, level + 1);
    if (left_level != -1)
        return left_level;

    int right_level = findLevel(root->right, key, level + 1);
    return right_level;
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

    // cout << "\n\nViršūnių reikšmės sudėtos taip:" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << nodes[i]->key << " "; // kas cia blogai?
    // }
    // cout << endl << endl;

    return buildTree(nodes, 0, n - 1);
}
// Iki čia buvo funkcijos, skirtos medžiui subalansuoti

Node* destroy(Node *root) { // kaip Destructor Done() - sunaikina ADT
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root); // Atlaisviname atmintį, skirtą dabartiniam mazgui
    }
    return NULL;
}