runStackWithArray: stack_exe
	./stack_exe
stack_exe: stackDriver.o stack_ll.o linked_list.o mt.o
	gcc -o stack_exe stackDriver.o stack_ll.o linked_list.o mt.o
mt.o: mt.c
	gcc -c mt.c
stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c
stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c
stack_ll.o: stack_ll.c stack.h
	gcc -c stack_ll.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
clean:
	rm -f *.o
	