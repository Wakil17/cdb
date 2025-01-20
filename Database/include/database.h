#ifndef DATABASE_H
#define DATABASE_H

#include "tree.h"
#include "parser.h"

// Exécute la commande donnée sur l'arbre donné
int execute_command(Node** root, Command cmd);

// Fonction pour initialiser la base de données
Node* init_database();

// Fonction pour nettoyer la base de données
void cleanup_database(Node* root);

#endif
