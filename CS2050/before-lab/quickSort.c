#include <stdio.h>

void quickSort(int array[],int low,int high);

int main(){
	int array[]={3,2,8,6,9,4,1,7,5,0};
	int i;
	quickSort(array,0,9);

	for(i=0;i<10;i++){
		printf("%d\n",array[i]);
	}
	return 0;
}

void quickSort(int array[],int low,int high){
	int mid=(low+high)/2;
	int i=low,j;
	int key;
	int temp;
	if(low<high){
		key=array[low];
		for(j=low+1;j<=high;j++){			
			if(array[j]<=key){
				temp=array[++i];
				array[i]=array[j];
				array[j]=temp;
			}			
		}
		temp=array[low];
		array[low]=array[i];
		array[i]=temp;

		quickSort(array,low,i);
		quickSort(array,i+1,high);
	}	
}
