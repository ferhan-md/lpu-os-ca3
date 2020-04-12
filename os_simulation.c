#include<stdio.h>
#include<conio.h>
int main()
{
	/*
	1. bt - burst time
	2. p - process number
	3. wt - waiting time
	4. tat - turn around time.
	*/
	int bt[30],p[30],wt[30],tat[30];
	int i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("\nEnter the number of process : ");
	scanf("%d",&n);
	printf("\nEnter estimated time : \n");
	for(i=0;i<n;i++)
	{printf("p%d:",i+1);
		 scanf("%d",&bt[i]);
		 p[i]=i+1; // contains process number
	}
	// sorting burst time in ascending order.
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			{
				pos=j;
			}
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0; //waiting time for the first process will be zero
	// calculating waiting time
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
				total+=wt[i];
		}
		
	}
	avg_wt = (float)total/n;
	total = 0;
	system("cls"); // clear output screen
	 // \t is used to increase space in line.
	printf("\nProcess\t\tEstimated Time\t\t\tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i]; // calculate turn arround time
		total +=tat[i];
		printf("\np%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total/n; // calculating average turn around time
	printf("\n\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
	return 0;
}
