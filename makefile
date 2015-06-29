bf+ff2bf.bf: bf+ff2bf bf+ff2bf.bfpff
	./bf+ff2bf -o bf+ff2bf.bf bf+ff2bf.bfpff
bf+ff2bf: bf+ff2bf.c
	gcc -o bf+ff2bf bf+ff2bf.c
clean:
	rm -f bf+ff2bf 
	rm -f bf+ff2bf.bf