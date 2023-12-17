Experiment – 2
Aim – WAP to implement FCFS Scheduling Algorithm.
Code –
#include <iostream>
using namespace std;
int main()
{
int Proc;
int at[20];
int bt[20];
int wt[20];
int tat[20];
int n;
cout<<"Enter number of processes - "<<endl;
cin>>n;
for(int i=0; i<n; i++)
{
cout<<"Enter the arrival time of "<< i << " Process"<<endl;
cin>>at[i];
}
for(int j=0; j<n; j++)
{
cout<<"Enter the burst time of "<< j << " Process"<<endl;
cin>>bt[j];
}
wt[0] = 0;
for(int i=1; i<n; i++)
{
wt[i] = max(at[i], wt[i-1] + bt[i-1]);
}
for(int i=0; i<n; i++)
{
tat[i] = wt[i] + bt[i];
}
cout << "Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time" <<
endl;
for (int i = 0; i < n; i++) {
cout << i << " | " << at[i] << " | " << bt[i] << " | " << wt[i] << " | " << tat[i] <<
endl;
}
float tot_wt = 0;
float tot_tat = 0;
for(int i=0; i<n; i++)
{
tot_wt = tot_wt + wt[i];
tot_tat = tot_tat + tat[i];
}
cout<<"Average Waiting Time - "<< tot_wt/n <<endl;
cout<<"Average Turnaround Time - "<< tot_tat/n <<endl;
return 0;
}
