#include<stdio.h>
void main(){
	int arr[50],n,i,large;
	printf("enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	large=arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>large){
			large=arr[i];
		}
	}
	printf("%d",large);
}
