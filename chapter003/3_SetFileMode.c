#include <fcntl.h>
#include <apue.h>
#include <myerr.h>

void set_fl(int fd, int flags);
int main()
{
	int fd;
	int flags;
	if((fd = open("1.txt", O_RDONLY)) < 0)	
	{
		err_sys("open error\n");
	}
	
	flags = O_WRONLY;
	set_fl(fd, flags);
	return;
}

void set_fl(int fd, int flage)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		err_sys("fcntl F_GETFL error\n");
	}
	printf("origin mode value : %x\n", val);

	val |= flage;
	if(fcntl(fd, F_SETFL, val) < 0)
	{
		err_sys("fcntl F_SETFL error\n");
	}
	printf("current mode value : %x\n", val);
	return;
}

