/*******************************************************************************
* Name : BST.cpp
* Author : Yuvan Rengifo
* Version : 1.0
* Date : April 30, 2023
* Description : inorder transversal of BST
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
******************************************************************************/
#include<iostream>
using namespace std;
class Vertex{ // class vertex with the required properties to be in a binary tree
public:
Vertex* leftchild;
Vertex* rightchild;
int key;
Vertex(int val){
key = val;
leftchild = NULL;
rightchild = NULL;
}
};
class BST{ //class for binary search tree that utilizes the vertex class
public:
Vertex* root = NULL;
void BST_Insert(int key){
Vertex* newVertex = new Vertex(key);
// implement the insert function for Binary search tree insert operation
        if(root == NULL){
            root = newVertex;
        }
        else{
            Vertex* current = root;
            Vertex* parent = NULL;
            while(current != NULL){
                parent = current;
                if(key < current->key){
                    current = current->leftchild;
                }
                else{
                    current = current->rightchild;
                }
            }
            if(key < parent->key){
                parent->leftchild = newVertex;
            }
            else{
                parent->rightchild = newVertex;
            }
        }
    }
void BST_Inorder_Traversal (Vertex* v){
// implement inorder traversal of the binary search tree to print the inorder traversal output
	if(v != NULL){
	            BST_Inorder_Traversal(v->leftchild);
	            cout << v->key << " ";
	            BST_Inorder_Traversal(v->rightchild);
	        }
}
void BST_Tree_Sort(){
BST_Inorder_Traversal(root);
}
};
int main(){
BST B1;
int array[100];
for(int i = 0 ; i < 100 ; i++){ // sample for generating random array
array[i] = rand()%1000;
}
for (int i = 0; i < 100; i++) {
B1.BST_Insert(array[i]); // inserting the array elements to the BST
}
B1.BST_Tree_Sort(); // printing the elements of the array in the sorted way
return 0;
}
