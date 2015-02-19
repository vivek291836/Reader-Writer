#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
using namespace std;

int main(int argc,char** argv){

	int fd;
	char* buff = (char*) malloc(100*sizeof(char));
		

	if(mkfifo("/home/kumar/Git/myfifo",0621) == -1){
		perror("mkfifo");
		return -1;
	}

	else{
	
		if((fd = open("/home/kumar/Git/myfifo",O_WRONLY)) == -1){
			perror("open");
			return -1;
		}

		
		cout<<"Writer got a Reader"<<endl;	
		int count;
		
		fgets(buff,100,stdin);
		
		if((count = write(fd,buff,strlen(buff))) == -1){

			perror("write");
			return -1;
		}
		 
		else{
				
			cout<<"process "<<getpid()<<" wrote " <<count << " bytes of data"<<endl;

			
		}
		
			unlink("/home/kumar/Git/myfifo");

	}
	
	return 0;
}
