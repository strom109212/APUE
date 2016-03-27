/*use fcntl get file mode through file_descriptor*/
/*
gcc -g myGetFileMode.c -o myGetFileMode.elf
./myGetFileMode.elf  1
./myGetFileMode.elf  0 < /dev/tty
./myGetFileMode.elf  2 2>>1.txt
./myGetFileMode.elf  5 5<>1.txt

>	重定向输出，如果文件不存在，就创建文件，如果文件存在，就将文件清空
>>	重定向输出，
<>	在描述符上读写打开1.txt
*/
#include <apue.h>
#include <myerr.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int val;
	if(argc != 2)
	{
		err_quit("usage:myGetFileMode file_descriptor");
	}
	
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)	
	{
		err_sys("fcntl error fd %d", atoi(argv[1]));
	}
	
	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read and write");
			break;
		default:
			printf("unknown access mode");
	}
	
	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblocking");
	if(val & O_SYNC)
		printf(", syschronous write");
	putchar('\n');
	return 0;
}
