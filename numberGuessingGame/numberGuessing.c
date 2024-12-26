#include<stdio.h>
void main(){
	int n,temp,len=0,num=0;
	printf("Enter a number : ");
	scanf("%d",&n);
	temp=n;
	while(n>0){
		n/=10;
		len++;
	}
	n=temp;
	while(n>0){
		int rem = n%10;
		printf("1 : %d\nNN : %d",rem);
		for(int i=0;i<len;i++){
			rem = rem*rem;
		}
		
	 
		printf("Rem : %d\nNum : %d\n",rem);
		n/=10;
	}
	printf("%d\n%d",num,temp);
	if(num==temp){
		printf("Number is Armstrong");
	}else{
			printf("Number is not Armstrong");
	}
	
}