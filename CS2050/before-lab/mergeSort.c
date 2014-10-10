#include <stdio.h>

void mergeSort(int array[],int low,int high);
void merge(int array[],int low,int mid,int high);

int main(){
	int array[]={3,2,8,6,9,4,1,7,5,0};
	int i;
	mergeSort(array,0,9);

	for(i=0;i<10;i++){
		printf("%d\n",array[i]);
	}
	return 0;
}

void mergeSort(int array[],int low,int high){
	int mid=(low+high)/2;
	if(low<high){
		mergeSort(array,low,mid);
		mergeSort(array,mid+1,high);

		merge(array,low,mid,high);
	}
}

void merge(int array[],int low,int mid,int high){
	int left=low,right=mid+1;
	int i=low; //!!!!别写成0
	int temp[10];
	while(left<=mid&&right<=high){
		if(array[left]<=array[right]){
			temp[i++]=array[left++];
		}
		else{
			temp[i++]=array[right++];
		}
	}
	while(left<=mid){
		temp[i++]=array[left++];
	}
	while(right<=high){
		temp[i++]=array[right++];
	}
	for(i=low;i<=high;i++){ //这里也注意别写成0和length,也别写成i<high
		array[i]=temp[i];
	}
}
