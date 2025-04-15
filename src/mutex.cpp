#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex carMutex;

void driveCarLockGuard(string driverName) {
    lock_guard<mutex> carLock(carMutex);
    cout << driverName << " is driving " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " is done driving " << endl;
}

void driveCarUniqueLock(string driverName) {
    unique_lock<mutex> carLock(carMutex);
    cout << driverName << " is driving " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " is done driving " << endl;
    carLock.unlock();
}

int main()
{
    thread t1(driveCarLockGuard, "json");
    thread t2(driveCarLockGuard, "xml");

    // before ending the program, make sure that both threads finish working
    t1.join();
    t2.join();

    thread t3(driveCarUniqueLock, "yaml");
    thread t4(driveCarUniqueLock, "csv");

    // before ending the program, make sure that both threads finish working
    t3.join();
    t4.join();
}