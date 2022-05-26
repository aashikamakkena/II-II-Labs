#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(void){
int fd[2];
char buf1[12] = "hello world\n";
char buf2[12];
fd[0] = open("file.txt",O_RDWR | O_CREAT,0777);
fd[1] = open("file.txt",O_RDWR);
write(fd[0],buf1,strlen(buf1));
write(fd[1],buf2,read(fd[1],buf2,12));
close(fd[0]);
close(fd[1]);
return 0;
}
