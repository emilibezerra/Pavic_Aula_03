#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <atomic>

//using namespace std;

//unsigned int contador = 0;



std::atomic <unsigned int> contador (0);
std::mutex locker;

void depression_thread() {
	//locker.lock();
	for (int i = 0; i < 5; i++) {
		
		printf("Esperar thread: %d:..\n", std::this_thread::get_id());
		std::cout << "Esperar thread:" << std::this_thread::get_id() << std::endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//locker.lock();
		contador++;
		//locker.unlock();
	}
	//locker.unlock();
}

int main() {
	std::thread thread01(depression_thread);

	std::thread thread02(depression_thread);

	thread01.join();
	thread02.join();

	printf("Contador : %d \n*", contador.load()); //Atomic contador.load()
	std::cout << "Contador" << contador << std::endl;
	//std::cout << "Contador" << std::endl;

}