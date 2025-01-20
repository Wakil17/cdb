#include "database.h"
#include <stdio.h>

int execute_command(Node** root, Command cmd) {
    switch(cmd.type) {
        case CMD_INSERT:
            // TODO: Insérer nouveau record
            break;
        case CMD_SELECT:
            // TODO: Afficher tous les records
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
