// github'e
//kaip ir veikia viskas bet nesuprantu
// Binary Search Tree

// root - šaknis - medžio viršūnė, į ją nėra nuorodų
#include <iostream>
using namespace std;

struct node { // will be in .h file
  int key;
  struct node *left;
  struct node *right;
};

struct node *createEmptyTree() { // kaip (?) Constructor Create() - sukuria tuščią ADT
    return NULL; 
}

struct node *createNewNode(int item) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void printTree(struct node *root, string indent = "", bool last = true) { // toString() atitikmuo
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
struct node *insert(struct node *node, int key) {
  // if the tree is empty
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

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;
  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    // If the node has two children
    struct node *temp = minValueNode(root->right);
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


//////////
int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
void storeBSTNodes(struct node* root, struct node* nodes[], int* index) {
    if (root == NULL) return;
    storeBSTNodes(root->left, nodes, index);
    nodes[*index] = root;
    (*index)++;
    storeBSTNodes(root->right, nodes, index);
}
struct node* buildTreeUtil(struct node* nodes[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct node* root = nodes[mid];
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);
    return root;
}
struct node* balance(struct node* root) {
    int n = countNodes(root);
    struct node* nodes[n];
    int index = 0;
    storeBSTNodes(root, nodes, &index);
    return buildTreeUtil(nodes, 0, n - 1);
}
///////////

void destroy(struct node *root) {
    if (root != NULL) {
        destroy(root->left);  // Sunaikiname kairįjį submedį
        destroy(root->right); // Sunaikiname dešinįjį submedį
        free(root); // Atlaisviname atmintį, skirtą dabartiniam mazgui
    }
}

int main() {
  struct node* root = createEmptyTree();
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 8);
  root = insert(root, 9);
  root = insert(root, 10);
  root = insert(root, 11);
  root = insert(root, 12);

  cout << "Before balancing: " << endl;
  printTree(root);

  root = balance(root);
  cout << "Balanced: " << endl;
  printTree(root);

  cout << "Sunaikinusss: " << endl;
  destroy(root);
  root = NULL; // gal kažkaip galima įdėti į funkciją??
  printTree(root);
  
  return 0;
}

