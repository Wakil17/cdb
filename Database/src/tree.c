#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creation d'un nouveau node
Node* newnode(Voiture data) {
    Node* newN = malloc(sizeof(Node));
    if (newN == NULL) {
        printf("Erreur d'allocation memoire\n");
        return NULL;
    }

    newN->data = data;
    newN->left = NULL;
    newN->right = NULL;

    printf("Noeud créé avec succès ! ID: %d, Marque: %s, Modele: %s\n",
           data.id, data.Marque, data.Modele);

    return newN;
}
//Ajout d'un node supplémentaire
Node* addnode(Node* racine, Voiture data) {
    if (racine == NULL) {
        return newnode(data); //la racine passée en parametre est nulle on crée une racine
    }
    //si data id est plus petit que celui de la racine on place le noeud a gauche, sinon on le place a droite. 
    if (data.id < racine->data.id) {
        racine->left = addnode(racine->left, data);
    } else if (data.id > racine->data.id) {
        racine->right = addnode(racine->right, data);
    }
    //si c’est le même id rien pour l'instant
    return racine;
}
//Recherche par ID
Node* search(Node* racine, int id) {
    if (racine == NULL) {
        return NULL;
    }
    if (racine->data.id == id) {
        return racine;
    }
    if (id < racine->data.id) {
        return search(racine->left, id);
    }
    return search(racine->right, id);
}
//Recherche par marque 
Node* searchMarque(Node* racine, const char* marque) {
    if (racine == NULL) {
        return NULL;
    }
    if (strcmp(racine->data.Marque, marque) == 0) {
        return racine;
    }
    // On cherche à gauche
    Node* found = searchMarque(racine->left, marque);
    if (found != NULL) {
        return found;
    }
    // Sinon, on cherche à droite
    return searchMarque(racine->right, marque);
}
//Parcourir et afficher le btree
void inorder(Node* racine) {
    if (racine == NULL) {
        return;
    }
    inorder(racine->left);
    printf("ID: %d, Marque: %s, Modele: %s\n", 
           racine->data.id, 
           racine->data.Marque,
           racine->data.Modele);
    inorder(racine->right);
}

Node* deleteNode(Node** racine, int id){
printf("Désolé cette fonctinalité n'est pas encore disponible...");

// il aurait fallu faire un truc du style: 
// 1. if(racine->id == id) -> supprimer racine.data 
// 2. si racine->left/right != NULL -> on va chercher les enfants et on les "remonte" 

}

//Libère récursivement tous les nœuds de l'arbre
void freetree(Node* racine) {
    if (racine == NULL) {
        return;
    }
    freetree(racine->left);
    freetree(racine->right);
    free(racine);
}

//=== Test ===
/*int main() {
    Node* racine = NULL;

    // Création de quelques voitures
    Voiture v1 = { 10, "Toyota", "Corolla" };
    Voiture v2 = { 5, "Honda", "Civic" };
    Voiture v3 = { 15, "Ford", "Focus" };
    Voiture v4 = { 3, "Nissan", "Sentra" };
    Voiture v5 = { 7, "Toyota", "Camry" };

    // Insertion des voitures dans l'arbre
    racine = addnode(racine, v1);
    racine = addnode(racine, v2);
    racine = addnode(racine, v3);
    racine = addnode(racine, v4);
    racine = addnode(racine, v5);

    // Affichage de l'arbre dans l'ordre croissant des ID
    printf("\nParcours infixe de l'arbre:\n");
    inorder(racine);

    // Recherche par ID
    int idRecherche = 7;
    Node* trouveParID = search(racine, idRecherche);
    if (trouveParID) {
        printf("\nVoiture trouvée avec l'ID %d: %s %s\n", 
               idRecherche, 
               trouveParID->data.Marque, 
               trouveParID->data.Modele);
    } else {
        printf("\nAucune voiture trouvée avec l'ID %d\n", idRecherche);
    }

    // Recherche par marque
    const char* marqueRecherche = "Toyota";
    Node* trouveParMarque = searchMarque(racine, marqueRecherche);
    if (trouveParMarque) {
        printf("\nVoiture trouvée avec la marque %s: ID %d, Modèle: %s\n", 
               marqueRecherche, 
               trouveParMarque->data.id, 
               trouveParMarque->data.Modele);
    } else {
        printf("\nAucune voiture trouvée avec la marque %s\n", marqueRecherche);
    }

    // Libération de la mémoire de l'arbre
    freetree(racine);
    racine = NULL;

    return 0;
}*/

