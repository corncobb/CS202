output: ArrayList.o DataType.o NodeList.o proj8.o
	g++ ArrayList.o DataType.o NodeList.o proj8.o -o output

proj8.o: proj8.cpp
	g++ -c proj8.cpp

ArrayList.o: ArrayList.cpp
	g++ -c ArrayList.cpp

DataType.o: DataType.cpp
	g++ -c DataType.cpp

NodeList.o: NodeList.cpp
	g++ -c NodeList.cpp

target: dependencies
	action

clean:
	rm *.o output
