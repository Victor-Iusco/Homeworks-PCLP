CFLAGS=-Wall -Werror

.PHONY: clean run-task1 run-task2

task1: task1.c
	gcc task1.c $(CFLAGS) -o task1
	
run-task1: task1
	./task1


task2: task2.c
	gcc task2.c $(CFLAGS) -o task2
	
run-task2: task2
	./task2
	
clean:
	rm -f task1 task2
