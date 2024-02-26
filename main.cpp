#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

int main() {
    // Testavimas
    cout << "----TESTAVIMAS----" << endl;

    // Sukūriamas medis, įterpiamos reikšmės
    Node* root = createEmptyTree();
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);

    // Pradinis medis
    cout << "Prieš subalansavimą: " << endl;
    printTree(root, "", true);
    
    // Ar pilnas
    if (isFull (root)) {
        cout << "*Šitas medis pilnas." << endl;
    } else {
        cout << "*Šitas medis nepilnas." << endl;
    }

    // Kokiame lygyje yra atitinkami elementai
    if (findLevel(root, 3, 1) != -1) {
        cout << "7 lygis: " << findLevel(root, 3, 1) << endl;
    } else {
        cout << "Medyje nėra nurodyto elemento." << endl;
    }
    if (findLevel(root,  17, 1) != -1) {
        cout << "17 lygis: " << findLevel(root, 7, 1) << endl;
    } else {
        cout << "Medyje nėra nurodyto elemento." << endl;
    }

    // Medis subalansuojamas
    root = balance(root);
    cout << "Subalansuotas: " << endl;
    printTree(root, "", true);

    // Randamos min ir max reikšmės medyje
    cout << "Min = " << minValue(root)->key << endl;
    cout << "Max = " << maxValue(root)->key << endl;

    // Ištrinamas nurodytas elementas
    root = deleteNode(root, 3);
    cout << "Ištrynus 3: " << endl;
    printTree(root, "", true);

    // Dar info apie esamą medį
    cout << "Viršūnių iš viso: " << countNodes(root) << endl;
    cout << "Medžio aukštis: " << height(root) << endl;

    if (isEmpty(root)) {
        cout << "*Šitas medis tuščias." << endl;
    } else {
        cout << "*Šitas medis nėra tuščias." << endl;
    }

    if (isFull(root)) {
        cout << "*Šitas medis pilnas." << endl;
    } else {
        cout << "*Šitas medis nepilnas." << endl;
    }

    if (isComplete(root)) {
        cout << "*Šitas medis baigtas." << endl;
    } else {
        cout << "*Šitas medis nėra baigtas." << endl;
    }

    // Dar kartą atspausdinamas nuklonuotas medis
    cout << "Nuklonuotass: " << endl;
    Node* root2 = cloneTree(root);
    printTree(root2, "", true);

    // Medis sunaikinamas, todėl neiko nespausdina
    cout << "Sunaikinus, medžio nebėra: " << endl;
    root = destroy(root);
    printTree(root, "", true);

    // Patikrina, ar tikrai medžio nebėra (tuščias)
    isEmpty(root);
    cout << "----PABAIGA----" << endl;
    return 0;
}

