#include<stdio.h>
int main(){
	int list[6]={1,2,3,4,5,6},i;
	int *p;
	p=&list[0];
	printf("%d\n",p);
	printf("%d\n",p++);
	printf("%d\n",p);
	printf("%d\n",p+1);//���ı�pָ���λ��
	printf("%d\n",p);
	printf("%d\n",*p);
	printf("%d\n",*++p);
	printf("%d\n",p);
	printf("\n\n");
	p=&list[0];
	for(i=0;i<6;i++){
		printf("%d\n",*(p+i));
		printf("%d\n",list[i]);
		
	}

	return 0;
}