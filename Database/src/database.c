#include "database.h"
#include <stdio.h>
#include <string.h>
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
			printf("Voiture ajoutée: ID: %d, Marque %s, Modèle: %s \n", nouvelle_voiture.id, nouvelle_voiture.Marque, nouvelle_voiture.Modele);
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
	    /*{
	    Node* deleted = deleteNode(root, cmd.id);
	    if(deleted == NULL) {
	    printf("Aucune voiture avec l'ID %d n'a été trouvé.\n", cmd.id);
	    }else{
		printf("Voiture avec l'ID %d supprimée avec succès !\n", cmd.id);
		
	    }

	    }*/
	    //return NULL;
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



void cleanup_database(Node* root) {
    // TODO: Nettoyer la base de données
    save_database(root);
    freetree(root);
    printf("Base de donnée nettoyée et sauvegardée avec succès !\n");
}

void save_database(Node* root) {
    FILE* file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde de la base de données.\n");
        return;
    }

    save_node(root, file);
    fclose(file);
    printf("Base de données sauvegardée avec succès.\n");
}

void save_node(Node* node, FILE* file) {
    if (node == NULL) return;
    
    save_node(node->left, file);
    fprintf(file, "%d %s %s\n", node->data.id, node->data.Marque, node->data.Modele);
    save_node(node->right, file);
}
Node* init_database() {
    Node* root = NULL;
    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Aucune base de données existante trouvée. Création d'une nouvelle base.\n");
        return root;
    }

    int id;
    char marque[MAX_MARQUE_LENGTH];
    char modele[MAX_MODELE_LENGTH];

    while (fscanf(file, "%d %s %s", &id, marque, modele) == 3) {
        Voiture v = {id, "", ""};
        strncpy(v.Marque, marque, MAX_MARQUE_LENGTH - 1);
        strncpy(v.Modele, modele, MAX_MODELE_LENGTH - 1);
        root = addnode(root, v);
    }

    fclose(file);
    printf("Base de données chargée avec succès.\n");
    return root;
}
