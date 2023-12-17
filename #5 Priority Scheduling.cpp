Experiment – 5
Aim – To implement Priority Scheduling in OS processing scheduling.
Code –
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Process {
int id;
int arrivalTime;
int burstTime;
int priority;
};
bool comparePriority(const Process& p1, const Process& p2) {
return p1.priority > p2.priority;
}
void priorityScheduling(vector<Process>& processes) {
sort(processes.begin(), processes.end(), comparePriority);
int currentTime = 0;
int totalTurnaroundTime = 0;
int totalWaitingTime = 0;
cout << "Process Execution Order:\n";
cout << "Process\tPriority\tBurst Time\tTurnaround Time\tWaiting Time\n";
for (const Process& p : processes) {
currentTime += p.burstTime;
int turnaroundTime = currentTime - p.arrivalTime;
int waitingTime = turnaroundTime - p.burstTime;
totalTurnaroundTime += turnaroundTime;
totalWaitingTime += waitingTime;
cout << p.id << "\t" << p.priority << "\t\t" << p.burstTime << "\t\t" <<
turnaroundTime << "\t\t" << waitingTime << endl;
}
double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) /
processes.size();
double avgWaitingTime = static_cast<double>(totalWaitingTime) /
processes.size();
cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;
cout << "Average Waiting Time: " << avgWaitingTime << endl;
}
int main() {
vector<Process> processes = {
{1, 0, 6, 2},
{2, 2, 8, 1},
{3, 4, 7, 3},
{4, 6, 3, 4},
};
priorityScheduling(processes);
return 0;
}
