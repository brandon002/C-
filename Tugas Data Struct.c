#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

struct node {
	int keyTemp;
	char name[31];
	int height;
	int no;
	struct node *left;
	struct node *right;
};

int max(int a, int b) {
	if (a < b) 
		return b;
	else 
		return a;
}

int getHeight(struct node *root) {
	if (root == NULL) 
		return 0;
	return 
		root->height;
}

int getBF(struct node *root) {
	if (root == NULL) 
		return 0;
	else 
		return getHeight(root->left) - getHeight(root->right);
}

struct node *rightRotate(struct node *T) {
	struct node *S = T->left;
	struct node *B = S->right;

	// rotate
	S->right = T;
	T->left = B;

	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	S->height = max(getHeight(S->left), getHeight(S->right)) + 1;

	return S;
}

struct node *leftRotate(struct node *T) {
	struct node *S = T->right;
	struct node *B = S->left;

	// rotate
	S->left = T;
	T->right = B;

	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	S->height = max(getHeight(S->left), getHeight(S->right)) + 1;

	return S;
}

struct node *newNode(int no, int x, char name[31]) {
	struct node *curNewNode = (struct node*)malloc(sizeof(struct node));
	strcpy(curNewNode->name, name);
	curNewNode->no = no;
	curNewNode->keyTemp = x;
	curNewNode->height = 1;
	curNewNode->left = NULL;
	curNewNode->right = NULL;

	return curNewNode;
}

struct node *insert(struct node *root,int no, int value, char name[31]) {
	if (root == NULL) {
		return newNode(no, value, name);
	}
	else if (value < root->keyTemp) {
		root->left = insert(root->left,no, value, name);
	}
	else {
		root->right = insert(root->right, no,value, name);
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bfactor = getBF(root);

	if (bfactor > 1 && value < root->left->keyTemp) {
		root = rightRotate(root);
	}
	else if (bfactor < -1 && value > root->right->keyTemp) {
		root = leftRotate(root);
	}
	else if (bfactor > 1 && value > root->left->keyTemp) {
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	else if (bfactor < -1 && value < root->right->keyTemp) {
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	return root;
}

struct node *deleteValue(node *root, int value)
{
	if (value < root->keyTemp) {
		root->left = deleteValue(root->left, value);
	}
	else if (value > root->keyTemp) {
		root->right = deleteValue(root->right, value);
	}
	else if (root->keyTemp == value)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			
		}
		else if (root->left != NULL && root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		else if (root->left == NULL && root->right != NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else
		{
			node *temp = root->left;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			root->no = temp->no;
			root->keyTemp = temp->keyTemp;
			strcpy(root->name, temp->name);
			root->left = deleteValue(root->left, temp->keyTemp);
		}
	}
	if (root !=NULL) {
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		int bfactor = getBF(root);

		if (bfactor > 1 && getBF(root->left) >= 0) {
			return rightRotate(root);
		}
		if (bfactor > 1 && getBF(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (bfactor < -1 && getBF(root->right) <= 0) {
			return leftRotate(root);
		}
		if (bfactor < -1 && getBF(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
   
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 


void menu(){
	printf("1. INSERT NEW PLANET/ASTEROID\n");
	printf("2. DELETE PLANET/ASERTOID\n");
	printf("3. FIND SIMILAR PLANET/ASTEROID\n");
	printf("4. SHOW PLANETS/ASTEROIDS\n");
}

void inorder_traversal(struct node* curr) {
	if (curr == NULL) return;
	inorder_traversal(curr->left);
	printf("%d %s\n", curr->keyTemp, curr->name);
	inorder_traversal(curr->right);
}
void printser(struct node* curr) {
	if (curr == NULL) return;
	inorder_traversal(curr->left);
 return;

}

void search(node* root, int number){
	if(root==NULL){
		return;
	}
	else if(number==root->keyTemp){
		printser(root);
	}
	else if (number<= root->keyTemp){
		printser(root);
	}
	else{
		printser(root);
	}
}



int main(){
	struct node *root = NULL;
	menu();
	int choice;
	int fromTemp; int toTemp;
	int tempTemp;
	char nameTemp[31];
	int charTemp[101]; int indexTemp =0; 
	char namaTemp[31][101]; int indexName =0;
	int selisih[101];
	int tes; scanf("%d", &tes);getchar();
	 int higher =0 ;
	for(int i =0;i<tes;i++)
	{
		higher=0;
	
		scanf("%d", &choice);
		switch(choice){
			case 1:	{
				scanf("%d %s",  &tempTemp, nameTemp); getchar();
				for(int i=0;i<indexTemp;i++){
					if(tempTemp < charTemp[i]){
						higher++;
						}
					}
					for(int i =0;i<101;i++){
						if(charTemp[i]==tempTemp){
							printf("%d\n", higher);
							break;
						}
					}
					charTemp[indexTemp] = tempTemp; indexTemp++;
					strcpy(namaTemp[indexName], nameTemp); indexName++; 
					root = insert(root, indexTemp, tempTemp, nameTemp); 
					printf("%d\n", higher); 
				break;
			} 
			case 2: {
					scanf("%d",  &tempTemp); getchar();
				for(int i=0;i<indexTemp;i++){
					if(charTemp[i]==tempTemp){
						deleteValue(root, tempTemp); 
						printf("%d\n", indexTemp-1);
						break;
						}
					} 
				break;
			}
			case 3: scanf("%d",  &tempTemp); getchar();{for(int i=0;i<=indexTemp;i++){
					selisih[i] = charTemp[i]-tempTemp;
					}bubbleSort(selisih, indexTemp+1); search(root, selisih[0]);
				break;
			} 
			case 4: {scanf("%d %d", &fromTemp, &toTemp);getchar(); if(toTemp>100)toTemp=100;
					if(toTemp>indexTemp)toTemp =indexTemp;
					int id = fromTemp;
					for(int i=fromTemp; i<toTemp;i++){
						printf("%d: %d %s\n", id, charTemp[i], namaTemp[i]); id++;
					}
				break;
			}
		}
	}
}
