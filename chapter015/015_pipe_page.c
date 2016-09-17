/*使用管道，将读出的文件内容直接传递给分页程序*/
#include <apue.h>
#include "sys/wait.h"

#define DEF_PAGER "/bin/more"

int main(int argc, char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char *pager, *argv0;
    char line[MAXLINE];
    FILE *fp;

    if(argc != 2)
    {
        printf("using ./a.out filename");
        return -1;
    }
    if(pipe(fd) < 0)
    {
        printf("pipe error");
        return -1;
    }

    if((fp = fopen(argv[1],"r")) == NULL)
    {
        printf("fopen error");
        return -1;
    }

    if((pid = fork()) < 0)
    {
        printf("fork error");
        return -1;
    }

    if(pid > 0)
    {
       close(fd[0]);
       while(fgets(line, MAXLINE, fp) != NULL)
       {
            n = strlen(line);
            write(fd[1], line, n);
       }
       close(fd[1]);

       if(waitpid(pid, NULL, 0) < 0)
       {
            printf("waitpid error");
            return -1;
       }
    }
    else
    {
        close(fd[1]);
        if(fd[0] != STDIN_FILENO)
        {
            if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
            {
                printf("dup2 error");
                return -1;
            }
            close(fd[0]);
        }

        if((pager = getenv("PAGER")) == NULL)
        {
            pager = DEF_PAGER;
        }

        if((argv0 = strrchr(pager,'/')) != NULL)
        {
            argv0++;
        }
        else
        {
            argv0 = pager;
        }

        if(execl(pager, argv0, (char *)NULL) < 0)
        {
            printf("excel error");
            return -1;
        }
        
    }
    return 0;
    
}
