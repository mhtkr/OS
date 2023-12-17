Experiment – 9
Aim – Implement first fit, best fit and worst fit memory management algorithm.
Code –
(i) FIRST FIT
#include<bits/stdc++.h>
using namespace std;
void firstFit(int block_size[], int total_blocks, int process_size[], int total_process) {
int allocation[total_process];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < total_process; i++) {
for (int j = 0; j < total_blocks; j++) {
if (block_size[j] >= process_size[i]) {
allocation[i] = j;
block_size[j] -= process_size[i];
break;
}
}
}
cout<<"First Fit"<<endl;
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < total_process; i++) {
cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main() {
int block_size[] = {300, 50, 200, 350, 70};
int process_size[] = {200, 47, 212, 426, 10};
int total_blocks = sizeof(block_size) / sizeof(block_size[0]);
int total_process = sizeof(process_size) / sizeof(process_size[0]);
firstFit(block_size, total_blocks, process_size, total_process);
return 0; }
(ii) BEST FIT
#include <iostream>
#include <cstring>
using namespace std;
void bestFit(int bsize[], int m, int psize[], int n) {
int alloc[n];
memset(alloc, -1, sizeof(alloc));
for (int i = 0; i < n; i++) {
int bestIdx = -1;
for (int j = 0; j < m; j++) {
if (bsize[j] >= psize[i]) {
if (bestIdx == -1)
bestIdx = j;
else if (bsize[bestIdx] > bsize[j])
bestIdx = j;
}
}
if (bestIdx != -1) {
alloc[i] = bestIdx;
bsize[bestIdx] -= psize[i];
}
}
cout<<"Best Fit"<<endl;
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++) {
cout << " " << i + 1 << "\t\t\t\t" << psize[i] << "\t\t\t\t";
if (alloc[i] != -1)
cout << alloc[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main() {
int bsize[] = {100, 500, 200, 300, 400};
int psize[] = {112, 518, 110, 526};
int m = sizeof(bsize) / sizeof(bsize[0]);
int n = sizeof(psize) / sizeof(psize[0]);
bestFit(bsize, m, psize, n);
return 0;
}
(iii) WORST FIT
#include<bits/stdc++.h>
using namespace std;
void worstFit(int blockSize[], int m, int processSize[], int n) {
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < n; i++) {
int wstIdx = -1;
for (int j = 0; j < m; j++) {
if (blockSize[j] >= processSize[i]) {
if (wstIdx == -1)
wstIdx = j;
else if (blockSize[wstIdx] < blockSize[j])
wstIdx = j;
}
}
if (wstIdx != -1) {
allocation[i] = wstIdx;
blockSize[wstIdx] -= processSize[i];
}
}
cout<<"Worst Fit"<<endl;
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++) {
cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main() {
int blockSize[] = {100, 500, 200, 300, 600};
int processSize[] = {212, 417, 112, 426};
int m = sizeof(blockSize) / sizeof(blockSize[0]);
int n = sizeof(processSize) / sizeof(processSize[0]);
worstFit(blockSize, m, processSize, n);
return 0;
}
