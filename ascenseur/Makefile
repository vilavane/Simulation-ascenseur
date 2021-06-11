FLAGS = -Wall -Werror -g

all: main 

main.o: main.c
	gcc ${FLAGS} -o main.o -c main.c

person.o: person.c person.h
	gcc ${FLAGS} -o person.o -c person.c

elevator.o: elevator.c elevator.h person.h
	gcc ${FLAGS} -o elevator.o -c elevator.c

main: main.o elevator.o person.o 
	gcc ${FLAGS} -o main main.o elevator.o person.o -lncurses

clean:
	rm -f *.o ./main

