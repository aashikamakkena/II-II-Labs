#include<stdio.h>
void waiting_time(int process[],int n,int wt[],int bt[]){
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i] = wt[i-1]+bt[i-1];
	}
}
void turn_around_time(int process[],int n,int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}
}
int main(){
	int process[]={1,2,3};
	int n = sizeof process/sizeof process[0];
	int bt[]={12,58,14};
	int wt[n],tat[n],i,j,pos,temp;
	int total_wt=0,total_tat=0;
	float avg_wt = 0,avg_tat=0;

	for(i=0;i<n;i++){
		pos=i;
		for(j=0;j<n;j++){
			if(bt[j]>bt[pos]){
				pos = j;
			}
		}
		temp = bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=process[i];
		process[i]=process[pos];
		process[pos]=temp;
	}

	waiting_time(process,n,wt,bt);
	turn_around_time(process,n,bt,wt,tat);
	for(i=0;i<n;i++){
		total_wt += wt[i];
		total_tat += tat[i];
	}
	avg_tat = (float) total_tat/(float) n;
	avg_wt = (float) total_wt/(float) n;

	printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n",process[i],bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time = %f\n",avg_wt);
	printf("Average turn around time = %f\n",avg_tat);
	return 0;
}

