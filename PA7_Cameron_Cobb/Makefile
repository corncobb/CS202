output: MyString.o proj7.o
	g++ MyString.o proj7.o -o output

proj7.o: proj7.cpp
	g++ -c proj7.cpp

MyString.o: MyString.cpp
	g++ -c MyString.cpp

target: dependencies
	action

clean:
	rm *.o output
