/*
lseek 函数执行成功后返回当前的偏移量，如果失败了返回-1
可以利用这个特性，来测试一个文件是否是可设置偏移量。
如果文件描述符指向一个管道、套接字、标准输入等，返回-1 
*/
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
