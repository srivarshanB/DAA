#include<stdio.h>
int main() 
{
	int num,rem,sum=0,temp;
	printf("enter the number:");
	scanf("%d",&num);
	temp=num;
	while(num>0)
	{
		rem=num%10;
		sum+=rem*rem*rem;
		num/=10;
	}
	if(temp==sum)
		printf("It is a armstrong number");
	else
		printf("It is not a armstrong number");
	return 0;
}
