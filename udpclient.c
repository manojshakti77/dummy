/************* UDP CLIENT CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int flag,alarm_flag,ack;

struct st
{
	int seq_num;
	char buf[100];
}

thread()
{
    /*Receive message from server*/
                nBytes = recvfrom(clientSocket,buffer,1024,0,NULL, NULL);

    printf("Received from server: %s\n",buffer);
	if(ack == buffer[0])
	{
		if(ack == 0)
			ack = 1;
		else
			ack = 0;
		flag = 1;
	}
}
alarm()
{
	if(flag == 1)
		return ;
	else
	{
		if(ack == 0)
			ack = 1;
		else
			ack = 0;
		alarm_flag = 1;
	}
	return;
}
int main(){
  int clientSocket, portNum, nBytes;
  struct st st1;
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;
  flag = 1;
  signal();
  pthread_create();//Thread for reading

  while(1){
	if(flag == 1)
	{
	flag=0;
    fgets(st1.buffer,1024,stdin);
	st1.seq_num = ack;
    nBytes = strlen(buffer) + 1;
    /*Send message to server*/
    sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
	alarm(2);
	while(flag == 0 || alarm_flag == 0);
	}
	if(alarm_flag == 1)
	{
		alarm_flag = 0;
		sendto(buffer);
		while(flag == 0 || alarm_flag == 0);
	}
  }

  return 0;
}