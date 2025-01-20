#ifndef PARSER_H
#define PARSER_H

#define MAX_MARQUE_LENGTH 50
#define MAX_MODELE_LENGTH 50

typedef enum {
    CMD_ERROR,
    CMD_INSERT,
    CMD_SELECT,
    CMD_DELETE,
    CMD_EXIT
} CommandType;

typedef struct {
    CommandType type;
    int id;
    char marque[MAX_MARQUE_LENGTH];
    char modele[MAX_MODELE_LENGTH];
} Command;

Command parse_command(char* input);

#endif
