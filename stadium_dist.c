#include <stdio.h>

#define MAX_NUM_COLUMNS	30

/* A simple atoi() function */

int my_atoi(char *str)
{
	int loop_cnt;
	int res = 0;
  
	/* Iterate through all characters of input string 
	 * and update result for only valid integers
	 */
	for (loop_cnt = 0; str[loop_cnt] != '\0'; loop_cnt++)
		res = res*10 + str[loop_cnt] - '0';
	
	return res;
}

int main(int argc, char **argv)
{
	if (argc == 1 || argc > 30) {
		if (argc == 1) 
			printf("Usage: %s Please enter valid column height \n", argv[0]);
		else 
			printf("Usage: %s Maximum columns exceeded\n", argv[0]);

		return -1;
	}
  
	unsigned int seat1 = 1;
	unsigned int seat2 = 3;
	unsigned int dist1 = 0;
	unsigned int dist2 = 0;
	
	unsigned int ou_loop_cnt;
	unsigned int in_loop_cnt;
	unsigned int temp_dist1 = 0;
	unsigned int temp_dist2 = 0;
  
	unsigned int temp = 0;
	unsigned int val = 0;
  

	for (ou_loop_cnt = 1; ou_loop_cnt < argc; ou_loop_cnt++) {
    		for (in_loop_cnt = ou_loop_cnt+1; in_loop_cnt < argc; in_loop_cnt++) {
	  		temp = (my_atoi(argv[ou_loop_cnt]) + my_atoi(argv[in_loop_cnt])); /* temp = argv[ou_loop_cnt] + argv[in_loop_cnt]; */
      			if (temp == val) { /* If same Height of the TREES */
				temp_dist1 = seat2 - seat1;
				temp_dist2 = ((seat1 - 1) + (argc - seat2));
		
				dist1 = in_loop_cnt - ou_loop_cnt;
				dist2 = ((ou_loop_cnt - 1) + (argc - in_loop_cnt));
		
				if (dist1 < temp_dist1) {
					if(dist1 < temp_dist2) {
						val = temp;
						seat1 = ou_loop_cnt;
						seat2 = in_loop_cnt;
					}
				}
				if (dist2 < temp_dist1) {
					if(dist2 < temp_dist2) {
						val = temp;
						seat1 = ou_loop_cnt;
						seat2 = in_loop_cnt;
					}
				}
			} else if (temp > val) { /*If more Height tree is found*/
				val = temp;
				seat1 = ou_loop_cnt;
				seat2 = in_loop_cnt;
			}
    		}
  	}

	temp_dist1 = seat2 - seat1;
	temp_dist2 = ((seat1 - 1) + (argc - seat2));
  
	printf("column1 = %u\ncolumn2 = %u\nDistance = %u\n", seat1, seat2, (val + (temp_dist1 < temp_dist2 ? temp_dist1 : temp_dist2)));

	return 0;
}
