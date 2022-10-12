
//
#include<iostream>
#include<thread>
using namespace std;

void VontadeDEViver() {
	cout <<"VontadeDEViver thread" << endl;
}

void call_from_thread() {
	cout << "Hello, Wordl" << endl;
}

int main() {
	//Launch a thread

	thread t1(call_from_thread);
	thread VontadeViver(VontadeDEViver);

	thread t2(call_from_thread);
	thread t3(call_from_thread);
	cout << "Hello, World from CPU" << endl;

	VontadeViver.join();

	t1.join();
	t2.join();
	t3.join();
	cout << "Hello, World from CPU - after Join" << endl;

	return 0;
}