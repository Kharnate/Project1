// ctrl + alt + l for style
#include <iostream>
#include <fstream> // Stream class to both read and write from/to files.
#include <string>

//Prototype
int showMenu();

void getChoice();

bool continueProgram = true;

int main() {


    //Week 1: Procedural Project 1: repl.it
    std::cout << "Production Line Tracker" << std::endl << std::endl;
    showMenu();
    //Week 1 end

    //Week 2: Procedural Project 2a
    std::cout << "Production Line Tracker" << std::endl;
    std::cout << "" << std::endl;

    do {
        showMenu();
        getChoice();
    } while (continueProgram);



    // Files
    std::ofstream myOutputFile;
    myOutputFile.open("example.txt");
    myOutputFile << "\n\nWriting this to a file.\n";
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


int showMenu() {

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Music Player" << std::endl;
    std::cout << "4. Add Movie Player" << std::endl;
    std::cout << "5. Display Production Statistics" << std::endl;
    std::cout << "6. Exit" << std::endl;

    std::cout << "" << std::endl;

    return 0;
}

void getChoice() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1 :
            std::cout << "Produce Items Stub" << std::endl; //After selecting 1 from the the main menu - showMenu()
            break;
        case 2 :
            std::cout << "Add Employee Account Stub" << std::endl; //Similar as case 1 to case 5
            break;
        case 3 :
            std::cout << "Add Music Player Stub" << std::endl;
            break;
        case 4 :
            std::cout << "Add Movie Player Stub" << std::endl;
            break;
        case 5 :
            std::cout << "Dispplay Production Statistics Stub" << std::endl;
            break;
        case 6:
            continueProgram = false; //When the user enters 6, the do-while ends nad returns to main menu
            break;
        default:
            std::cout << "Not a valid selection" << std::endl;
    }
}


