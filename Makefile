CC=clang-6.0 -std=c99
CL=clang-6.0 --coverage
CFLAGS=-O0 -g -lcmocka
LDFLAGS=-O3



all: clean queens test_main test_queens


queens.o:queens.c queens.h
	$(CC) -c -o queens.o queens.c $(LDFLAGS)


queens:main.c queens.o
	$(CC) -o queens main.c queens.o $(LDFLAGS)



test_main:main.c queens.o
	$(CC) -o test_main test_main.c $(CFLAGS)

test_queens:test_queens.o
	$(CC) -o test_queens test_queens.c $(CFLAGS)


perf:measure.c queens.o
	$(CC) -o perf measure.c queens.o $(LDFLAGS)	



%.o: %.c
	$(CC) -o $@ $< $(CFLAGS)

check: test_main test_queens
	./test_main
	./test_queens

couverture: clean all
	$(CL) test_queens.c -o test_queens $(CFLAGS)
    
	./test_queens
	./test_main
	llvm-cov-6.0 gcov -f -b test_queens test_main

graph:
	python3 plot.py


clean:
	rm -f *.o test_queens test_main queens *.gcov *.gcda *.gcno

.PHONY: clean
