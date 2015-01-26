#include <stdio.h>
#include <string.h>
#include "parser.h"

#define MAX_LINE 250
int main(int argc ,char** argv){
	if(argc!=2){
		printf("Usage: ./lab11 <input file>");
		return 0;
	}
	FILE* fp=fopen(*(argv+1),"r");
	if(fp==NULL){
		printf("Fail to open the file");
		return 0;
	}
	char buffer[MAX_LINE+1];
	while(fgets(buffer,MAX_LINE,fp)){
		if(buffer[strlen(buffer)-1]=='\n'){
			buffer[strlen(buffer)-1]='\0';
		}
		char* token=strtok(buffer," \n\r\t");
		while(token!=NULL){
			//printf("token:%s\n",token);
			if(is_phone_number(token)){
				printf("Phone number:%s\n",token);
			}
			else if(is_date(token)){
				printf("Date:%s\n",token);
			}
			else if(looks_like_name(token)){
				char* next=strtok(NULL," \n\r\t");
				if(looks_like_name(next)){
					printf("Name:%s %s\n",token,next);
				}
				else token=next;
			}
			else if(is_email(token)){
				printf("Email:%s\n",token);
			}
			token=strtok(NULL," \n\r\t");
		}
		
	}
}
