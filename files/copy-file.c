#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/* Information
*  
* O_RDONLY, O_WRONLY, O_RDWR - mandatory 
* O_CREAT, O_APPEND, O_TRUNC, O_EXCL - optional
*
*/

#define ERR(fd, string) if(fd < 0) { \
				perror(string); \
				exit(0);\
			}

int main(int argc, char **argv)
{
	if(argc != 3) {
		puts("Exception: <a.out> <source-file> <dest-file>");
		exit(0);
	}

	int fd_src, fd_dest;
	char buf;

	//bzero(buf, sizeof(buf));

	fd_src = open( argv[1], O_RDONLY, 0664);
	ERR(fd_src, "open");

	fd_dest = open(argv[2], O_WRONLY, 0664);
	ERR(fd_src, "open");

	while( read(fd_src, &buf, 1) > 0 ) {
		if(write(fd_dest, &buf, 1) < 0) {
			perror("write");
			exit(0);
		}
	}

	puts("File copyied ...");

	return 0;
}