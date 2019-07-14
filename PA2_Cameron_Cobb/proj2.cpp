//Cameron Cobb
//CS202
//Proj2.cpp


#include <iostream>
#include <fstream>

#define MAXSIZE 11 // Im lazy. Dont want to type "11" a lot

struct Cardata {        //struct that will store the car data
    int year;
    char make[MAXSIZE];
    char model[MAXSIZE];
    float price;
    bool available;
};

void readFromFile(Cardata * arrayforcars);

void printtofile(Cardata * arrayforcars);

void printfromstruct(Cardata * arrayforcars);

void sortbyprice(Cardata * arrayforcars, int * positions);

size_t myStringLength(const char*str);

int myStringCompare(const char*str1, const char*str2);

char *myStringCopy(char* destination, const char* source);

char *myStringCat(char* destination, const char* source);

void swapCars(Cardata * a, Cardata * b);

void howmanydays(Cardata * arrayforcars, int * positions);

void pickacartorent(Cardata * arrayforcars, int * positions);

int main(){

    int Input;
    Cardata arrayforcars[10]; //array of structs
    //Cardata * passedstruct;
    int positions[5] = {0,1,2,3,4};
     

    do{
        std::cout << "\n1) Input File Name\n2) Print \n3) Copy Data Into New File\n4) Sort (ascending order)\n5) Price by Day Estimator\n6) Pick a Car \n7) Exit" << std::endl;
        std::cout << "Please choose an option from above: ";
        std::cin >> Input;
        std::cout << std::endl;
        switch(Input){
            case 1: readFromFile(arrayforcars);
                    break; 
            case 2: printfromstruct(arrayforcars);
                    break;
            case 3: printtofile(arrayforcars);
                    break;
            case 4: sortbyprice(arrayforcars, positions);
                    break;
            case 5: howmanydays(arrayforcars, positions);
                    break;
            case 6: pickacartorent(arrayforcars, positions);
                    break;
            case 7: exit(1);
        }
    }while(Input != 7);
    return 0;
}
void readFromFile(Cardata * arrayforcars){
    char inFileName[20];  // size of only 20 characters
    std::cout << "Full input file name with extension: ";
    std::cin >> inFileName;
    std::ifstream infile;
    infile.open(inFileName);

    if(!infile){
        std::cout<<"Error finding file" << std::endl;
        system("pause");
        exit(-1);
    }

   for(int i = 0; i < 5; i++){
            infile >> arrayforcars[i].year; //reads the first and puts into struct
            infile >> arrayforcars[i].make;
            infile >> arrayforcars[i].model;
            infile >> arrayforcars[i].price;
            infile >> arrayforcars[i].available;
    }

    infile.close(); //closes file
    std::cout << "Data has been successfully read from file and stored." << std::endl;

}

void printfromstruct(Cardata * arrayforcars){
    for(int i = 0; i < 5; i++){
            std::cout << "[" << i << "] ";
            std::cout << arrayforcars[i].year << " "; //reads the first and puts into struct
            std::cout << arrayforcars[i].make << " ";
            std::cout << arrayforcars[i].model << ", ";
            std::cout << "$" << arrayforcars[i].price << " per day, ";
            std::cout << "Available: " << std::boolalpha << arrayforcars[i].available << std::endl << std::endl;
    }
}

void printtofile(Cardata * arrayforcars){       //print the contents to a new filw
    char outFileName[20];  // size of only 20 characters
    std::cout << "Full output file name with extension: ";
    std::cin >> outFileName;
    std::ofstream outfile;
    outfile.open(outFileName);

        for(int i = 0; i < 5; i++){
            outfile << arrayforcars[i].year << " "; //reads the first and puts into struct
            outfile << arrayforcars[i].make << " ";
            outfile << arrayforcars[i].model << " ";
            outfile << arrayforcars[i].price << " ";
            outfile << arrayforcars[i].available << std::endl;
        }

    std::cout << "Data has been written to: " << outFileName << std::endl;
}

void sortbyprice(Cardata * arrayforcars, int * positions){ //sorting by price... duh...
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i - 1; j++){
            if(arrayforcars[j+1].price < arrayforcars[j].price){
                int tempInt = positions[j+1];
                positions[j+1] = positions[j];
                positions[j] = tempInt;

                swapCars(&arrayforcars[j+1], &arrayforcars[j]);
            } 
        }
    }
    std::cout<< "\nData has been sorted by ascending price." << std::endl;
    //printfromstruct(arrayforcars);
}
 
void swapCars(Cardata * a, Cardata * b){ //LOOK!! Its a swap function... again
    Cardata temp = *a;
    *a = *b;
    *b = temp;
}

void howmanydays(Cardata * arrayforcars, int * positions){
    int numdays;
    std::cout << "Enter the amount of days you want to rent a car: ";
    std::cin >> numdays;

    sortbyprice(arrayforcars, positions);
    
    for(int i = 0; i < 5; i++){
        if(arrayforcars[i].available > 0){
            std::cout << "[" << i << "] ";
            std::cout << arrayforcars[i].year << " "; //reads the first and puts into struct
            std::cout << arrayforcars[i].make << " ";
            std::cout << arrayforcars[i].model << ", ";
            std::cout << "Total Cost: $" << arrayforcars[i].price * numdays << std::endl << std::endl;
            //std::cout << "Available: " << std::boolalpha << arrayforcars[i].available << std::endl;
        }
    }
}

void pickacartorent(Cardata * arrayforcars, int * positions){ //Picks a car to rent function... duh
    int selection = -1;
    int days;
    printfromstruct(arrayforcars);
    do{
        std::cout << "Pick a car to rent (Choose by index number): ";
        std::cin >> selection;

        if(selection > 4 || selection < 0){
             std::cout << "Index is not in range. Pick a different selection." << std::endl;
        }
        else if(arrayforcars[selection].available == 0){
            std::cout << "CANNOT RENT THIS CAR! OUT OF STOCK! PLEASE CHOOSE A DIFFERENT CAR!" << std::endl; 
        }
    }while((selection > 4 || selection < 0) || arrayforcars[selection].available == 0); // Makes sure indexed number is not out of range and also if the car is availible!

    std::cout << "Enter amount of days you will rent the car: ";
    std::cin >> days;
    arrayforcars[selection].available = 0;
    std::cout << "***SUCCESS***" << std::endl;
    std::cout << "You rented: " << arrayforcars[selection].year << " "
    << arrayforcars[selection].make << " "
    << arrayforcars[selection].model << "\n\n"
    << "Total cost: $" << arrayforcars[selection].price * days << std::endl;


}

size_t myStringLength(const char*str){ //why would this function be needed????
    int length = 0;
    for (; str[length] != '\0'; length++) continue;

    return length * sizeof(char);

}

int myStringCompare(const char*str1, const char*str2){ //why would this function be needed for this project also?
    for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++){
		int val1 = str1[i], val2 = str2[i];
		(val1 >= 97)? val1 -= 32 : val1 -= 0;
		(val2 >= 97)? val2 -= 32 : val1 -= 0;
		if (val1 > val2){
			return 1;
		}else if (val1 < val2){
			return -1;
		}
	}
    return 0;
}

char *myStringCopy(char* destination, const char* source){ //why would I use this function also???!!!
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
}

char *myStringCat(char*destination, const char* source){ //This was taken from past CS135 project
    char *start = destination;

    while(*destination != '\0'){
        destination++;
    }

    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start; 
}
