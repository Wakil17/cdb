#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Command parse_command(char* input) {
    Command cmd = {CMD_ERROR};
    const char* delim = " ";
    char* token;
    int word_count = 0;
    char* words[4]; // Maximum 4 mots : commande, id, marque, modele

    // 1. Séparer la ligne en mots
    token = strtok(input, delim);
    while (token != NULL && word_count < 4) {
        words[word_count++] = token;
        token = strtok(NULL, delim);
    }

    if (word_count == 0) {
        return cmd;
    }

    // 2. Si "insert", parser id, marque, modele
    if (strcmp(words[0], "insert") == 0) {
        if (word_count == 4) {
            cmd.type = CMD_INSERT;
            cmd.id = atoi(words[1]);
            strncpy(cmd.marque, words[2], MAX_MARQUE_LENGTH - 1);
            cmd.marque[MAX_MARQUE_LENGTH - 1] = '\0';
            strncpy(cmd.modele, words[3], MAX_MODELE_LENGTH - 1);
            cmd.modele[MAX_MODELE_LENGTH - 1] = '\0';
        }
    }
    // 3. Si "select", juste type ou marque
    else if (strcmp(words[0], "select") == 0) {
        if (word_count == 1) {
            cmd.type = CMD_SELECT;
        } else if (word_count == 2) {
            cmd.type = CMD_SELECT;
            strncpy(cmd.marque, words[1], MAX_MARQUE_LENGTH - 1);
            cmd.marque[MAX_MARQUE_LENGTH - 1] = '\0';
        }
    }
    // 4. Si "delete", parser id
    else if (strcmp(words[0], "delete") == 0) {
        if (word_count == 2) {
            cmd.type = CMD_DELETE;
            cmd.id = atoi(words[1]);
        }
    }
    // 5. Si "exit", type EXIT
    else if (strcmp(words[0], "exit") == 0) {
        if (word_count == 1) {
            cmd.type = CMD_EXIT;
        }
    }

    return cmd;
}
