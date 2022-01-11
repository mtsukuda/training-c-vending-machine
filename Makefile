CC= cc
CFLAGS= -std=c99 -pedantic -Wall
OBJECTS= vm.o
all: vm
vm.o: vm.c
	$(CC) $(CFLAGS) -c vm.c
vm: $(OBJECTS)
	$(CC) $(OBJECTS) -o vm
clean:
	rm -f *.o vm
