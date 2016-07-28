#include<stdio.h>

int main(){
	int n, a[100], i, max=0;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter %d elements :\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>max)		//find max element
			max=a[i];
	}
	int exp;
	for(exp=1;max/exp>0;exp*=10){	//for each digit in elements
		//sort using count sort
		//based on current digit place
		int b[100], count[10];
		//initialize all counts to 0
		for(i=0;i<10;i++)
			count[i]=0;
		//store count of each element
		for(i=0;i<n;i++)
			count[(a[i]/exp)%10]++;
		//calculate position of each element in sorted array
		for(i=1;i<10;i++)
			count[i] += count[i-1];
		//build sorted array
		for(i=n-1;i>=0;i--){
			b[count[(a[i]/exp)%10]-1]=a[i];
			count[(a[i]/exp)%10]--;
		}
		//copy sorted array too= original array
		for(i=0;i<n;i++)
			a[i]=b[i];
	}
	//print sorted array
	printf("Sorted array : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
