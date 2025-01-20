#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "database.h"
#include "parser.h"

#define MAX_INPUT_LENGTH 1024

void repl(void) {
    Node* root = init_database();
    char input[MAX_INPUT_LENGTH];
    
    printf("Bienvenue dans la base de données de voitures.\n");
    printf("Utilisez les commandes suivantes:\n");
    printf("  insert <id> <marque> <modele>\n");
    printf("  select\n");
    printf("  delete <id>\n");
    printf("  exit\n");

    while(1) {
        printf("db > ");
        if (!fgets(input, MAX_INPUT_LENGTH, stdin)) {
            break;
        }
        
        // Supprimer le caractère de nouvelle ligne
        input[strcspn(input, "\n")] = 0;

        Command cmd = parse_command(input);
        if (cmd.type == CMD_ERROR) {
            printf("Commande invalide. Veuillez réessayer.\n");
            continue;
        }
        
        int result = execute_command(&root, cmd);
        if (result != 0) {
            if (result == 1) {  // CMD_EXIT
                printf("Au revoir !\n");
                break;
            } else {
                printf("Erreur lors de l'exécution de la commande.\n");
            }
        }
    }
    
    cleanup_database(root);
}

int main() {
    repl();
    return 0;
}
