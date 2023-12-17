Experiment – 7
Aim – WAP to implement LRU Page Replacement Algorithm.
Code –
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
int faults = 0;
int hits = 0;
int tableSize = 4;
int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2};
int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);
list<int> pages;
for (int i = 0; i < referenceStringLength; ++i) {
auto it = find(pages.begin(), pages.end(), referenceString[i]);
if (it != pages.end()) {
pages.erase(it);
pages.push_back(referenceString[i]);
} else {
if (pages.size() < tableSize) {
pages.push_back(referenceString[i]);
} else {
pages.pop_front();
pages.push_back(referenceString[i]);
}
faults += 1;
}
}
hits = referenceStringLength - faults;
cout << "LRU Page Replacement Algorithm - "<< endl;
cout << "Total page faults = " << faults << endl;
cout << "Total page Hits = " << hits << endl;
return 0; }
