#  This is a test change...
#
#
#  GIT
#
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE *TREE;
struct NODE {
   int data;
   int key;
   TREE leftChild, rightChild;
};


void inorder(TREE t)
{
   if (t != NULL) {
      inorder(t->leftChild);
      printf("Key=%d, data=%d.\n", t->key, t->data);
      inorder(t->rightChild);
   }
}

TREE insert(int key, int data, TREE t)
{
   if (t == NULL) {
      printf("Inserting new node, key=%d, data=%d.\n",key, data);
      t = (TREE) malloc(sizeof(struct NODE));
      t->data = data;
      t->key = key;
      t->leftChild = NULL;
      t->rightChild = NULL;
    }
    else if (key < t->key) {
      printf("Following Left\n");
      t->leftChild = insert(key, data, t->leftChild);
    }
    else if (key > t->key) {
      printf("Following Right\n");
      t->rightChild = insert(key, data, t->rightChild);
    }
    return t;
}

int main()
{
   TREE tree;

   tree=NULL;

   tree = insert(20,5,tree);
   tree = insert(10,4,tree);
   tree = insert(5,2,tree);
   tree = insert(6,1,tree);
   tree = insert(11,9,tree);
   tree = insert(30,8,tree);
   tree = insert(25,7,tree);
   tree = insert(35,6,tree);
   tree = insert(27,3,tree);
   printf("Inorder Algorithm.\n");
   inorder(tree);
   return 0;
}

