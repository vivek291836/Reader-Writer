#include<iostream>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
using namespace std;

int main(int argc,char** argv){

	int fd;
	char* buff = (char*) malloc(100*sizeof(char));
	

	
	if((fd = open("/home/kumar/Git/myfifo",O_RDONLY)) == -1){
		perror("open");
		return -1;
	}
	
	cout<<"Reader got a Writer"<<endl;
	int count;
	
	if((count=read(fd,buff,100)) == -1){

			perror("read");
			return -1;

	}
	cout<<"process" <<getpid()<< "reads "<<count <<" bytes"<<endl;

	fputs(buff,stdout);
	
	
	return 0;
}
