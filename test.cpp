// // github'e
// // kaip ir veikia viskas bet nesuprantu
// // pilna versija
// #include <iostream>
// using namespace std;

// struct node { // will be in .h file
//   int key;
//   struct node *left;
//   struct node *right;
// };

// struct node *createEmptyTree() { // kaip (?) Constructor Create() - sukuria tuščią ADT
//   return NULL; 
// }

// struct node *createNewNode(int item) {
//   struct node *temp = (struct node*)malloc(sizeof(struct node));
//   temp->key = item;
//   temp->left = temp->right = NULL;
//   return temp;
// }


// void printTree(struct node *root, string indent = "", bool last = true) { // toString() atitikmuo
//   // rood - nuo kurio mazgo pradės spausdinti medį
//   // indent - įtraukos eil.
//   // last - ar mazgas paskutinis savo lygyje
//   // čia root (pats pirmas žymimas kaip R)
//   if (root != NULL) {
//       // Nes jei medis būtų tuščias, nieko nespausdintų
//       cout << indent;
//       // Ar tai paskutinis to lygio node (lapas)
//       if (last) {
//         cout << "R-----";
//         indent += "    ";
//       } else {
//         cout << "L-----";
//         indent += "|   ";
//       }
//       cout << root->key << endl;
//       printTree(root->left, indent, false);
//       printTree(root->right, indent, true);
//   }
// }

// struct node *insert(struct node *node, int key) {
//   if (node == NULL) {
//     return createNewNode(key);
//   }
//   if (key < node->key) {
//     node->left = insert(node->left, key);
//   } else {
//     node->right = insert(node->right, key);
//   }
//   return node;
// }

// struct node *minValueNode(struct node *node) {
//   struct node *current = node; // laikina virsune
//   while (current && current->left != NULL)
//     current = current->left;
//   return current;
// }

// struct node *maxValueNode(struct node *node) {
//   struct node *current = node; // laikina virsune
//   while (current && current->right != NULL)
//     current = current->right;
//   return current;
// }

// struct node *deleteNode(struct node *root, int key) {
//   if (root == NULL) {
//     return root;
//   }
  
//   if (key < root->key) {
//     root->left = deleteNode(root->left, key);
//   } 
//   else if (key > root->key) {
//     root->right = deleteNode(root->right, key);
//   } 
//   else { // rasta virsune kuria reikia istrinti
//   // jei turi tik viena pomedi
//     if (root->left == NULL) { 
//       struct node *temp = root->right; // sukuriama laikina virsune kad neprarasti pomedzio reiksmes
//       free(root);
//       return temp;
//     } else if (root->right == NULL) {
//       struct node *temp = root->left;
//       free(root);
//       return temp;
//     }
//     //?
//     // jei turi du pomedzius
//     struct node *temp = minValueNode(root->right);
//     // istrintos virsunes vieta uzima jos kairysis pomedis
//     root->key = temp->key;
//     // Delete the inorder successor
//     root->right = deleteNode(root->right, temp->key);
//   }
//   return root;
// }


// //////////
// int countNodes(struct node* root) {
//     if (root == NULL) return 0;
//     return countNodes(root->left) + countNodes(root->right) + 1;
// }
// void storeBSTNodes(struct node* root, struct node* nodes[], int* index) {
//     if (root == NULL) return;
//     storeBSTNodes(root->left, nodes, index);
//     nodes[*index] = root;
//     (*index)++;
//     storeBSTNodes(root->right, nodes, index);
// }
// struct node* buildTreeUtil(struct node* nodes[], int start, int end) {
//     if (start > end) return NULL;
//     int mid = (start + end) / 2;
//     struct node* root = nodes[mid];
//     root->left = buildTreeUtil(nodes, start, mid - 1);
//     root->right = buildTreeUtil(nodes, mid + 1, end);
//     return root;
// }
// struct node* balance(struct node* root) {
//     int n = countNodes(root);
//     struct node* nodes[n];
//     int index = 0;
//     storeBSTNodes(root, nodes, &index);
//     return buildTreeUtil(nodes, 0, n - 1);
// }
// ///////////

// void destroy(struct node *root) { // kaip Destructor Done() - sunaikina ADT
//     if (root != NULL) {
//         destroy(root->left);
//         destroy(root->right);
//         free(root); // Atlaisviname atmintį, skirtą dabartiniam mazgui
//     }
// }

// int main() {
//   struct node* root = createEmptyTree();
//   root = insert(root, 1);
//   root = insert(root, 2);
//   root = insert(root, 3);
//   root = insert(root, 4);
//   root = insert(root, -5);
//   root = insert(root, 6);
//   root = insert(root, 7);
//   root = insert(root, -8);
//   root = insert(root, 9);
//   root = insert(root, 10);
//   root = insert(root, 11);
//   root = insert(root, 12);

//   cout << "Before balancing: " << endl;
//   printTree(root);

//   root = balance(root);
//   cout << "Balanced: " << endl;
//   printTree(root);

//   // cout << "Min = " << minValueNode(root)->key << endl;
//   // cout << "Max = " << maxValueNode(root)->key << endl;

//   // root = deleteNode(root, 3);
//   // root = deleteNode(root, 11);
//   // cout << "istryne 3, 11" << endl;
//   // cout << "Balanced: " << endl;
//   // printTree(root);


//   cout << "Sunaikinus medžio nebėra: " << endl;
//   destroy(root);
//   root = NULL; // gal kažkaip galima įdėti į funkciją??
//   printTree(root);
  
//   return 0;
// }