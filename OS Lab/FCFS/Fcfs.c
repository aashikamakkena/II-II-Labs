#include <stdio.h>
int main(){
	int a[10],i,n;
	float twt,tat,ttat,wt;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter BurstTimes: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	wt = 0;
	printf("ArrayIndex\tBurstTime\tWaitingTime\tTurnAroundTime\n");
	printf("0\t\t");
	printf("%d\t\t",a[0]);
	printf("%.2f\t\t",wt);
	tat = a[0];
	printf("%.2f\n",tat);
	twt = 0;
	ttat = a[0];
	for(i=1;i<n;i++){
		printf("%d\t\t",i);
		printf("%d\t\t",a[i]);
		wt = tat;
		printf("%.2f\t\t",wt);
		twt += wt;
		tat = wt + a[i];
		printf("%.2f\n",tat);
		ttat += tat;
	}
	
	
	
	
	printf("Average Waiting Time is %.2f\n",twt/n);
	printf("Average Turn Around Time is %.2f\n",ttat/n);
	
	return 0;
}

