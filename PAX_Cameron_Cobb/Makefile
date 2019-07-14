output: projX.o DataType.o SmartPtr.o
	g++ projX.o DataType.o SmartPtr.o -o output

Driver.o: projX.cpp
	g++ -c projX.cpp

DataType.o: DataType.cpp
	g++ -c DataType.cpp

SmartPtr.o: SmartPtr.cpp
	g++ -c SmartPtr.cpp

target: dependencies
	action

clean:
	rm *.o output
