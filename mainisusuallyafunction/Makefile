.PHONY: clang gcc all

all: clang gcc

gcc:
	@echo "GCC Compilation:"
	@echo "================"
	gcc -Wall -O0 -static -s -o gcc_mainarray mainarray.c

clang:
	@echo "Clang Compilation:"
	@echo "=================="
	clang -Wall -O0 -static -s -o mainarray mainarray.c

run: all
	./mainarray
