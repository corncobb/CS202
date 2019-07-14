output: proj6.o Vehicle.o Car.o
	g++ proj6.o Vehicle.o Car.o -o output

proj6.o: proj6.cpp
	g++ -c proj6.cpp

Vehicle.o: Vehicle.cpp
	g++ -c Vehicle.cpp

Car.o: Car.cpp
	g++ -c Car.cpp

target: dependencies
	action

clean:
	rm *.o output
