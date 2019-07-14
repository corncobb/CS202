//Cameron Cobb
//CS202
//1/30/2019

#include <iostream>
#include <fstream>

#define row 10 //Initilizing the row and word size to 10
#define word 10


void myStringCopy(char destination[], const char source[]);

int myStringLength(const char str []);

int myStringCompare(const char str1[], const char str2[]);

void printNames(char NameArr[][word], int position[]);

void SortLenghtNames(char NameArr[][word], int position[]);

void SwapNamesArr(char NameArr[][word], int position[], int a, int b);

void alphabetize(char NameArr[][word], int position[]);

void logtofile(std::ofstream& outfile, char NameArr[][word], int position[]);

int main(){
    char InputFileName[20];
    char OutputFileName[20];
    char NameArr[row][word];
    int numberOfNames;
    int position[10] = {0,1,2,3,4,5,6,7,8,9};
    
    std::cout << "Full input file name with entension: ";
    std::cin >> InputFileName;
    std::cout << "Full output file name with extenstion:  ";
    std::cin >> OutputFileName; 
    std::ifstream infile;
    std::ofstream outfile (OutputFileName);
    infile.open(InputFileName);

    if(!infile){
        std::cout<<"Error finding file" << std::endl;
        system("pause");
        exit(-1);
    }
    
   
    int i = 0;
    while(!infile.eof()){
            infile >> NameArr[i];
            i++;
        
    }
    infile.close(); //closes file
        
    std::cout << "\nUnsorted Data (Original Input Order and Name)\n=============================" << std::endl;
    outfile << "\nUnsorted Data (Original Input Order and Name)\n=============================" << std::endl;
    printNames(NameArr, position);
    logtofile(outfile, NameArr, position);

    std::cout << "\nSorted-by-Length Data (Original Input Order and Name)\n=============================" << std::endl;
    outfile << "\nSorted-by-Length Data (Original Input Order and Name)\n=============================" << std::endl;
    SortLenghtNames(NameArr, position);
    printNames(NameArr, position);
    logtofile(outfile, NameArr, position);

    std::cout << "\nAlphabetically Sorted Data (Original Input Order and Name)\n=============================" << std::endl;
    outfile << "\nAlphabetically Sorted Data (Original Input Order and Name)\n=============================" << std::endl;
    alphabetize(NameArr, position);
    printNames(NameArr, position);
    logtofile(outfile, NameArr, position);


    
    
    return 0;
}

void SwapNamesArr(char NameArr[][word], int position[], int a, int b){ //swaps name strings with another
    char tempvar[word];
    int tempint = position[b];
    myStringCopy(tempvar, NameArr[b]);
    myStringCopy(NameArr[b], NameArr[a]);
    myStringCopy(NameArr[a], tempvar);
    position[b] = position[a];
    position[a] = tempint;
}

void myStringCopy(char destination[], const char source[]){ //Copies one string to the other string
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // add '\0' at the end
    //return destination;

}

int myStringLength(const char str []){ //finds string length
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int myStringCompare(const char str1[], const char str2[]){ //compares string length
    for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++){
		int val1 = str1[i], val2 = str2[i];
		if(val1 >= 97){
            val1 -= 32;
         }else{
             val1 -= 0;
             }
        if(val2 >= 97){
            val2 -= 32;
         }else{
             val1 -= 0;
             }
        if (val1 > val2){
			return 1;
		}else if (val1 < val2){
			return -1;
		}

    }
    return 0;
}


void printNames(char NameArr[][word], int position[]){ //prints names... duh

        for (int i = 0; i < row; i++){
            std::cout << position[i] << ' ' << NameArr[i] << std::endl;
        }
    }

void alphabetize(char NameArr[][word], int position[]){ //alphabatizes names
	for (int i = 0; i < row; i++){
        for (int j = 0; j < row - 1; j++){
            if(myStringCompare(NameArr[j], NameArr[j+1]) == 1){
                SwapNamesArr(NameArr, position, j, j+1);
            }
        }
    }
}

void SortLenghtNames(char NameArr[][word], int position[]){ //sorts stings by length
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row - i - 1; j++){
            if(myStringLength(NameArr[j]) > myStringLength(NameArr[j+1])){
                SwapNamesArr(NameArr, position, j, j+1);

            }

        }

    }

}
void logtofile(std::ofstream& outfile, char NameArr[][word], int position[]){
    for (int i = 0; i < row; i++){
        outfile << position[i] << ' ' << NameArr[i] << '\n'; //Basically puts everything in the file... duh
    }
}