#include<stdio.h>
#define MAX 30
void main(){
int i,j,n,burst[MAX],wt[MAX],tat[MAX];
float avg_wt=0,avg_tat=0;
printf("Enter No. of Processes:");
scanf("%d",&n);
printf("Enter Burst Time Of Processes \n");
for(i=0;i<n;i++){
    scanf("%d",&burst[i]);
}

printf("Process\t Burst Time\t Waiting Time\t Turn Around Time\n");
for(i=0;i<n;i++){
    wt[i]=0;
    tat[i]=0;
    for(j=0;j<i;j++){
        wt[i]=wt[i]+burst[j];
    }
    tat[i]=wt[i]+burst[i];
    avg_wt=avg_wt+wt[i];
    avg_tat=avg_tat+tat[i];
    printf("%d\t %d\t\t %d\t\t %d\n",i+1,burst[i],wt[i],tat[i]);
}
avg_wt=avg_wt/n;
avg_tat=avg_tat/n;
printf("Average Waiting Time : %f\n",avg_wt);
printf("Average Turn Around Time : %f\n",avg_tat);

}
