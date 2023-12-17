Experiment – 8
Aim – WAP to implement Optimal Page Replacement Algorithm.
Code –
#include<bits/stdc++.h>
using namespace std;
int findMinPage(const int refstr[], const unordered_set<int>& pages, int index) {
int minPage = 0, minCount = INT_MAX;
for (auto it = pages.begin(); it != pages.end(); it++) {
int count = 0;
for (int j = index; j < 12; j++) {
if (refstr[j] == *it) count++;
}
if (count < minCount) {
minCount = count;
minPage = *it;
}
}
return minPage;
}
void printPages(const unordered_set<int>& pages) {
for (auto it = pages.begin(); it != pages.end(); it++) {
cout << *it << " ";
}
cout << endl;
}
int main() {
unordered_set<int> pages;
int size = 4, pageFaults = 0;
int refstr[] = {2, 5, 1, 3, 7, 3, 4, 2, 1, 5, 3, 4};
cout << "Optimal Page Replacement Algorithm - "<<endl;
for (int i = 0; i < 12; i++) {
if (pages.find(refstr[i]) == pages.end()) {
if (pages.size() == size) {
pageFaults++;
int minPage = findMinPage(refstr, pages, i + 1);
pages.erase(pages.find(minPage));
pages.insert(refstr[i]);
printPages(pages);
} else {
pages.insert(refstr[i]);
printPages(pages);
}
}
}
cout << "No. of page faults: " << pageFaults << endl;
return 0;
}
