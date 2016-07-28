#include<stdio.h>

float bucket[100][100];
int   top[100];

int main(){
	int n, i;
	float a[100];
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter %d elements strictly in [0,1) :\n", n);
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
	//bucket sort
	//initialize top of all buckets
	for(int i=0;i<100;i++)
		top[i]=0;
	for(int i=0;i<n;i++){
		int p=n*a[i];	//index of bucket
		bucket[p][top[p]]=a[i];
		top[p]++;
	}
	//sort individual buckets
	for(int k=0;k<100;k++){
		//using insertion sort
		for(int i=1;i<top[k];i++){
			printf("%d\n",top[k]);
			for(int j=0;j<top[k]-i;j++){
				if(bucket[k][j]>bucket[k][j+1]){
					//swap
					float t=bucket[k][j];
					bucket[k][j]=bucket[k][j+1];
					bucket[k][j+1]=t;
				}
			}
		}
	}
	//concatenate all buckets into original array
	int ind=0;
	for(int k=0;k<100;k++){
		for(int i=0;i<top[k];i++)
			a[ind++]=bucket[k][i];
	}
	//print sorted array
	printf("Sorted array :\n");
	for(int i=0;i<n;i++)
		printf("%f ",a[i]);
	printf("\n");
	return 0;
}
