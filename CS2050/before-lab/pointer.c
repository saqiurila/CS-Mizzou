#include<stdio.h>
void test(int *x,int b){
	x=&b;
	printf("%d\t%p\t%p\n",*x,&b,&x);
	//*x=b;
}
void str(){
	char *str[5];
	char *ptr1,*ptr2;
	str[0]="this is 1";
	str[1]="this is 2";
	ptr1=str[0];
	ptr2=str[1];
	puts(ptr1);
	puts(++ptr1);
	puts(ptr2);
}

void quiz1(){
	float f=3;
	char *p="I am string";
	printf("%c\n",*p);
	printf("%f\n",f);
}

void quiz2(){
	int x[]={10,8,6,4,2};
	int *xp=x;
	xp+=3;
	printf("%p\n",xp);
	printf("%p\n",*xp);
	printf("%p\n",x[3]);
}
int main(){
	int a=1,b=3,*x;
	x=&a;
	*x=2;
	printf("%d\n",a);
	printf("%p\t%p\t%p\n",x,&a,&x);
	test(x,b);
	printf("%d\t%p\t%p\n",*x,&b,&x);

	str();

	quiz2();
	
	quiz1();

	return 0;
}


