#include<stdio.h>
#include<unistd.h>
 
int main() {
   int pfd1[2], pfd2[2];
   int status1, status2;
   int pid;
   char pipe1[20];
   char pipe2[20];
   printf("Enter message 1:");
   scanf("%s",pipe1);
   printf("Enter message 2:");
   scanf("%s",pipe2);
   char readmes[20];
   status1 = pipe(pfd1);
   
   if (status1 == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }
   status2 = pipe(pfd2);
   
   if (status2 == -1) {
      printf("Unable to create pipe 2 \n");
      return 1;
   }
   pid = fork();
   
   if (pid != 0){
      close(pfd1[0]); 
      close(pfd2[1]); 
      printf("In Parent: Writing to pipe 1 – Message is %s\n", pipe1);
      write(pfd1[1], pipe1, sizeof(pipe1));
      read(pfd2[0], readmes, sizeof(readmes));
      printf("In Parent: Reading from pipe 2 – Message is %s\n", readmes);
   } else { 
      close(pfd1[1]); 
      close(pfd2[0]); 
      read(pfd1[0], readmes, sizeof(readmes));
      printf("In Child: Reading from pipe 1 – Message is %s\n", readmes);
      printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2);
      write(pfd2[1], pipe2, sizeof(pipe2));
   }
   return 0;
}

