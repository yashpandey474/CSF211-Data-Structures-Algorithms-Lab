rm *.o
rm *exe

gcc -c commaRead.c
gcc -o script_exe commaRead.o
./script_exe