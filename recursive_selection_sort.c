
/* This is the selection sort code from page 31 of */
/* Foundations of Computer Science, C Edition for  */
/* CS520 @ Drexel                                  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Recursive_SelectionSort(int A[], int i, int n)
{
   int j, small, temp;
   if (i < n-1) { /* basis is when i = n - 1, in which case */
      /* the function returns without changing A */
      /* induction follows */
      small = i;
      for (j=i+1;j<n;j++)
         if (A[j] < A[small])
            small = j;
      temp = A[small];
      A[small] = A[i];
      A[i] = temp;
      Recursive_SelectionSort(A, i+1, n);
   }
}

void PrintArray (int A[],int n)
{
   int i=0;

   for (i=0;i<5;i++) {
      printf("A[%d]=%d\n",i,A[i]);
   }
}

void PrintArrays (int A[], int B[],int n)
{
   int i=0;

   for (i=0;i<n;i++) {
      printf("Sorted A[%d]=%d    UnSorted A[%d]=%d\n",i,A[i],i,B[i]);
   }
}

void fill_arrays(int A[], int B[], int tot)
{
   int i, n;

   /* Initialize the random seed */
   srand (time(NULL));

   for (i=0;i<tot;i++) {
       n = rand() % (tot * 100);
       A[i]=n;
       B[i]=n;
   }
}

int main()
{
   int tot = 10, max=1000000;
   int A[max], B[max];
   int i, start_time, end_time, run_time;
   int z;

   /* Let's increase sorted #'s by 10* and see how sort does */

   while (tot<max) {

      fill_arrays(A, B, tot);

      /* PrintArray(A, tot); */
      /* start_time = time(NULL); */
      start_time = clock();
      Recursive_SelectionSort(A,0, tot);
      /*end_time = time(NULL);*/
      end_time = clock();
      /* PrintArray(A, tot); */
      /*PrintArrays(A,B, tot);*/
      run_time = end_time - start_time;
      printf("Elements=%d, Run=%d, Start Clock=%d, End Clock=%d, Run Time=%d clock cycles.\n",tot, z, start_time,end_time, run_time);
      
      tot = tot*10;
   }
}

