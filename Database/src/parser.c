#include "parser.h"
#include <string.h>

//Command parse_command(char* input) {
    //Command cmd = {CMD_ERROR};
int main(){    
    // TODO:
    // 1. Séparer la ligne en mots
    char* input = "insert 1 bmw m3";
    token = strtok(input,"" );
    while(token != NULL){
    printf("Token: %s\n", token);
    token = strtok(NULL = "");
    }

    // 2. Si "insert", parser id, name, email
    // 3. Si "select", juste type
    // 4. Si "delete", parser id
    // 5. Si "exit", type EXIT
    // Objectif: Transformer texte en commande exécutable
    return 0;
    //return cmd;
}
