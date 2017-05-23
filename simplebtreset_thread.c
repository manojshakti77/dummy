#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<pthread.h>

typedef struct {
//	unsigned char pkt_type;
        unsigned char opcode_msb;         /* OCF & OGF */
        unsigned char opcode_lsb;         /* OCF & OGF */
        unsigned char  plen;
}hci_command_reset;

typedef struct
{
//    unsigned char pkt_type;
    unsigned char opcode_msb;         /* OCF & OGF */
    unsigned char opcode_lsb;         /* OCF & OGF */
    unsigned char plen;
    unsigned char scan_param;
}hci_set_scan;


void *thread_fun(void *arg)
{
    int retval;
    int i;
    char buf[64];
    int sfd = open("/dev/bluetooth0",O_RDONLY);
//  rewind(sfd);
    while(1)
    {
        while ((retval = read(sfd,buf,sizeof(buf))) < 0)
        {
        if (retval <= 0)
            continue;
        break;
        }
        printf("EVENT RECEIVED...:\n");
        for(i=0;i<retval;i++)
            printf("0x%02X ",buf[i]);
        printf("\n");
  //      hci_rec_event(buf);
    }
}

int main(void)
{
//	int fd;
	hci_command_reset cmd_reset;
    hci_set_scan set_scan;
	char buf[64];
	FILE *fd;
	int size;
	pthread_t tid;

	pthread_create(&tid,NULL,thread_fun,NULL);
	
	fd = fopen("/dev/bluetooth0","r+");
	if(fd == 0)
	{
		perror("open");
		return -1;
	}

//	cmd_reset.pkt_type= 0x01;
	cmd_reset.opcode_lsb = 0x0C;
	cmd_reset.opcode_msb = 0x03;
	cmd_reset.plen = 0x00;

	printf("nfenv...1\n");
	
	if(!(fwrite(&cmd_reset,sizeof(char ),sizeof(cmd_reset),fd) > 0))
	{
		perror("write");
		return -1;
	}
	
#if 0
	printf("nfenv...2\n");
	if(!((size = fread(buf,sizeof(char ),sizeof(buf),fd)) > 0))
	{
		perror("read");
		return -1;
	}
	printf("Received data....:");
	for(int i = 0;i < size;i++)
	{
		printf("0x%02X  ",buf[i]);
	}
	printf("\n");
#if 0
	    /*Setting the Device into Discoverable Mode*/
//    set_scan.pkt_type = 0x01;
    set_scan.opcode_lsb = 0x0C;
    set_scan.opcode_msb = 0x1A;
    set_scan.plen = 0x01;
    set_scan.scan_param = 0x03;
	if(!(fwrite(&set_scan,sizeof(char ),sizeof(set_scan),fd) > 0))
	{
		perror("write");
		return -1;
	}
    if(!((size = fread(buf,sizeof(char ),sizeof(buf),fd)) > 0))
    {
        perror("read");
        return -1;
    }
    printf("Received data....:");
    for(int i = 0;i < size;i++)
    {
        printf("0x%02X  ",buf[i]);
    }
    printf("\n");
	fclose(fd);
#endif
#endif
	while(1);
	return 0;
}
