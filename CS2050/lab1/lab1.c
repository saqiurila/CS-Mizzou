/**
*FNU Saqiurila
*qsq35
*/
#include <stdio.h>
#include <stdlib.h>
//iterator through the array and find the sum of all of its members

typedef struct{
	char title[20];
	int yearReleased;
	int sales;
	int ticketsSold;
}Movie;

#define MAX_ARR_LEN 20

Movie movie_catalog[MAX_ARR_LEN];

int populate_movie_catalog(){
	char* file_path ="data.txt";
	int number=0;
	int i;
	char text[10]="";
	FILE* data;
	data=fopen(file_path,"r");
	if (data==NULL){
		printf("Can not open the file.");
		exit(-1);
	}
	fscanf(data,"%d",&number);
	printf("%d",number);
	//number=atoi(text);
	for(i=0;i<number;i++){
		fscanf(data,"%s %d %d %d",movie_catalog[i].title,&movie_catalog[i].yearReleased,&movie_catalog[i].sales,&movie_catalog[i].ticketsSold);
		printf("%s\n",movie_catalog[i].title);
	}
	//printf("size of array:%d\n",movie_catalog);
	fclose(data);
	return number;
}
float average_ticket_price(int length){
	int sum=0;
	int i;
	int sales;
	int ticketsSold;
	float average;
	for(i=0;i<length;i++){
		sales+=movie_catalog[i].sales;
		
		ticketsSold+=movie_catalog[i].ticketsSold;
		//printf("%d",movie_catalog[i].ticketsSold);
		//printf("%d",ticketsSold);
	}
	
	average=(float)sales/ticketsSold;
	return average;
}
int find_highest_grossing_movie(int length){
	//char *higest_grossing_movie="";
	int highest_gross;
	int highest_grossing_movie;
	int i;
	highest_grossing_movie=0;
	highest_gross=movie_catalog[0].sales;
	for(i=1;i<length;i++){
		if(movie_catalog[i].sales>highest_gross){
			highest_gross=movie_catalog[i].sales;
			highest_grossing_movie=i;
		}
	}
	return highest_grossing_movie;
}
void print_catalog(int length){
	int i;
	if(length>0){
		for(i=0;i<length;i++){
			printf("%s:%d\n",movie_catalog[i].title,movie_catalog[i].yearReleased);
		}
	}
}
int main(void){
	int length;
	int highest_grossing_movie;
	float average_price;

	length=populate_movie_catalog();
	printf("The length of the list is %d\n",length);
	
	printf("List of Movies:\n");
	print_catalog(length);

	average_price=average_ticket_price(length);
	printf("Average Ticket Prices: %.3f\n",average_ticket_price);

	highest_grossing_movie=find_highest_grossing_movie(length);
	printf("Highest Grossing Movie: %s\n",movie_catalog[highest_grossing_movie].title);

	return 0;
}
