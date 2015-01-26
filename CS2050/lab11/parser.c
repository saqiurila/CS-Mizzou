#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int is_phone_number(char* word){
	if(strlen(word)!=14){
		return 0;
	}
	else if(*word!='('||*(word+4)!=')'||*(word+5)!='-'||*(word+9)!='-'){
		return 0;
	}
	int i;
	for(i=0;i<14;i++){
		if(i==0||i==4||i==5||i==9){
			continue;
		}
		else if(*(word+i)>57||*(word+i)<48){
			return 0;
		}
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
	else if(*(word+2)!='/'||*(word+5)!='/'){
		return 0;
	}
	char* cmonth=malloc(sizeof(char)*3);
	*cmonth=*(word);
	*(cmonth+1)=*(word+1);

	int month=atoi(cmonth);
	if(month<1||month>12){
		return 0;
	}
	char* cday=malloc(sizeof(char)*3);
	*cday=*(word+3);
	*(cday+1)=*(word+4);
	int day=atoi(cday);
	if(day>validDays[month-1]){
		return 0;
	}
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
	int len=strlen(word);
	int has_at=0;
	if(*(word+len-4)!='.'||*(word+len-3)!='c'||*(word+len-2)!='o'||*(word+len-1)!='m'){
		return 0;
	}
	int i;
	for(i=0;i<len-4;i++){
		if(*(word+i)=='@'){
			has_at=1;
			continue;
		}
		else if((*(word+i)>90&&*(word+i)<97)||*(word+i)>122||(*(word+i)>57&&*(word+i)<65)||*(word+i)<48){
			return 0;
		}
	}
	if(has_at==0){
		return 0;
	}
	return 1;
}
