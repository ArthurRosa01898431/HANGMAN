CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o associative_array.o generic_vector.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o

unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -o unit_test.o -c unit_test.c

test_def.o: test_def.c
	$(CC) $(CFLAGS) -o test_def.o -c test_def.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

generic_vector.o : generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

associative_array.o : associative_array.c
	$(CC) $(CFLAGS) -c associative_array.c -o associative_array.o

clean:
	rm string_driver $(OBJECTS) unit_test unit_test.o test_def.o
