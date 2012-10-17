brute: brute.c
	gcc -obrute brute.c

test: brute
	./brute 1 2 3

verify: brute
	@echo "--- 1 ---"
	@./brute 1 | sort | wc -l
	@./brute 1 | sort | uniq | wc -l
	@echo "--- 2 ---"
	@./brute 1 2 | sort | wc -l
	@./brute 1 2 | sort | uniq | wc -l
	@echo "--- 3 ---"
	@./brute 1 2 3 | sort | wc -l
	@./brute 1 2 3 | sort | uniq | wc -l
	@echo "--- 4 ---"
	@./brute 1 2 3 4 | sort | wc -l
	@./brute 1 2 3 4 | sort | uniq | wc -l
	@echo "--- 5 ---"
	@./brute 1 2 3 4 5 | sort | wc -l
	@./brute 1 2 3 4 5 | sort | uniq | wc -l
	@echo "--- 6 ---"
	@./brute 1 2 3 4 5 6 | sort | wc -l
	@./brute 1 2 3 4 5 6 | sort | uniq | wc -l

.PHONY: test verify
