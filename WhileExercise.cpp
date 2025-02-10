#include <iostream>
#include <chrono>
#include <thread>

int main(){

    int contador = 0;

    for(int i = 0; i < 10; i++){
        std::cout << "Loading ";
        contador=20*(i+1) /2;
        std::cout << contador << "%" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    }
    return 0;
}