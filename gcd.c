#include<stdio.h>
int gcd(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a==b)
		return a;
	if(a>b)
		return gcd(a-b,b);
	else
		return gcd(a,b-a);
}
int main()
{
	int a=36,b=48;
	printf("GCD of %d is %d: %d",a,b,gcd(a,b));
	return 0;
}
