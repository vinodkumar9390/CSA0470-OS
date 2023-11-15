#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/stat.h> 
int main() 
{ 
	int fd, nbytes; 
	char buffer[1024]; 
	 printf("m.vinodkumar\n");
    printf("192111625\n");    
	fd = open("file.txt", O_RDONLY); 
	if (fd == -1) { 
		perror("open"); 
		return 1; 
	} 
	nbytes = read(fd, buffer, sizeof(buffer)); 
	if (nbytes == -1) { 
		perror("read"); 
		return 1; 
	} 
	printf("Read %d bytes: %s\n", nbytes, buffer); 
	if (close(fd) == -1) { 
		perror("close"); 
		return 1; 
	} 
	return 0; 
}
