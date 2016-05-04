#include <apue.h>
#include <myerr.h>

int main()
{
	struct stat buf;
	if(lstat("test_chmod.txt", &buf)  < 0)
	{
		err_sys("lstat error for test_chmod.txt\n");
	}
	
	if(chmod("test_chmod.txt", (buf.st_mode & ~S_IWOTH) | S_ISGID ) < 0)
	{
		err_sys("chmod error for test_chmod.txt\n");
	}
	return 0;
}
