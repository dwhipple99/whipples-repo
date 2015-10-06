
/* This is the selection sort code from page 31 of */
/* Foundations of Computer Science, C Edition for  */
/* CS520 @ Drexel                                  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************************** QUICK SORT FUNCTIONS *********************************/
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
/*************************************** QUICK SORT FUNCTIONS *********************************/

/*************************************** SELECTION SORT FUNCTIONS *********************************/
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

void SelectionSort(int A[], int n)
{
   int i, j, small, temp;

   for (i=0; i < n-1; i++) {
      /* set small to the index of the first occurance */
      /* of the smallest element remaining */
      small = i;
     
      for (j = i+1; j < n; j++) 
          if (A[j] < A[small])
             small = j;
      /* when we reach here, small is the index of */
      /* the first smallest element in A[i..n-1];  */
      /* we now exchange A[small] with A[i]        */
      temp = A[small];
      A[small] = A[i];
      A[i] = temp;
   }
}
/*************************************** SELECTION SORT FUNCTIONS *********************************/
/*************************************** HEAP SORT FUNCTIONS *********************************/
int compare(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

void heap_sort(int a[], compare_func func_pointer, int len)
{
    /* heap sort */
    int half;
    int parents;
 
    if (len <= 1)
        return;
    half = len >> 1;
    for (parents = half; parents >= 1; --parents)
    {
        int tmp;
        int level = 0;
        int child;
 
        child = parents;
        /* bottom-up downheap */
 
        /* leaf-search for largest child path */
        while (child <= half)
        {
            ++level;
            child += child;
            if ((child < len) &&  ((*func_pointer)(a[child], a[child - 1]) > 0))
                ++child;
        }
        /* bottom-up-search for rotation point */
        tmp = a[parents - 1];
        for (;;)
        {
            if (parents == child)
                break;
            if ((*func_pointer)(tmp, a[child - 1]) <= 0)
                break;
            child >>= 1;
            --level;
        }
        /* rotate nodes from parents to rotation point */
        for (; level > 0; --level)
        {
            a[(child >> level) - 1] =
                a[(child >> (level - 1)) - 1];
        }
        a[child - 1] = tmp;
    }
 
    --len;
    do
    {
        int tmp;
        int level = 0;
        int child;
 
        /* move max element to back of array */
        tmp = a[len];
        a[len] = a[0];
        a[0] = tmp;
 
        child = parents = 1;
        half = len >> 1;
 
        /* bottom-up downheap */
 
        /* leaf-search for largest child path */
        while (child <= half)
        {
            ++level;
            child += child;
            if ((child < len) && ((*func_pointer)(a[child], a[child - 1]) > 0))
                ++child;
        }
        /* bottom-up-search for rotation point */
        for (;;)
        {
            if (parents == child)
                break;
            if ((*func_pointer)(tmp, a[child - 1]) <= 0)
                break;
            child >>= 1;
            --level;
        }
        /* rotate nodes from parents to rotation point */
        for (; level > 0; --level)
        {
            a[(child >> level) - 1] =
                a[(child >> (level - 1)) - 1];
        }
        a[child - 1] = tmp;
    }
    while (--len >= 1);
}

/*************************************** HEAP SORT FUNCTIONS *********************************/

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

   system("clear");

   printf("Array before sorting:");
   for (i=0;i<n;i++) {
      printf(" %d,",B[i]);
   }
   printf("\n\nArray after sorting:");
   for (i=0;i<n;i++) {
      printf(" %d,",A[i]);
   }
   printf("\n\n");
   /*for (i=0;i<n;i++) {
      printf("Sorted A[%d]=%d    UnSorted A[%d]=%d\n",i,A[i],i,B[i]);
   }*/
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
   int tot = 10, max=100000;
   int A[max], B[max];
   int i, start_time, end_time, run_time, recursive_run_time, qs_run_time, heap_run_time;
   int input;
   int z;

   /* Let's increase sorted #'s by 10* and see how sort does */

   while (tot<max) {

      fill_arrays(A, B, tot);
    
      /* This is the standard Selection Sort */
      start_time = clock();
      SelectionSort(A,tot);
      end_time = clock();
      run_time = end_time - start_time;
      PrintArrays(A, B, tot);
      
      fill_arrays(A, B, tot);

      /* This is the Recursive Selection Sort on same # of elements */
      start_time = clock();
      Recursive_SelectionSort(A,0,tot);
      end_time = clock();
      recursive_run_time = end_time - start_time;
      PrintArrays(A, B, tot);

      fill_arrays(A, B, tot);

      /* This is the HEAP Sort on same # of elements */
      start_time = clock();
      heap_sort(A,compare,tot);
      end_time = clock();
      heap_run_time = end_time - start_time;

      fill_arrays(A, B, tot);

      /* This is the Recursive Selection Sort on same # of elements */
      start_time = clock();
      quicksort(A,0,tot-1);
      end_time = clock();
      qs_run_time = end_time - start_time;
      PrintArrays(A, B, tot);
      printf("Elements=%d, Run=%d, SS Time=%d cycles, Recursive SS=%d cycles, QuickSort=%d cycles, Heap Sort=%d cycles.\n",tot, z, run_time, recursive_run_time, qs_run_time, heap_run_time);
      tot = tot*10;

      scanf("%d", &input);
   }
}

