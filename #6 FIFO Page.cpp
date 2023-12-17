Experiment – 6
Aim – To implement FIFO Page Replacement.
Code –
#include <iostream>
using namespace std;
#define FRAMES_NUMBER 3
int FIFO(int pages[], int size)
{
int frames[FRAMES_NUMBER];
for (int i = 0; i < FRAMES_NUMBER; i++)
frames[i] = -1;
int paeFaults = 0;
int victim = 0;
for (int pageIndex = 0; pageIndex < size; pageIndex++)
{
bool isFound = false;
for (int i = 0; i < FRAMES_NUMBER; i++)
if (frames[i] == pages[pageIndex])
{
isFound = true;
cout << pages[pageIndex] << endl;
break;
}
if (!isFound)
{
bool hasFreeFrame = false;
for (int i = 0; i < FRAMES_NUMBER; i++)
if (frames[i] == -1)
{
hasFreeFrame = true;
frames[i] = pages[pageIndex];
paeFaults++;
cout << pages[pageIndex] << "\t\t";
for (int f = 0; f < FRAMES_NUMBER; f++)
cout << frames[f] << "\t";
cout << endl;
break;
}
if (!hasFreeFrame)
{
frames[victim] = pages[pageIndex];
victim = (victim + 1) % FRAMES_NUMBER;
paeFaults++;
cout << pages[pageIndex] << "\t\t";
for (int f = 0; f < FRAMES_NUMBER; f++)
cout << frames[f] << "\t";
cout << endl;
}
}
}
return paeFaults;
}
int main(int argc, char const *argv[])
{
int pages[] = {1, 2, 3, 1, 4, 5, 2, 1, 2, 6, 7, 3, 2};
cout << "Number Of Page Faults = " << FIFO(pages, 13);
getchar();
return 0;
}
