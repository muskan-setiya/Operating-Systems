#include <stdio.h>


int main()
{
   printf(" Enter Number of processes : ");
   int n; //no. of processes
  scanf("%d",&n);

  printf(" \nEnter Time Quantum : ");
  float tq;
  scanf("%f",&tq);

  int process[n];
  float BT[n],TAT[n],WT[n],CT[n];
  printf("Enter process id and Burst Time\n");

  int i,index,j;
  for(i=0;i<n;i++){
      scanf("%d %f/n",&process[i],&BT[i]);
  }

  float BTdata[n] ;

  for(i=0;i<n;i++){
    BTdata[i]=BT[i];
  }

  int complete=0;
  float curtime =0;
  do{

        for(i=0;i<n;i++){

            if(BT[i]==0){}

            //When BT is less than TQ
            else if(BT[i]<=tq){
               curtime=curtime+BT[i];
               BT[i]=0;
               CT[i]=curtime;
               complete= complete + 1;
               }
            else{
               curtime = curtime + tq;
               BT[i] = BT[i] - tq;
               CT[i] = curtime;
            }
        }
  }
  while(complete!=n);

  //Waiting time(n) = TAT - BT
  //tat(n) = wt(n) + bt(n)


  for(i=0;i<n;i++){
     TAT[i] = CT[i];
     WT[i] = CT[i]-BTdata[i];
  }

  float avgTAT=0,avgWT=0;
  for(i=0;i<=n;i++){
     avgTAT =avgTAT+TAT[i];
     avgWT = avgWT + WT[i];
  }
  avgTAT = avgTAT/n ;avgWT =avgWT/n;

  printf(" Process  Burst_Time  Completion_Time  Waiting_Time\n");
  for (i=0;i<n;i++){
      printf("  %d \t  %f  \t   %f  \t     %f  \n",process[i],BTdata[i],CT[i],WT[i]);
  }
  printf("\n Average Turn Around Time = %f\n",avgTAT);
  printf("\n Average Wainting Time = %f\n",avgWT);

 }
