#include <stdio.h>
#include <string.h>

void insertionSort(int array[],int length);

int main(){
	int array[]={3,2,8,6,9,4,1,7,5,0};
	int i;
	insertionSort(array,10);

	for(i=0;i<10;i++){
		printf("%d\n",array[i]);
	}
	return 0;
}

void insertionSort(int array[],int length){
	int i,j,temp;
	for(i=0;i<length;i++){
		/*for(j=i-1;j>=0;j--){
			if(array[j]>array[j+1]){
				temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
			else
				break;
		}*/
		j=i;
		while(j>=0&&array[j-1]>array[j]){
			temp=array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
			j--;
		}
	}
}
