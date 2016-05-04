/*create file with a hole*/

#include "apue.h"
#include <fcntl.h>
#include "myerr.h"

char buf1[] = "abcdefg";
char buf2[] = "ABCDEFG";

int main()
{
	int fd;
    char buf[10000] = {'a'};
    //create a file with a hole
	if((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		err_sys("create error");
	}
	if(write(fd, buf1, 4) != 4)
	{
		err_sys("buf1 write error");
	}
	if(lseek(fd, 10000, SEEK_SET) == -1)
	{	
		err_sys("lseek error");
	}
	
	if(write(fd, buf2, 4) != 4)
	{
		err_sys("write buf2 error");
	}
    close(fd);
    
	exit(0);	
}
