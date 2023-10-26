runprogram: run_exe
	./run_exe
run_exe: criminality.o
	gcc -o run_exe criminality.o
sortOnHeight.o: sortOnHeight.c
	gcc -c sortOnHeight.c
sortOnName.o: sortOnName.c
	gcc -c sortOnName.c
3sum.o: 3sum.c
	gcc -c 3sum.c
greater.o: greater.c
	gcc -c greater.c
criminality.o: criminality.c
	gcc -c criminality.c
clean:
	rm -f *.o
	rm run_exe