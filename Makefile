CC=g++
CFLAGS="-I. -g -Wfatal-errors --std=c++11"
DEPS = vehicle.h car.h
OBJ = vehicle.o car.o testDrive.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testDrive: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
