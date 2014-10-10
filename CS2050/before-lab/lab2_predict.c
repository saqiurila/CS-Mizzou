#include <stdio.h>

typedef struct{
	char title[20];
	int yearReleased;
	int sales;
	int ticketsSold;
}Movie;

#define MAX_ARR_LEN 20

Movie movie_catalog[MAX_ARR_LEN];

int populate_movie_catalog();
char* binary_search(int low, int high, int key);
void sort_by_year(int length);

int main(){
	int length;
	length=populate_movie_catalog();	
	sort_by_year(length);
	printf("The movie released in 2014 is: %s\n",binary_search(0,length-1,2005));
	return 0;
}
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
	//printf("%d",number);
	//number=atoi(text);
	for(i=0;i<number;i++){
		fscanf(data,"%s %d %d %d",movie_catalog[i].title,&movie_catalog[i].yearReleased,&movie_catalog[i].sales,&movie_catalog[i].ticketsSold);
		printf("%s\n",movie_catalog[i].title);
	}
	//printf("size of array:%d\n",movie_catalog);
	fclose(data);
	return number;
}

void sort_by_year(int length){
	int i,j;
	Movie temp;
	Movie *current=movie_catalog;
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if((current+j)->yearReleased<(current+i)->yearReleased){			
				temp=*(current+i);
				*(current+i)=*(current+j);
				*(current+j)=temp;
			}
		}
	}
	printf("The released years in ascending sorted order:\n");
	for(i=0;i<length;i++){
		printf("%d\n",movie_catalog[i].yearReleased);
	}
}

char* binary_search(int low, int high, int key) {	
	int mid=(high+low)/2;
	if(high<low){
		return "Fail to find.";
	}
	if(movie_catalog[mid].yearReleased<key){
		binary_search(mid+1,high,key);
	}
	else if(movie_catalog[mid].yearReleased>key){
		binary_search(low,mid-1,key);
	}
	else
		return movie_catalog[mid].title;
}