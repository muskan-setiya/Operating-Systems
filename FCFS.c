#include <stdio.h>

void swapi(int k,int l){
  int temp=k;
  k=l;
  l=temp;
}

void swapf(float k,float l){
  float temp=k;
  k=l;
  l=temp;
}

int main()
{
  printf(" Enter Number of processes : ");
  int n; //no. of processes
  scanf("%d",&n);
  int process[n];
  float BT[n],TAT[n],WT[n], AT[n];
  
  printf("Enter process id, Arrival Time and Burst Time\n");
  
  int i,index,j;
  for(i=0;i<n;i++){
      scanf("%d %f %f/n",&process[i],&AT[i],&BT[i]);
  }
  
  //Sorting on the basis of Arrival Time
  for(i=0;i<n;i++){
    index = i;
    for(j=i+1;j<n;j++){
      if(BT[j]<BT[i]){
         swapi(process[i],process[j]);
         swapf(BT[i],BT[j]);
         }         
    }
  }
  
  //Waiting time(n) = waiting time(n-1) + burst time(n-1)
  //tat(n) = wt(n) + bt(n)
  
  WT[0]=0;TAT[0]=BT[0];
  for(i=1;i<n;i++){
     WT[i] = WT[i-1]+BT[i-1];
     TAT[i] = WT[i]+BT[i];
  } 
  
  float avgTAT=0,avgWT=0;
  for(i=0;i<n;i++){
     avgTAT =avgTAT+TAT[i];
     avgWT = avgWT + WT[i];
  }
  avgTAT = avgTAT/n ;avgWT =avgWT/n;
  printf("\n Average Turn Around Time = %f\n",avgTAT);
  printf("\n Average Wainting Time = %f\n",avgWT);
}
