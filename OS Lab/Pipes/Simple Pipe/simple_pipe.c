#include <stdio.h>
#include <unistd.h>
int main(){
	int pfd[2];
	int status;
	char message[10] = "Hello";
	char readmes[10];
	status = pipe(pfd);
	if(status == -1){
		printf("Unable to create pipe\n");
	}
	printf("Writing '%s'to the pipe\n",message);
	write(pfd[0],message,sizeof(message));
	printf("Reading from the pipe\n");
	read(pfd[1],readmes,sizeof(readmes));
	
	return 0;
}
