#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARAAY_H

#include "my_string.h"
#include "generic_vector.h"

struct node;
typedef struct node Node;

struct node {
	 int height;
	 Node* left;
	 Node* right;
	 MY_STRING key;
       	 GENERIC_VECTOR index;
};

struct tree {	
        Node* root;
};


typedef struct tree Tree;




Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);

Status tree_insert(Tree* tree, MY_STRING key, MY_STRING word);

Status insert(Node** node, MY_STRING key, MY_STRING word);

Tree* tree_init_default(void);

int max(int a, int b);

int getBalance(Node** pNode);

int height(Node* pNode);


Node* leftRotate(Node* pNode);

Node* rightRotate(Node* pNode);

void in_order_tree_print(Node* tree);

void node_destroy(Node* root);

void Tree_destroy(Tree** phTree);

void swapVector(GENERIC_VECTOR* vector_one, GENERIC_VECTOR* vector_two);

void in_order_find_max(Node* pNode, Node** ppTempNode ,int* pSize);

GENERIC_VECTOR* find_max_list_in_tree(Tree** pTree);

#endif
