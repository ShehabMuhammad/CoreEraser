// C program to find the size of file 
#include <stdio.h> 
  
long int findSize(char file_name[]) 
{ 
    // opening the file in read mode 
    FILE* fp = fopen(file_name, "r"); 
  
    // checking if the file exist or not 
    if (fp == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
  
    fseek(fp, 0L, SEEK_END); 
  
    // calculating the size of the file 
    long int res = ftell(fp); 
  
    // closing the file 
    fclose(fp); 
  
    return res; 
} 

void  OverWrite(char *path);
void EraseFile(char *path, long int size);
  
// Driver code 
int main(int argc, char **argv) 
{ 
    if(argc < 2) { printf("No path was specified. \n"); return 0;  }
      char *fileName = argv[argc-1];
    long int res = findSize(fileName); 
   if (res != -1) {  printf("Size of the file is %ld bytes \n", res);  }
    OverWrite(fileName);
    EraseFile(fileName, res);
 
    return 0; 
} 


void OverWrite(char *path){

FILE *hakuna= fopen(path ,  "w+") ;
fclose(hakuna);
}


void EraseFile( char *path, long int size){

FILE *fuck = fopen(path, "a+") ;
int i=size/2;
while(i>0){
fputs( "00", fuck );
i--;
}


fclose(fuck);
remove(path); printf(" --- File Has Been Erased Successfully ---");
}