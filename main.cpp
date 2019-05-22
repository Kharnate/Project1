// ctrl + alt + l for style
#include <iostream>
#include <fstream> // Stream class to both read and write from/to files.
#include <string>

//Prototype
void sayHello();

void printSum(int, int);

int calculateSum(int, int);

int showMenu();

int main() {

    std::cout << "Production Line Tracker" << std::endl << std::endl;
    //Week 1: Procedural Project 1: repl.it
    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Music Player" << std::endl;
    std::cout << "4. Add Movie Player" << std::endl;
    std::cout << "5. Display Production Statistics" << std::endl;
    std::cout << "6. Exit" << std::endl;
    //Week 1 end

    //Week 2: Procedural Project 2a
     int n;
     std::cout << "Enter a Number: ";
     std::cin >> n;

     if (n==6) {
         showMenu();
     }
     while (n>0 && n<6) {
         std::cout << "Produce Items Stub" << std::endl;
         std::cout << "Enter a Number: ";
         std::cin >> n;
         if(n == 6) {
             showMenu();
         }
     }
     while (n >6){
         std::cout << "Not a valid Selection" << std::endl;
         std::cout << "Enter a Number: ";
         std::cin >> n;
         if(n == 6) {
             showMenu();
         }
     }

    //Class Activity 05/20: Functions
    sayHello();
    int num1 = 2;
    int num2 = 3;
    printSum(num2, num2); //Sending values to printSum
    std::cout << "num1 in main is " << num1 << std::endl;
    int sum = calculateSum(num1, num2);
    std::cout << "The sum is " << sum << std::endl;

    // Files
    std::ofstream myOutputFile;
    myOutputFile.open("example.txt");
    myOutputFile << "Writing this to a file.\n";
    myOutputFile.close(); //Closes the file
    /*
     * This code creates a filled called example.txt
     * and insert a sentence into it in the same way as count,
     * but using the file stream myfile instead.
     */

    std::string line;
    std::ifstream myInputFile("example.txt");

    if (myInputFile.is_open()) {
        while (getline(myInputFile, line)) { //Reads the file line by line, using getline.
            //Value returned by getline is a reference to the stream object itself
            std::cout << line << std::endl;
        }
        myInputFile.close(); //Closes the file
    } else {
        std::cout << "Unable to open" << std::endl;
    }

    return 0;
}

void sayHello() {
    std::cout << "Hello World!" << std::endl;
}


void printSum(int num1, int num2) {  //Accepting the value from main
    num1 = 10;
    std::cout << "The total in printSum is " << num1 + num2 << std::endl;
}

int calculateSum(int num1, int num2) {
    return num1 + num2;
}

int showMenu () {
        std::cout << "" << std::endl;
        std::cout << "1. Produce Items" << std::endl;
        std::cout << "2. Add Employee Accounts" << std::endl;
        std::cout << "3. Add Music Player " << std::endl;
        std::cout << "4. Add Movie Player" << std::endl;
        std::cout << "5. Display Production Statistics" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "" << std::endl;

        return 0;
    }



