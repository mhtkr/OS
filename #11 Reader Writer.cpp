Experiment – 11
Aim – WAP to implement Reader Writer Problem.
Code –
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
std::mutex mtx;
std::condition_variable cv;
int readCount = 0;
int writeCount = 0;
void reader() {
std::unique_lock<std::mutex> lock(mtx);
while (writeCount > 0) {
cv.wait(lock);
}
readCount++;
std::cout << "Reader is reading" << std::endl;
readCount--;
cv.notify_one();
}
void writer() {
std::unique_lock<std::mutex> lock(mtx);
while (readCount > 0 || writeCount > 0) {
cv.wait(lock);
}
writeCount++;
std::cout << "Writer is writing" << std::endl;
writeCount--;
cv.notify_one();
}
int main() {
std::thread reader1(reader);
std::thread reader2(reader);
std::thread writer1(writer);
std::thread writer2(writer);
reader1.join();
reader2.join();
writer1.join();
writer2.join();
return 0;
}
