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
			save_database(*root);
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
	    {
	    Node* deleted = deleteNode(root, cmd.id);
	    if(deleted == NULL) {
	    printf("Aucune voiture avec l'ID %d n'a été trouvé.\n", cmd.id);
	    }else{
		printf("Voiture avec l'ID %d supprimée avec succès !\n");
	    }
	    }
            break;
        case CMD_EXIT:
            // TODO: Nettoyer et sortir
		save_database(*root);
		cleanup_database(*root);
		*root = NULL;
          	return 1;
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
    save_database(root);
    freetree(root);
    printf("Base de donnée nettoyée et sauvegardée avec succès !\n");
}

