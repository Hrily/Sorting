#include<stdio.h>

int main(){
	int n, a[100], i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter %d elements :\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//comb sort
	int gap=n, swapped=1;
	while(gap!=1 || swapped){
		//shrink the camparision gap
		gap=(gap*100)/124;		//gap=gap/1.24
		if(gap<1) gap=1;
		swapped=0;			//init swapped
		for(i=0;i<n-gap;i++){
			if(a[i]>a[i+gap]){
				//swap
				int t=a[i];
				a[i]=a[i+gap];
				a[i+gap]=t;
				swapped=1;	//swap done
			}
		}
	}
	//print sorted array
	printf("Sorted array :\n");
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
