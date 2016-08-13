compresor: main.o  huffman.o lector.o
	gcc -o compresor main.o  huffman.o lector.o
main.o: main.c  huffman.h lector.h
	gcc -c main.c
huffman.o: huffman.c huffman.h
	gcc -c huffman.c
lector.o: lector.c lector.h
	gcc -c lector.c
clean:
	rm main.o  huffman.o lector.o
