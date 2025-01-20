#include<stdio.h>
#include<stdlib.h>

	typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
	} Node;


Node*  newnode(int value){

	Node *new = malloc(sizeof(Node));
	if(new == NULL){
	printf("Erreur d\'allocation memoire \n");
	return 0;
	}

	new->value = value;
	new->left = NULL;
       	new->right = NULL;

	printf("Noeaud crée avec succès ! \n  Value: %d", new->value);	
	return *new;
}

Node* addnode(Node* racine, int value){

	if(racine->value == NULL){
		newnode = newnode(value);
		return newnode;
	}

	
	if(racine->value > value){
		Node *new = malloc(sizeof(Node));
	
	if(new == NULL){
	
	}
	if(racine->value <= value){
		Node *new = malloc(sizeof(Node));
		
		if(new == NULL){
		printf("Erreur d\'allocation memoire \n");
		return 0;
		}

		new->value = value;
	       	new->left = NULL;
		new->right = NULL;	
		
	} 


	if(new == NULL){
		printf("Erreur d\'allocation memoire \n");
		return 0;
		}
	}

}


int main(){

	Node* head = malloc(sizeof(Node))

	if(head == NULL){
		printf("Echec lors de la création du premier noeud \n");
		return 0;
	}
	Node* new = newnode(head, 9);
	return 0;
}
