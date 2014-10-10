/**
*FNU Saqiurila
*14227763
*qsq35
*Sep 17
*/
#include <stdio.h>

#define MAX_ACCOUNTS 20

typedef struct{
	int accountId;
	float balance;
}Account;

int load_accounts(Account accounts[],char* fileName);
void sort(Account accounts[],int length);
Account* find_account(Account accounts[],int low,int high,int id);
void run_transactions(Account accounts[],int length,char* fileName);
void print(Account accounts[],int length);
void selectionSort(Account accounts[],int length);  //Bonus
void swap(Account accounts[],int first,int second);

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("Incorrect number of command line atguments\n");
		printf("Correct usage:./a.out <account list> <transactions>\n");
		return -1;
	}
	
	Account accounts[MAX_ACCOUNTS];
	int length=load_accounts(accounts,argv[1]);
	if(length==-1){
		printf("Can not open the file");
		return -1;
	}
	sort(accounts,length);
	run_transactions(accounts,length,argv[2]);	
	printf("\nFinal balance sheet\n");
	print(accounts,length);
	
	selectionSort(accounts,length);  //Resort
	printf("\nResored by selection sort:\n");
	print(accounts,length);
}

int load_accounts(Account accounts[],char* fileName){
	int len=0;
	FILE* fp=fopen(fileName,"r");
	if(fp==NULL){
		return -1;  //Can not open the file.
	}
	while(1){
		fscanf(fp,"%d%f",&accounts[len].accountId,&accounts[len].balance);
		len++;
		if(feof(fp)){			
			break;
		}
		if(len>MAX_ACCOUNTS){
			break;
		}		
	}
	return len;
}

void sort(Account accounts[],int length){
	int i,j;
	Account temp;
	Account *current=accounts;
	//Every loop finds the smallest number from the remainders of the array
	for(i=0;i<length;i++){
		//Every loop compares the current number with the remainders
		for(j=i+1;j<length;j++){
			//If current is bigger than the next number, then swap two numbers
			if((current+j)->accountId<(current+i)->accountId){			
				swap(accounts,i,j);
			}
		}
	}
}
Account* find_account(Account accounts[],int low,int high,int id){
	int mid=(high+low)/2;
	
	//Fail to find
	if(high<low){
		return NULL;
	}
	
	//Base case
	if(accounts[mid].accountId==id){
		//printf("found\n");
		//return NULL;
		return &accounts[mid];
	}
	
	else if(accounts[mid].accountId<id){
		return find_account(accounts,mid+1,high,id);
	}
	else{
		return find_account(accounts,low,mid-1,id);
	}
}
void run_transactions(Account accounts[],int length,char* fileName){
	int accountId;
	float money;
	FILE* fp=fopen(fileName,"r");
	while(1){
		fscanf(fp,"%d%f",&accountId,&money);
		Account* account=find_account(accounts,0,length-1,accountId);
		if(account==NULL){
			printf("Invalid transaction; account %d does not exist.\n", accountId);
		}
		else if(account->balance+money<0){
			printf("Invalid transaction; Withdrawing %.2f from account %d results in a negative balance.\n",money,accountId);
		}
		else{
			account->balance+=money;
		}
		if(feof(fp)){
			break;
		}
	}
}
void print(Account accounts[],int length){
	int i;
	for(i=0;i<length;i++){
		printf("%d %.2f\n",accounts[i].accountId,accounts[i].balance);
	}
}
void selectionSort(Account accounts[],int length){
	int i,j,iMin;
	float min;
	for(i=0;i<length;i++){
		iMin=i;
		min=accounts[iMin].balance;
		//Every loop finds the smallest number from the remainders of the array
		for(j=i+1;j<length;j++){			
			if(accounts[j].balance<accounts[iMin].balance){
				min=accounts[j].balance;
				iMin=j;
			}
		}
		if(iMin!=i){
			swap(accounts,i,iMin);
		}
	}
}
void swap(Account accounts[],int first,int second){
	Account temp;
	temp=accounts[first];
	accounts[first]=accounts[second];
	accounts[second]=temp;
}