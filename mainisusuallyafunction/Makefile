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

gcc_no_warning:
	gcc -Wall -O0 -static -s -DNO_WARNING -o gcc_mainarray mainarray.c

clang_no_warning:
	clang -Wall -O0 -static -s -DNO_WARNING -o mainarray mainarray.c

run: all
	./mainarray
