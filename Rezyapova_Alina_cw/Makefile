CC = gcc
FLAGS = -Wall -Wextra -g
TARGET = cw
PATCH = src.patch

OBJECTS = main.o bmp_utility.o drawings.o bmp_reader.o

$(TARGET): $(OBJECTS)
	@$(CC) $(FLAGS) $^ -o $@

main.o: main.c bmp_utility.h bmp_reader.h drawings.h
	@$(CC) $(FLAGS) -c $< -o $@

bmp_utility.o: bmp_utility.c bmp_utility.h bmp_reader.h
	@$(CC) $(FLAGS) -c $< -o $@

drawings.o: drawings.c drawings.h bmp_reader.h
	@$(CC) $(FLAGS) -c $< -o $@

bmp_reader.o: bmp_reader.c bmp_reader.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o $(TARGET) $(PATCH)

patch:
	@git diff --no-prefix main $(shell git branch --show-current) -- $(shell pwd) > $(PATCH)

.PHONY: clean patch
