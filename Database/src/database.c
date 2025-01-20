#include "database.h"
#include <stdio.h>
int execute_command(Node** root, Command cmd) {
    switch(cmd.type) {
        case CMD_INSERT:
            {
		        Voiture nouvelle_voiture;
		        nouvelle_voiture.id = cmd.id;
		        strncpy(nouvelle_voiture.Marque, cmd.marque, MAX_MARQUE_LENGTH - 1);
		        nouvelle_voiture.Marque[MAX_MARQUE_LENGTH - 1] = '\0';
		        strncpy(nouvelle_voiture.Modele, cmd.modele, MAX_MODELE_LENGTH - 1);
		        nouvelle_voiture.Modele[MAX_MODELE_LENGTH - 1] = '\0';
        
		        *root = addnode(*root, nouvelle_voiture);
    }
            break;
        case CMD_SELECT:
            if (*root == NULL) {
        printf("La base de données est vide.\n");
    } else {
        printf("Contenu de la base de données :\n");
        inorder(*root);
    }
            break;
        case CMD_DELETE:
            // TODO: Supprimer record par ID
            break;
        case CMD_EXIT:
            // TODO: Nettoyer et sortir
            break;
        default:
            return -1;
    }
    return 0;
   
}
Node* init_database() {
    // TODO: Initialiser la base de données
    return NULL;
}

void cleanup_database(Node* root) {
    // TODO: Nettoyer la base de données
}

