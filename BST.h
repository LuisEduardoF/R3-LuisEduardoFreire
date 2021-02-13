#ifndef BST
#define BST
typedef struct bst *tBst;

int height(tBst);

tBst inicializeBST();
tBst insert(int, tBst);


void DFS(tBst);
void non_recursiveDFS(tBst);

void postOrder(tBst);
void non_recursivePostOrder(tBst);

void inOrder(tBst);
void non_recursiveInOrder(tBst);

void BFS(tBst);

void printTree(tBst, void f(tBst));

void freeBST(tBst);
#endif