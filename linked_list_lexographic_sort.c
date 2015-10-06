
/* This is the solution to Problem 2.2.3 on page 34 of Foundations of Computer Science for Drexel CS520 */
/* This takes two linked lists and returns TRUE if the first string precedes */
/* the second in lexographic in order.  It does this Recursively */

#include <stdio.h>

#define PI 3.14159
#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct CELL *LIST;
struct CELL {
   int element;
   LIST next;
};

#define DefCell(EltType, CellType, ListType)		\
typedef struct CellType *ListType;			\
struct CellType { 					\
   EltType element;					\
   ListType next;					\
}

/* returns true if the first string (represented by a linked list of characters precedes the second
   string lexographically */
BOOLEAN lexo_compare(LIST L1, LIST L2){
   printf("This is a recursive lexographic sort.\n");
   if (L2==NULL) return FALSE;
   if (L1==NULL) return TRUE;
   if (L1->element == L2->element)
      return lexo_compare(L1->next, L2->next);
   return (L1->element < L2->element);
  
}

LIST merge(LIST list1, LIST, list2)
{
   if (list1 == NULL) return list2;
   else if (list2 == NULL) return list1;
   else if (list1->element <= list2->element) {
       /* Here, neither list is empty, and the first list
          has the smaller first element.  The answer is the 
          first element of the first list followed by the 
          merge of the remaining elements. */
       list1->next = merge(list1->next, list2);
       return list1;
   }
   else { /* list2 has the smaller first element */
      list2->next=merge(list1, list2->next);
      return list2;
   }
}

LIST split(LIST list)
{
   LIST pSecondCell;

   if (list == NULL) return NULL;
   else if (list->next == NULL) return NULL;
   else { /* there are at least two cells */
      pSecondCell = list->next;
      list->next = pSecondCell->next;
      pSecondCell->next = split(pSecondCell->next);
      return pSecondCell;
   }
}

LIST MergeSort(LIST list)
{
   LIST SecondList;

   if (list == NULL) return NULL;
   else if (list->next == NULL) return list;
   else {
        /* at least two elements on the list */
        SecondList = split(list);
        /* Note that as a sde effect, half 
           the elements are removed from the list */
        return merge(MergeSort(list), MergeSort(SecondList));
   }
}

int main()
{
   LIST L1;
   LIST L2;
   BOOLEAN result;

   DefCell(char, CELL, LIST);

   L2 = NULL;
   L1 = NULL;

   result = lexo_compare(L1, L2);

   if (result) 
      printf("L1 is < L2, result is true.\n");
   else
      printf("L1 is NOT < L2, result is false.\n");

   return 0;
}
