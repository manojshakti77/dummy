#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<curses.h>

int main(void)
{
  int pid;
  FILE *fd;

  if(!fork())
  {
    char str[64] = "Logging info.....manoj\n";
    printf("PID....%d\n",getpid());
    if(setsid() < 0)
    {
      perror("setsid");
      return 0;
    }
    chdir("/");
    close(0);//STD_IN
    close(1);//STD_OUT
    close(2);//STD_ERRNO

    fd = open("mylog.txt",O_RDWR);
    while(1)
    {
      write(fd,str,sizeof(str));
      sleep(1);
    }
    fclose(fd);
    return 0;
  }

}
