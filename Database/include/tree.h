#ifndef TREE_H
#define TREE_H

typedef struct {
    int id;
    char Marque[50];
    char Modele[50];
} Voiture;
//Le struct Voiture stock les informations
//Le struct Node stock les infos relatives au btree
typedef struct Node {
    Voiture data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newnode(Voiture data);              // Crée un nouveau nœud
Node* addnode(Node* root, Voiture data);  // Insèrer
Node* search(Node* root, int id);        // Rechercher par ID
Node* searchMarque(Node* root, const char* marque);        // Rechercher par Marque
void inorder(Node* root);                // Affiche toutes les voitures
void freetree(Node* root);               // Libère la mémoire

#endif
