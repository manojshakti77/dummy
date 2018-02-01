#include <stdio.h>
#include <stdlib.h>
int main(void) {
  
  int argv[] = {0,4,2,3,4};
  int argc = 5;
  unsigned int i;
  unsigned int j;
  unsigned int temp;
  unsigned int val = 0;
  unsigned int t1;
  unsigned int t2;
  
  for(i = 1;i < argc;i++)
  {
    for(int j = i+1;j<argc;j++)
    {
      temp = argv[i] + argv[j];
      printf("%d ",temp);
      if((temp > val) && ((j-i) < (t1-t2)))
      {
        val = temp;
        t1 = i;
        t2 = j;
      }
    }
  }
  printf("\nval = %d, T1 = %d, T2= %d\n",val,t1,t2);
  return 0;
}