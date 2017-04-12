#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
	unsigned char pkt_type;
        unsigned char opcode_msb;         /* OCF & OGF */
        unsigned char opcode_lsb;         /* OCF & OGF */
        unsigned char  plen;
}hci_command_reset;

int main(void)
{
	int fd;
	hci_command_reset cmd_reset;
	char buf[64];
	
	fd = open("/dev/bluetooth0",O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	
	cmd_reset.pkt_type= 0x01;
	cmd_reset.opcode_lsb = 0x0C;
	cmd_reset.opcode_msb = 0x03;
	cmd_reset.plen = 0x00;
	
	if(write(fd,&cmd_reset,sizeof(cmd_reset) < 0)
	{
		perror("write");
		return -1;
	}
	
	if(read(fd,buf,sizeof(buf) < 0)
	{
		perror("read");
		return -1;
	}
	
	for(int i = 0;i < sizeof(buf);i++)
	{
		printf("0x%02X  ",buf[i]);
	}
	printf("\n");
	return 0;
}