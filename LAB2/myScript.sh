	rm -f *.o
    rm runStackWithArray

gcc -c stack_ll.c
gcc -c stackDriver.c
gcc -c linked_list.c
gcc -o runStackWithArray stackDriver.o stack_ll.o linked_list.o
./runStackWithArray