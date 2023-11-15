#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{   
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
	 printf("m.vinodkumar\n");
    printf("192111625\n");    
    printf("fd = %d\n", fd);     
    if (fd ==-1)
    {       
        printf("Error Number % d\n", errno);
        perror("Program");                
    }
    return 0;
}
