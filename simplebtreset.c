#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

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


int main(void)
{
//	int fd;
	hci_command_reset cmd_reset;
    hci_set_scan set_scan;
	char buf[64];
	FILE *fd;
	int size;
	
	fd = fopen("/dev/bluetooth0","r+");
	if(fd == 0)
	{
		perror("open");
		return -1;
	}

#if 1
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
	return 0;
}
