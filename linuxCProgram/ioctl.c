/*************************************************************************
  > File Name: ioctl.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年10月09日 星期一 17时42分07秒
 ************************************************************************/
#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

static void usage()
{
	printf("usage : ipconfig interface \n");
	exit(0);
}

int main(int argc,char **argv)
{
	struct sockaddr_in *addr;
	struct ifreq ifr;
	char *name,*address;
	int sockfd;

	if(argc != 2) 
		usage();
	else  
		name = argv[1];

	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	strncpy(ifr.ifr_name,name,IFNAMSIZ-1);

	if(ioctl(sockfd,SIOCGIFADDR,&ifr) == -1)
		perror("ioctl error"),
			exit(1);

	addr = (struct sockaddr_in *)&(ifr.ifr_addr);
	address = inet_ntoa(addr->sin_addr);
	printf("inet addr: %s ",address);

	if(ioctl(sockfd,SIOCGIFBRDADDR,&ifr) == -1)
		perror("ioctl error"),exit(1);

	addr = (struct sockaddr_in *)&ifr.ifr_broadaddr;
	address = inet_ntoa(addr->sin_addr);
	printf("broad addr: %s ",address);

	if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
		perror("ioctl error"),exit(1);

	addr = (struct sockaddr_in *)&ifr.ifr_addr;
	address = inet_ntoa(addr->sin_addr);
	printf("inet mask: %s ",address);
	printf("\n");
	exit(0);
}
#endif

#if 0


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define  BASE_VALUE 257
int main(int argc,char *argv[])
{
	int mixer_fd=0;
	char *names[SOUND_MIXER_NRDEVICES]=SOUND_DEVICE_LABELS;
	int value,i;
	printf("\nusage:%s dev_no.[0..24] value[0..100]\n\n",argv[0]);
	printf("eg. %s 0 100\n",argv[0]);
	printf("will change the volume to MAX volume.\n\n");
	printf("The dev_no. are as below:\n");
	for (i=0;i<SOUND_MIXER_NRDEVICES;i++)
	{
		if (i%3==0) printf("\n");
		printf("%s:%d\t\t",names[i],i);
	}
	printf("\n\n");
	if (argc<3)  exit(1);
	if ((mixer_fd = open("/dev/mixer",O_RDWR)))
	{
		printf("Mixer opened successfully,working...\n");
		value=BASE_VALUE*atoi(argv[2]);
		if (ioctl(mixer_fd,MIXER_WRITE(atoi(argv[1])),&value)==0)
			printf("successfully.....");
		else
			printf("unsuccessfully.....");

		printf("done.\n");
	}
	else
		printf("can't open /dev/mixer error....\n");
	exit(0);
}
#endif
