
#include <stdio.h>
#include <unistd.h>
#include <apue.h>
#include <myerr.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main()

{
	int fd;
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	{
		printf("stdin cannot seek\n");	
	}
	else
	{
		printf("stdin can seek\n");
	}
	
	if((fd = open("1.txt", O_RDWR | O_CREAT | O_TRUNC, RWRWRW)) < 0)
	{
		printf("open error\n");
	}	
	off_t currpos;
	currpos = lseek(fd, 0, SEEK_CUR);
	if(currpos == -1)
	{
		printf("1.txt cannot seek\n");
	}
	else 
	{
		printf("1.txt can seek\n");
	}
	
	if(write(fd, "abcdef", 6) != 6)
	{
		printf("write error");
	}
	
	currpos = lseek(fd, 0, SEEK_CUR);
	if(currpos == -1)
	{
		printf("1.txt cannot seek after write\n");
	}
	else 
	{
		printf("1.txt can seek after write\n");
	}
	return 0;
	
}	
