/*APUE3-2 创建一个具有空洞的文件*/
/*
查看文件的大小 ls -l file.file
查看文件的内容 od -c file.hole 
*/
#include "apue.h"
#include <fcntl.h>
#include "myerr.h"

char buf1[] = "abcdefg";
char buf2[] = "ABCDEFG";

int main()
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		err_sys("create error");
	}
	if(write(fd, buf1, 4) != 4)
	{
		err_sys("buf1 write error");
	}
	if(lseek(fd, 1000, SEEK_SET) == -1)
	{	
		err_sys("lseek error");
	}
	
	if(write(fd, buf2, 4) != 4)
	{
		err_sys("write buf2 error");
	}
	exit(0);	
}
