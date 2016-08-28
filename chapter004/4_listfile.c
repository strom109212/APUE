/*
# list file and filetype
# gcc -g listfile.c -o listfile
# ./listfile      ---list files of current dir
# ./listfile dir ---list filse of dir
*/


#include "apue.h"
#include "dirent.h"

char *fullpath = NULL;
unsigned int pathlen = 0;
static void err_print(const char* str);
static int procpath();

int main(int argc,char* argv[])
{
    if (argc > 3)
    {
        err_print("too many argv");
        return -1;
    }
    else if(argc == 1)
    {
        argv[1] = ".";
    }

    if (pathlen < strlen(argv[1]))
    {
        pathlen = strlen(argv[1])*2 +256;
        fullpath = realloc(fullpath,pathlen);
        if (fullpath == NULL)
        {
            err_print("realoc fail");
            exit(1);
        }
    }
    strcpy(fullpath, argv[1]);
    (void)procpath();
    return 0;
}

static int procpath()
{
    struct stat     statbuf;
    struct dirent   *dirp;
    DIR             *dp;
    int n;
    
    if (lstat(fullpath, &statbuf) <0)
    {
        err_print("lstat fail");
        return -1;
    }
    if (S_ISDIR(statbuf.st_mode) == 0) /*not dir*/
    {
        printf("%s\n", fullpath);
        return 0;
    }
    n = strlen(fullpath);
    if (n + 256 + 2 > pathlen)
    {
        pathlen *=2;
        fullpath = realloc(fullpath,pathlen);
        if(fullpath == NULL)
        {
            err_print("realoc fail");
            exit(1);
        }
    }
    fullpath[n++] = '/';
    fullpath[n] = 0;

    if ((dp = opendir(fullpath)) == NULL)
    {
        return 0;
    }
    
    while((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(&fullpath[n], dirp->d_name);
        (void)procpath();
    }

    fullpath[n-1] = 0;
    closedir(dp);
    return 0;
    
}

void static err_print(const char* str)
{
    printf("ERROR: %s,file:%s,line:%d",str,__FILE__, __LINE__);
}




