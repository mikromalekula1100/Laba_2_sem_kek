TARGET = My_lab_25
CC = g++


$(TARGET) : main.o deq.o node.o
	$(CC) main.o deq.o node.o -o $(TARGET)

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

deq.o : deq.cpp
	$(CC) -c deq.cpp -o deq.o

node.o : node.cpp
	$(CC) -c node.cpp -o node.o
