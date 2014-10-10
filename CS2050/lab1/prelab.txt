#include <stdio.h>
#include <stdlib.h>
#define MAX_ARR_LEN 20;
int numbers[20];

/**
 * Input: None
 * Return: The number of numbers read into the file
 * This function should open a file called data.txt which contains a list of 
 * numbers. The first number in the file is the length of the file. It should then 
 * read the subsequent numbers into the numbers array. If the length of the file is 
 * greater than MAX_ARR_LEN then only MAX_ARR_LEN numbers should be read in. 
 * Ex file: 
 * 3
 * 2
 * 1
 * 5
 */
int read_numbers_from_file(){
	char path[100]="d:\\data.txt";
	int number=0,i=0;
	char text[10]="";
	FILE* data;
	data=fopen(path,"r");
	if (data==NULL){
		printf("Can not open the file.");
		exit(-1);
	}
	for(i=0;fgets(text,10,data);i++){
		if(i==0){
			if(atoi(text)<20)
				number=atoi(text);
			else
				number=20;
		}
		else
			numbers[i-1]=atoi(text);
	}
	return number;
}

/**
 * Input: The length of the numbers array
 * Return: The average of all the numbers in the numbers array
 */
float average(int length){
	int sum=0,i=0;
	float average;
	for(i=0;i<length;i++){
		sum+=numbers[i];
	}
	average=(float)sum/read_numbers_from_file();
	return average;
}

/**
 * Input: The length of the numbers array
 * Return: The largest number in the numbers array
 */
int find_max(int length){
	int max=0,i=0;
	max=numbers[0];
	for(i=1;i<length;i++){
		if(numbers[i]>max){
			max=numbers[i];
		}
		//or max=numbers[i]>max?numbers[i]:max;
	}
	return max;
}

/**
 * Input: The length of the numbers array
 * Return: None
 * This function should print every member of the numbers array. 
 */
void print_numbers(int length){
	int i;
	if(length>0){
		printf("Numbers in the list are:\n");
		for(i=0;i<length;i++){
			printf("%d\n",numbers[i]);
		}
	}
}

int main(void) {

	int length,max;
	float avg;

	length=read_numbers_from_file();
	printf("The length of the list is %d\n",length);
	
	print_numbers(length);

	avg=average(length);
	printf("The average of the list is %.3f\n",avg);

	max=find_max(length);
	printf("The largest number in the list is %d\n",max);

	return 0;
}
