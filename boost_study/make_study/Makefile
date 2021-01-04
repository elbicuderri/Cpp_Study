
CC=g++
CFLAGS=-g -Wall

all: study1

# study1: study_1.cpp
# 	$(CC) $(CFLAGS) -I /usr/local/boost_1_75_0/include -L /usr/local/boost_1_75_0/lib -o study1 study_1.cpp

study1.o: study_1.cpp
	$(CC) $(CFLAGS) -c study_1.cpp

study1: study1.o
	$(CC) $(CFLAGS) -o study1 -I /usr/local/boost_1_75_0/include -L /usr/local/boost_1_75_0/lib study_1.cpp

clean:
	rm study_1.o study1