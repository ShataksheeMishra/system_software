#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *file;
	file = fopen(argv[1],"r");
	if(file != NULL){
	
		char ch;
		while((ch=fgetc(file)) != EOF){
			putchar(ch);
		}
	fclose(file);
	}
	else{
	printf("file error");
	}




}
