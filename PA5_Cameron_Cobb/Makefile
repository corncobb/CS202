output: proj5.o Vehicle.o Car.o
	g++ proj5.o Vehicle.o Car.o -o output

proj5.o: proj5.cpp
	g++ -c proj5.cpp

Vehicle.o: Vehicle.cpp
	g++ -c Vehicle.cpp

Car.o: Car.cpp
	g++ -c Car.cpp

target: dependencies
	action

clean:
	rm *.o output
