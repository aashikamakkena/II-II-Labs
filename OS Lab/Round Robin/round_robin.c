#include<stdio.h>
#include <stdbool.h>
int turn_around_time(int process[],int n,int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i] = bt[i] + wt[i];
		
	}
}
int waiting_time(int process[],int n,int bt[],int wt[],int quantum){
	int rem_bt[n];
	for(int i=0;i<n;i++)
		rem_bt[i] = bt[i];
		int t =0;
		while(1){
			bool done =true;
			for(int i=0;i<n;i++){
				if(rem_bt[i]>0){
					done = false;
				if(rem_bt[i] >quantum){
					t+= quantum;
					rem_bt[i] -= quantum;
				}
				else{
					t += rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if(done == true)
			break;
	}
	
	
}
int find_avg_time(int process[],int n,int bt[],int quantum){
	int wt[n],tat[n],total_wt = 0,total_tat = 0;
	waiting_time(process,n,bt,wt,quantum);
	turn_around_time(process,n,bt,wt,tat);
	printf("Process\t\tBurstTime\tWaitingTime\tTurnAroundTime\n");
	for(int i=0;i<n;i++){
		total_wt += wt[i];
		total_tat += tat[i];
		printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time = %f\n",(float)total_wt/(float)n);
	printf("Average turn arounf time = %f\n",(float)total_tat/(float)n);
	
}
int main(){
	int process[]  = {1,2,3};
	int n = sizeof process/sizeof process[0];
	int burst_time[] = {8,6,12};
	
	int quantum = 2;
	find_avg_time(process,n,burst_time,quantum);
	return 0;
}

	

