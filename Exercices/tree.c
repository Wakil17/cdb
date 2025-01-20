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

	printf("Noeaud crée avec succès !  Value: %d \n", new->value);	
	return new;
}

Node* addnode(Node* racine, int value){
	//si racine vide on crée une racine 
	if(racine == NULL){
		return newnode(value);
	}

	//si la valeur et plus petite on va à gauche 
	if(racine->value > value){
		racine->left = addnode(racine->left, value);
	}
	//sinon on va a droite 
	else if (racine->value < value){
		racine->right = addnode(racine->right, value);
	}	
	return racine;		
}


void inorder(Node* racine){
	if (racine == NULL) {return;}
	inorder(racine->left);
	printf("%d", racine->value);
	inorder(racine->right);

}


Node* search(Node* racine, int value){

	if(racine == NULL) {return NULL;}
	if(racine->value == value){
		return racine; 
	}else{
		search(racine->left, value);
		search(racine->right, value);	
	}



}



int main(){

	Node* head = NULL;

	head = addnode(head, 5);
	head = addnode(head, 3);
	head = addnode(head, 7);
	head = addnode(head, 1);
	head = addnode(head, 9);
	
	inorder(head);
	printf("\n");
	
	Node* find = search(head, 9);
	if(find){
		printf("Trouvé ! %d \n ", find->value);
	}else{
		printf("Element non trouvé...");
	}

	return 0; 
}
