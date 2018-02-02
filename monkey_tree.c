#include <stdio.h>

#define MAX_NUM_TREES   30

// A simple atoi() function
int my_atoi(char *str)
{
    int res = 0; // Initialize result
  
    // Iterate through all characters of input string and
    // update result
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
  
    // return result.
    return res;
}

int main(int argc, char **argv) {
  
  unsigned int i;
  unsigned int j;
  
  unsigned int d1 = 0;
  unsigned int d2 = 0;
  
  unsigned int td1 = 0;
  unsigned int td2 = 0;
  
  unsigned int temp = 0;
  unsigned int val = 0;
  
  unsigned int t1 = 1;
  unsigned int t2 = 3;

  if((argc - 1) < MAX_NUM_TREES)
  {
	printf("Num Max Trees exceeded the Limit\n");
	return -1;
  }
  for(i = 1;i < argc;i++)
  {
    for(int j = i+1;j<argc;j++)
    {
      /*temp = argv[i] + argv[j];*/
	  temp = (my_atoi(argv[i]) + my_atoi(argv[j]));
      printf("%d ",temp);
	  /*If same Height of the TREES*/
      if(temp == val)
      {
        td1 = t2 - t1;
		td2 = ((t1 - 1) + (argc - t2));
		
		d1 = j - i;
		d2 = ((i - 1) + (argc - j));
		
		if(d1 < td1)
		{
			if(d1 < td2)
			{
				val = temp;
				t1 = i;
				t2 = j;
			}
		}
		if(d2 < td1)
		{
			if(d2 < td2)
			{
				val = temp;
				t1 = i;
				t2 = j;
			}
		}
      }
	  /*If more Height tree is found*/
	  else if(temp > val)
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
