#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h> 
#include<fcntl.h> 
#include<stdlib.h> 

void tree(){
     struct stat st = {0};
     int fileDescriptor;

     //create directory Dir0 
     if (stat("./Dir0", &st) == -1){
          mkdir("./Dir0", 0700);
          }
     
     // changing directory to Dir0
     chdir("Dir0");

     // Creating the txt files now as follows inside Dir0 
     fileDescriptor = open("t1.txt", O_CREAT | O_RDWR, S_IRWXU);

     if(fileDescriptor < 0){
          perror("Error creating file");
          exit(-1);
          }
     
     fileDescriptor = open("t2.txt", O_CREAT | O_RDWR, S_IRWXU);

     if(fileDescriptor < 0){
          perror("Error creating file");
          exit(-1);
          }
     
     fileDescriptor = open("t3.txt", O_CREAT | O_RDWR, S_IRWXU);
     
     if(fileDescriptor < 0){
          perror("Error creating file");
          exit(-1);
          }
     
     // Create directory Dir1
     if(stat("./Dir1", &st) == -1){
             mkdir("./Dir1", 0700); 
        } 
}

int main(){
     tree();
} 