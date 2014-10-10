/**
*FNU Saqiurila
*14227763
*qsq35
*Sep 17
*/
#include <stdio.h>

#define MAX_ARR_LEN 1000

void mergesort(int array[],int low,int high);
void merge(int array[],int low,int mid,int high);
int magic_index(int array[],int low, int high);
int populate_array(int array[],char* fileName);
int is_sorted(int array[],int length);
void insertionsort(int array[],int length);  //Bonus

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out <input file>\n");
		return 0;
	}
	
	int array[MAX_ARR_LEN];
	int magic_number;
	int length=populate_array(array,argv[1]);
	
	if(length==-1){
		printf("Fail to open the file.\n");
	}
	
	mergesort(array,0,length-1);
	
	if(is_sorted(array,length)==1){
		printf("The array is sorted:\n");
		int i;
		for(i=0;i<length;i++){
			printf("%d ",array[i]);
		}
		printf("\n");
		
		magic_number=magic_index(array,0,length);
		printf("Magic number: %d\n",magic_number);
	}
	else{
		printf("Fail to sort the array.\n");
	}
	return 0;
}

void mergesort(int array[],int low,int high){
	int mid=(low+high)/2;
	
	if(low<high){
		if(high-low<5){
			insertionsort(array,(high-low+1)); //insertion sort
		}
		//Split into two parts
		mergesort(array,low,mid);
		mergesort(array,mid+1,high);
		
		merge(array,low,mid,high);
	}
	
}

void merge(int array[],int low,int mid,int high){
	int i=low,j=mid+1;
	int index=low;
	int tempArray[MAX_ARR_LEN];
	//Compare
	while(i<=mid&&j<=high){
		if(array[i]<array[j]){
			tempArray[index++]=array[i++];
		}
		else{
			tempArray[index++]=array[j++];
		}
	}
	//If there are some numbers left
	while(i<=mid){
		tempArray[index++]=array[i++];
	}
	while(j<=high){
		tempArray[index++]=array[j++];
	}
	//Put the sorted list into array
	for(i=low;i<=high;i++){
		array[i]=tempArray[i];
	}
}

void insertionsort(int array[],int length){
	int i,temp;
	for(i=0;i<length;i++){
		int index=i; 		
		while(index>0&&array[index]<array[index-1]){
			//swap two number
			temp=array[index];
			array[index]=array[index-1];
			array[index-1]=temp;
			
			index--;
		}
	}
}

int magic_index(int array[],int low, int high){
	if(high<low){
		return -1;
	}
	int mid=(high+low)/2;
	if(array[mid]<mid){
		return magic_index(array,mid+1,high);
	}
	else if(array[mid]>mid){
		return magic_index(array,low,mid-1);
	}
	else{
		return mid;
	}
}

int populate_array(int array[],char* fileName){
	int i=0;
	FILE* fp=fopen(fileName,"r");
	if(fp==NULL){
		return -1; //Fail to open the file
	}
	while(1){
		fscanf(fp,"%d",&array[i++]);
		if(feof(fp)){
			break;
		}
	}
	return i;
}

int is_sorted(int array[],int length){
	int i;
	for(i=0;i<length-1;++i){
		if(array[i]>array[i+1]){
			return 0;
		}
	}
	return 1;
}

