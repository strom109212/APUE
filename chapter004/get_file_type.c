/*
gcc -g get_file_type.c -o get_file_type.elf

./get_file_type.elf /etc/passwd /etc /dev/log /dev/tty /var/lib/oprofile/opd_pipe /dev/rs0 /dev/cdrom
*/
#include <apue.h>
#include <myerr.h>

int main(int argc, char* argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	for(i = 1; i< argc; i++)
	{
		printf("%s : ", argv[i]);
		if(lstat(argv[i], &buf) < 0)
		{
			err_ret("lstat error");
			continue;
		}
		
		if(S_ISREG(buf.st_mode))
			printf("regular\n");
		else if(S_ISDIR(buf.st_mode))
			printf("directory\n");	
		else if(S_ISCHR(buf.st_mode))
			printf("character special\n");
		else if(S_ISBLK(buf.st_mode))
			printf("block special\n");
		else if(S_ISFIFO(buf.st_mode))
			printf("fifo\n");
		else if(S_ISLNK(buf.st_mode))
			printf("symbolic link\n");
		else if(S_ISSOCK(buf.st_mode))
			printf("socket\n");
		else
			printf("unknown file type\n");
	}
	return 0;
}
