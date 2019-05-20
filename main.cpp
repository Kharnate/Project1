#include <iostream>

//Prototype
void sayHello ();
void printSum(int, int);
int calculateSum (int, int);

int main() {
    std::cout << "Hello, World!" << std::endl;

    //Week 1: Procedural Project 1: repl.it
    std::cout << "Production Line Tracker" << std::endl;
    std::cout << ""<< std::endl;
    std::cout << "1. Add Employee Account" << std::endl;
    std::cout << "2. Add Music Player" << std::endl;
    std::cout << "3. Add Movie Player" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout <<"5. Exit";
    //Week 1 end

    //Class Activity 05/20
    sayHello();
    int num1 = 2;
    int num2 = 3;
    printSum (num2, num2); //Sending values to printSum
    std::cout << "num1 in main is " << num1 << std::endl;
    int sum = calculateSum (num1, num2);
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}

void sayHello(){
    std::cout << "Hello World!"<<std::endl;
}


void printSum (int num1, int num2) {
    num1 = 10;
    std::cout << "The total in printSum is " << num1+num2 << std::endl;

}

int calculateSum (int num1, int num2) {
    return num1 + num2;
}