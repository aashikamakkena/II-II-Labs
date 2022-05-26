#include<stdio.h>
void completion_time(int process[],int ct[], int bt[],int n){
	ct[0] = bt[0];
	for(int i=1;i<n;i++){
		 ct[i] = ct[i-1]+bt[i];
	}
}
void turn_around_time(int process[],int n,int ct[],int at[],int tat[]){
	for(int i=0;i<n;i++){
		 tat[i] = ct[i]-at[i];
	}
}
void waiting_time(int process[],int n,int tat[],int bt[],int wt[]){
	for(int i=0;i<n;i++){
		wt[i] = tat[i] - bt[i];
	}
}
int main(){
	int process[]= {1,2,3,4,5};
	int pos,i,j,temp;
	int n = sizeof process/sizeof process[0];
	int at[]= {0,1,3,2,4},bt[] = {3,6,1,2,4},priority[] = {3,4,9,7,8};
	int ct[n],wt[n],tat[n];
	int total_wt=0,total_tat = 0;
	float avg_wt=0,avg_tat=0;
	for(i=0;i<n-1;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(priority[j]<priority[pos]){
				pos = j;
			}
		}
		
		temp = priority[i];
		priority[i]=priority[pos];
		priority[pos]=temp;
		
		temp=process[i];
		process[i]=process[pos];
		process[pos]=temp;
		
		
		temp = at[i];
		at[i]=at[pos];
		at[pos]=temp;
		
		temp = bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		
		
		
		
		
	}
completion_time(process,ct,bt,n);
turn_around_time(process,n,ct,at,tat);
waiting_time(process,n,tat,bt,wt);
for(i=0;i<n;i++){
	total_wt += wt[i];
	total_tat += tat[i];
}
avg_wt = (float)total_wt/(float)n;
avg_tat = (float)total_tat/(float)n;

printf("Process\t\tPriority\tArrival time \t Burst time\t Completion time\t turn around\t waiting time\n");
for(i=0;i<n;i++){
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i],priority[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("Average waiting time:%f\n",avg_wt);
printf("Average turn around time:%f\n",avg_tat);
return 0;
}
