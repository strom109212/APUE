#include "apue.h"
#include "myerr.h"
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define BUFFSIZE 3

int main()
{
	int n;
	char buf[BUFFSIZE] = {0};
	int fd1, fd2;
	clock_t start_time, finish_time;
	if((fd1 = open("file.hole", O_RDONLY)) < 0)
	{
		err_sys("open file.hole error");
	}
	
	//lseek file.hole to 10M
	if(lseek(fd1, 10*1024*1024, SEEK_CUR) == -1)
	{
		err_sys("lseek error");	
	}
	if((fd2 = open("1.txt", O_WRONLY)) < 0)
	{
		err_sys("open 1.txt error");
	}

	start_time = clock();
	while((n = read(fd1, buf, BUFFSIZE)) > 0)
		if(write(fd2, buf, n) != n)
			{
				err_sys("write error");
			}
	if(n < 0)
	{
		err_sys("read error");
	}
	finish_time = clock();
	double sec =(double)(finish_time - start_time)/CLOCKS_PER_SEC;
	printf("copy 10M used time %f sec\n", sec);
		
	return 0;
}
