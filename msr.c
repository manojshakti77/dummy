#include<stdio.h>
#include<unistd.h>
#include<asm/msr.h>
#include<linux/timex.h>
int main(void)
{
	unsigned long int start,end;
//	rdtscl(start);
	start = get_cycles();
	sleep(1);
//	rdtscl(end);
	end = get_cycles();
	printf("%lu\n",(end-start));
	return 0;
}
