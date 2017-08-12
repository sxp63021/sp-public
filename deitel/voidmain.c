#include <stdio.h>

int user_main(void) __attribute__ ((constructor));

int square(int i) { return i*i; }

int user_main() { 

  for (int i=0; i < 10; ++i) 
    printf("%d\n", square(i)); 

  return 0;
}

/* if i do int main_ret = user_main(); i am seeing compiler error
   "initializer element is not constant"

   Searching for a reson for this, i understood

   In C lang, the term constant refers to literal constants (like 1, 'a'
   0xFF and so on) and enum members. const-qualified objects (of any type)
   are not constants in C language terminology.
   
   even if you define const int N = 5; // N is not a constant in C lang
   // N would be a constant in C++, but not in C
   so if we do static int j = N; // we will see error in C lang
   error is "attempted to initialize a static object with a non-constant

   This is the reason in C lang, we predominantly use #define to declare
   named constants.
*/
//int main_ret = user_main();
int main_ret = 10;

void main() {

  printf("value of main_ret: %d\n", main_ret);

}

