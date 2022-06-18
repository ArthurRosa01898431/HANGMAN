 
#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include <string.h>
#include "my_string.h"
#include "associative_array.h"
#include "status.h"


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess) {  

	
//															My_string* pCurrent_word_family = (My_string*) current_word_family;

	
	
//	my_string_assignment((ITEM*) &pNew_key, (ITEM)pCurrent_word_family);
//	 my_string_assignment((ITEM*) &new_key, (ITEM)current_word_family);
	for(int i = 0; i < my_string_get_size(word); i++) {

		if (guess == *my_string_at(word, i)) {



//			pNew_key->data[i] = guess;
			my_string_push_back( new_key,guess);
					}
	
		else {
			my_string_push_back(new_key,*my_string_at(current_word_family,i));

		}
	}

	return SUCCESS;
	

}



Tree* tree_init_default(void) {

	Tree* temp = (Tree*)malloc(sizeof(Tree));

	if (temp !=  NULL) {

		temp->root = NULL;
	}
	
	return (Tree*)temp;


}

void Tree_destroy(Tree** phTree)
{
    if (phTree != NULL)
    {
        Tree* pTree = (Tree*)*phTree;
        if (pTree != NULL)
        {
            node_destroy(pTree->root);
            free(pTree);
        }
    }
}


void node_destroy(Node* root)
{
    if (root != NULL)
    {
        if (root->index != NULL){
           generic_vector_destroy(&(root->index)	);
	}

        node_destroy(root->left);
        node_destroy(root->right);

       my_string_destroy(&(root->key));

        free(root);
    }
}

Status tree_insert(Tree* tree, MY_STRING key, MY_STRING word){

	Tree* temp = (Tree*) tree;
	
	if(temp == NULL) {

		return FAILURE;
	}

//	printf("before return of tree insert\n");	
	return insert(&(temp->root),key,word);



}

GENERIC_VECTOR* find_max_list_in_tree(Tree** pTree) {

	int size = 0;
						//Chalanege Bug- Had to have a poninter to a variable and not a pointer to an int like int* max = 0;
	int* max = &size;

	Node* temp;
	
	in_order_find_max((*pTree)->root,&temp, max);

	return &( temp->index);

	

}


void in_order_find_max(Node* pNode, Node** ppTempNode ,int* pSize) {

	if (pNode != NULL) {	

	in_order_find_max(pNode->left, ppTempNode, pSize);

//	printf("Current MAx is %d and vector size is %d\n", *pSize, generic_vector_get_size(pNode->index));

	if(*pSize < generic_vector_get_size(pNode->index)) {  //Transversing the tree and intialising the temp Vector to the largest
		*pSize = generic_vector_get_size(pNode->index);
		*ppTempNode = pNode;

//		printf("Max size is %d\n", *pSize);
	}

	in_order_find_max(pNode->right, ppTempNode, pSize);

	}


}



void swapVector(GENERIC_VECTOR* vector_one, GENERIC_VECTOR* vector_two ) {
	
	GENERIC_VECTOR temp; 
	
       //generic_vector_destroy(vector_one);

	temp = *vector_one;

	*vector_one = *vector_two;

	*vector_two  = temp;



}	
Status insert(Node** node, MY_STRING key, MY_STRING word) {


   Node* temp_node;
    int comparison;
    int balance;
    if (*node == NULL)
    {	

//	printf("First if INside\n");
        temp_node = (Node*)malloc(sizeof(Node));
        if (temp_node == NULL){
	       	return FAILURE;
	}
//	printf("Before intitalizing the node\n");
        temp_node->left = NULL;
        temp_node->right = NULL;
        temp_node->height = 1;

//	printf("Before intitalizing the node's key and index\n");
        temp_node->key = my_string_init_default();
        temp_node->index = generic_vector_init_default(my_string_assignment, my_string_destroy); //This is item assignment and destry
	
//	printf("Before for loop in insert\n");
//
//	
//
/*	
 
	for(i = 0; i < my_string_get_size(key); i++) {


		my_string_push_back(temp_node->key, *my_string_at(key, i));

	}
*/

	my_string_assignment(&(temp_node->key),key);
	//Insert the word with the vector that matches the key
	//
//	printf("After for loop in insert\n");
	generic_vector_push_back(temp_node->index,  word);

	*node = temp_node;	

//	printf("Before return in first node\n");
	return SUCCESS;
	}
	


    comparison = my_string_compare(key,(*node)->key);
	
//	printf("The new key is: %s. The parrent is %s\n",my_string_c_str(key),my_string_c_str((*node)->key));
  //  printf("My string COmpare Value: %d\n",my_string_compare(key,(*node)->key));
	if(comparison == 0) {
		generic_vector_push_back((*node)->index,word);

	}


	if(comparison == 1)  {

		insert(&((*node)->right), key, word);



		}

	if (comparison == -1){
		insert(&((*node)->left), key, word);


	}

//	printf("Before max of two nodes\n");
	(*node)->height = 1 + max(height((*node)->left), height((*node)->right));
//	printf("Node height: %d for %s key \n ", (*node)->height ,my_string_c_str(((*node)->key)));
	
	balance = getBalance(node);
//	printf("After get Balance and before check for balance\n");
//	
//	printf("The balance is %d\n",balance);
	if (balance < -1 || balance > 1) {

//		printf("INside balance for loop\n");
		//Right  Rotate //Straight line // Right of root // LEft Left case
		if (balance > 1 && my_string_compare(key,(*node)->left->key) == -1 ) {  //-1 means the inputed key is less then key above
//			printf("Right Rotate\n");	
			(*node) = rightRotate(*node);
			return SUCCESS;

		}
		//Left Rotate // Straight Line // Left of root	// Right Right case
		 if (balance < -1 && my_string_compare(key ,(*node)->right->key) == 1  ) {
//			  printf("Left Rotate\n");
			(*node) = leftRotate(*node);

			return SUCCESS;

                }
		 //Left right case

		 if (balance > 1 && my_string_compare(key,(*node)->left->key) == 1) {

//			  printf("Left Right Rotate\n");
			(*node)->left = leftRotate((*node)->left);
			(*node) = rightRotate(*node);
			return SUCCESS;

                }
		//Right left case
		 if (balance < -1 && my_string_compare(key,(*node)->right->key) == -1) {
//			 printf("Right Left Rotate\n");
			(*node)->right = rightRotate((*node)->right);
            		(*node) = leftRotate(*node);
//			printf("RL DOWN\n");
			return SUCCESS;

                }

	}

	return SUCCESS;	

	
}
	


int max(int a, int b)
{
    return ((a > b) ? a : b);
}


int getBalance(Node **pNode)
{
    if (*pNode == NULL){
        return 0;
    }
    return (height((*pNode)->left) - height((*pNode)->right));
}

int height(Node* pNode)
{
    if (pNode == NULL) {
	    return 0;
	}
    return pNode->height;
}


Node* leftRotate(Node* pNode) {
	Node* temp = pNode->right;
	Node* temp2 = temp->left;
	
	if(temp->left== NULL) {

		temp2 = NULL;

	}

	else {


		temp2 = temp->left;

	}

	temp->left = pNode;

	pNode->right = temp2 ; 

	pNode->height = max(height(pNode->left), height(pNode->right)) + 1;

	temp->height = max(height(temp->left), height(temp->right)) + 1;

	return temp;
}



Node* rightRotate(Node* pNode) {
	Node* temp = pNode->left;
	Node* temp2;
	
//	printf("Start of rightRotate\n");
	if(temp->right == NULL) {
		temp2 = NULL;
	}

	else {
		temp2 = temp->right;
	}

//	printf("AAA\n");
	temp->right  = pNode;

	pNode->left = temp2;
//	printf("Before max in right Rotate\n");
	pNode->height = max(height(pNode->left), height(pNode->right)) + 1;

	temp->height = max(height(temp->left), height(temp->right)) + 1;
//	printf("Finished rightRotate\n");
	return temp;
}


void in_order_tree_print(Node* tree)
{
    Node* temp_node = (Node*)tree;

    if (temp_node != NULL)
    {
        in_order_tree_print(tree->left);
        printf("%5d: %s : %s\n", generic_vector_get_size(temp_node->index), my_string_c_str(temp_node->key), my_string_c_str(generic_vector_at(temp_node->index, 0)));

        in_order_tree_print(tree->right);
    }
}

	
