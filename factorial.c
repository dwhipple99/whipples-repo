#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double factorial(double n)
{
  if (n<=1) {
    /*printf("Calling Factorial for basis, %d\n", n);*/
    return 1; /* basis */
  }
  else {
    /*printf("Calling Factorial for %d\n", n);*/
    return n * factorial(n-1); /* induction */
  }
}

int main()
{
   double z=4, answer,y;

   for (z=1;z<30;z++) {
      answer = factorial(z);
      printf("Computing Factorial of %f=%f,",z, answer);
      printf("(n-1) factorial=%f, ",factorial(z-1));
      y = factorial(z)/z;
      printf("factorial of N/N=%f.\n",y);
   }
}

