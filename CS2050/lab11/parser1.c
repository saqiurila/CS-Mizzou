#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int is_phone_number(char* word){
	//char* copy=(char*)malloc(sizeof(char)*(strlen(word)+1));
	char* token;
	int i=1;
	//strcpy(copy,word);
	//if the length is not 14
	if(strlen(word)!=14){
		return 0;
	}
	token=strtok(word,"-");
	while(token!=NULL){
		//first token
		if(i==1){
			//if not starts with ( or ends with with ) or has the length of 5
			if(strlen(token)!=5||*token!='('||*(token+4)!=')'){
				return 0;
			}
			else{
				while(*(++token)!=')'){
					//if not a number
					if(*token>57||*token<48){
						return 0;
					}
				}	
			}
		}
		else{
			int j=0;
			while(j++<i+1){
				//if the length is smaller than 3 or 4, or not a number
				if(*token=='\0'||*token>57||*token<48){
					return 0;
				}
				token++;
			}
			//if the length is bigger than 3 or 4
			if(*token!='\0'){
				return 0;
			}
		}
		token=strtok(NULL,"-");
		i++;
	}
	//if there are not 3 '-' in the string
	if(i!=4){
		return 0;
	}
	return 1;
}

int is_date(char* word){
	int validDays[]={31,28,31,30,31,30,31,31,30,31};
	int i=1;
	//if the length is not 10
	if(strlen(word)!=10){
		return 0;
	}
	int month=atoi(strtok(NULL,"/"));
	if(month<1||month>12){
		free(copy);
		return 0;
	}
	int day=atoi(strtok(NULL,"/"));
	if(day!=validDays[month-1]){
		free(copy);
		return 0;
	}
	free(copy);
	return 1;
}
int looks_like_name(const char* word){
	int i;
	if(strlen(word)<=1){
		return 0;
	}
	else if(*word<65||*word>90){
		return 0;
	}
	for(i=1;i<strlen(word);i++){
		if(*(word+i)<97||*(word+i)>122){
			return 0;
		}
	}
	return 1;
}
int is_email(char* word){
	char* copy=(char*)malloc(sizeof(char)*(strlen(word)+1));
	int i;
	int j=0;
	strcpy(copy,word);
	char* token=strtok(copy,"@\0");
	if(token==NULL){
		return 0;
	}
	while(token!=NULL){
		int len=strlen(token);
		if(j==2){
			if(len==3||*(token)=='c'||*(token)=='o'||*(token)=='m'){
				return 1;
			}
			else{
				return 0;
			}
		}
		for(i=0;i<len;i++){
			if((*(token+i)>90&&*(token+i)<97)||*(token+i)>122||(*(token+i)>57&&*(token+i)<65)||*(token+i)<48){
				return 0;
			}
		}		
		token=strtok(NULL,".");
		j++;
	}
	return 0;
}
