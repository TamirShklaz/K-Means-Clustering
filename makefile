PROG = bin/*

OBJS = obj/*
INCLUDE = -ITools
.PHONY: clean As2 run
all:    clean As2 run

CC = g++

As2:
	$(CC) -c main.cpp -o ./bin/main.o
	$(CC) -c Cluster.cpp -o ./bin/Cluster.o
	$(CC) -c Point.cpp -o ./bin/Point.o
	$(CC) -o bin/As2 bin/main.o bin/Cluster.o bin/Point.o

run:
	bin/As2