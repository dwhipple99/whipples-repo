/* This is a function implementing deterministic automaton for a example
   from signal processing.  It is a bounce filter that might be used for 
   scanning a black/white image line by line and eliminating the imperfections. */

#include <stdio.h>

void bounce()
{
       char x;

        /* state a */
a:      putchar('0');
        x = getchar();
        if (x == '0') goto a; /* transition to state a */
        if (x == '1') goto b; /* transition to state b */
        goto finis;

        /* state b */
b:      putchar('0');
        x = getchar();
        if (x == '0') goto a; /* transition to state a */
        if (x == '1') goto c; /* transition to state c */
        goto finis;

        /* state c */
c:      putchar('1');
        x = getchar();
        if (x == '0') goto d; /* transition to state a */
        if (x == '1') goto c; /* transition to state b */
        goto finis;

        /* state d */
d:      putchar('1');
        x = getchar();
        if (x == '0') goto a; /* transition to state a */
        if (x == '1') goto c; /* transition to state b */
        goto finis;

finis:  ;
}

void main()
{
   bounce();
}
