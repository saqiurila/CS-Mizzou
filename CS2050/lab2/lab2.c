/**
*FNU Saqiurila
*14227763
*qsq35
*Sep 10
*/
#include <stdio.h>

typedef struct{
	char title[20];
	char author[20];
	int rating;
}Book;

#define MAX_LABRARY_SIZE 30


int populate_array(Book library[],char* input);
int binary_search(Book library[],int low, int high, int key);
void sort(Book library[],int length);
void print(Book library[],int length,int key);
void sort_by_author(Book library[],int length); //Bonus
void sort_by_title(Book library[],int length);

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage:.a.out <input file\n");
		return -1;
	}
	
	Book library[MAX_LABRARY_SIZE];
	int length=0;
	int key=0;
	int index=0;
	
	length=populate_array(library,argv[1]);
	if(length==-1){
		printf("Can not open the file.");
		return 0;
	}
	sort(library,length); //Sort the array by rating
	
	printf("Enter a rating to search for: ");
	scanf("%d",&key);
	
	index=binary_search(library,0,length-1,key);
	if(index==-1){
		printf("Fail to find the rating");
		return 0;
	}
	printf("\nSorted by rating:\n");
	print(library,length,index);
	
	printf("\nSorted by author:\n");
	sort_by_author(library,length);
	print(library,length,-1);
	return 0;
}
int populate_array(Book library[],char* input){
	int number=0;
	int i;
	char text[10]="";
	
	FILE* data;
	data=fopen(input,"r");
	if (data==NULL){
		return -1;
	}
	
	fscanf(data,"%d",&number);
	number=number<20?number:20;
	
	//Scan the description of the books from the input file
	for(i=0;i<number;i++){
		fscanf(data,"%s %s %d",library[i].title,&library[i].author,&library[i].rating);
	}
	fclose(data);
	return number;
}

void sort(Book library[],int length){
	int i,j;
	Book temp;
	Book *current=library;
	
	//Every loop finds the smallest number from the remainders of the array
	for(i=0;i<length;i++){
		//Every loop compares the current number with the remainders
		for(j=i+1;j<length;j++){
			//If current is bigger than the next number, then swap two numbers
			if((current+j)->rating<(current+i)->rating){			
				temp=*(current+i);
				*(current+i)=*(current+j);
				*(current+j)=temp;
			}
		}
	}
}

void sort_by_author(Book library[],int length){
	int i,j;
	Book temp;
	Book *current=library;
	
	//Every loop finds the smallest author name from the remainders of the array
	for(i=0;i<length;i++){
		//Every loop compares the current name with the remainders
		for(j=i+1;j<length;j++){
			//If current name is bigger than the next name, then swap two names
			if(strcmp((current+j)->author,(current+i)->author)<0){			
				temp=*(current+i);
				*(current+i)=*(current+j);
				*(current+j)=temp;
			}
			else if(strcmp((current+j)->author,(current+i)->author)==0){
				sort_by_title(library,length);
			}
		}
	}
}

void sort_by_title(Book library[],int length){
	int i,j;
	Book temp;
	Book *current=library;
	
	//Every loop finds the smallest title from the remainders of the array
	for(i=0;i<length;i++){
		//Every loop compares the current title with the remainders
		for(j=i+1;j<length;j++){
			//If current title is bigger than the next title, then swap two titles
			if(strcmp((current+j)->title,(current+i)->title)<0){			
				temp=*(current+i);
				*(current+i)=*(current+j);
				*(current+j)=temp;
			}
		}
	}
}

int binary_search(Book library[],int low, int high, int key) {	
	int mid=(high+low)/2;
	
	//Fail to find
	if(high<low){
		return -1;
	}
	
	//Base case
	if(library[mid].rating==key){
		return mid;
	}
	
	else if(library[mid].rating<key){
		return binary_search(library,mid+1,high,key);
	}
	else{
		return binary_search(library,low,mid-1,key);
	}
}

void print(Book library[],int length,int key){
	int i;
	for(i=0;i<length;i++){
		if(i==key){
			printf("***"); //Mark the book the user is looking for
		}
		printf("%s %s %d\n",library[i].title,library[i].author,library[i].rating);
	}
}