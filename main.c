#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(){
    tBst BinarySearchTree = inicializeBST();
    int a1 = 10, a2 = 8, a3 = 15, a4 = 5, a5 = 9, a6 = 14, a7 = 17;
    BinarySearchTree = insert(a1, BinarySearchTree);
    BinarySearchTree = insert(a2, BinarySearchTree); 
    BinarySearchTree = insert(a3, BinarySearchTree);
    BinarySearchTree = insert(a4, BinarySearchTree);
    BinarySearchTree = insert(a5, BinarySearchTree); 
    BinarySearchTree = insert(a6, BinarySearchTree); 
    BinarySearchTree = insert(a7, BinarySearchTree); 
    printf("DFS:\n");
    printTree(BinarySearchTree, DFS);
    printf("\n");

    printf("DFS nao recursivo:\n");
    printTree(BinarySearchTree, non_recursiveDFS);
    printf("\n");

    printf("postOrder:\n");
    printTree(BinarySearchTree, postOrder);
    printf("\n");

    printf("InOrder:\n");
    printTree(BinarySearchTree, inOrder);
    printf("\n");

    printf("BFS:\n");
    printTree(BinarySearchTree, BFS);
    printf("\n");

    freeBST(BinarySearchTree);
}