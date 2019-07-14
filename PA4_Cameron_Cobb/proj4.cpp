//Cameron Cobb
//CS202
//Proj4.cpp
//Note: I really hate this project. This was the biggest headache ever

#include <iostream>
#include <fstream>
#include "Car.h"
#include "Agency.h"
#include "Sensors.h"

// at least this project compiles... ;)

void themostexspensivecar(Agency * agency); //hope i make it this far

void readFromFile(Agency *agency); // reads from file... duh

int main(){

    int Input;
    Agency agency;
    int positions[5] = {0,1,2,3,4};
    int selection; // not neccessary
     

    do{
        std::cout << "\n1) Input File Name\n2) Print \n3) Number of Sensors\n4) Most Expensive Car\n5) Exit" << std::endl;
        std::cout << "Please choose an option from above: ";
        std::cin >> Input;
        std::cout << std::endl;
        switch(Input){
            case 1: readFromFile(&agency);
                    break; 
            case 2: agency.printData(); //prints all the date to the screen
                    break;
            case 3: 
                    break;
            case 4: 
                    break;
            case 5: exit(1);
        }
    }while(Input != 5);
    return 0;
}
void readFromFile(Agency *agency)
{
    char sourceFilename[100];
    std::cout << "Please enter source file name with extension: ";
    std::cin >> sourceFilename;
    std::cout << '\n';
    std::ifstream source_file;
    source_file.open(sourceFilename);
    if(!source_file)
    {
        std::cout << "Error opening file\n";
    }
    else
    {
        agency->readData(source_file);
    }

    return;
}