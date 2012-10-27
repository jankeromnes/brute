brute: brute.c
	gcc -obrute brute.c

test: brute
	@a=""
	@for n in 1 2 3 4 5 6 7 8 9 ; do \
	   a="$$a $$n" ; \
	   echo "--- $$n ---" ; \
	   ./brute $$a | wc -l ; \
	   ./brute $$a | sort | uniq | wc -l ; \
	done

.PHONY: test
