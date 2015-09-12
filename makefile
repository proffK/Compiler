CC=gcc
CCFLAGS=-Wall -g
CLEAN=rm -f *.o 
PROGRAM_NAME=pslc
$(PROGRAM_NAME): main.o libsyn.a 
	$(CC) $(CCFLAGS) $^  -o $@ -L. -lsyn
main.o: main.c virtmach
	$(CC) $(CCFLAGS) -c $< 
libsyn.a:token.o pk_lex.o pk_tree.o pk_diff.o pk_syn.o pk_sem.o
	ar rcs $@ $^
pk_syn.o: pk_syn.c 
	$(CC) $(CCFLAGS) -c $< 
pk_tree.o: pk_tree.c
	$(CC) $(CCFLAGS) -c $<
pk_lex.o: pk_lex.c
	$(CC) $(CCFLAGS) -c $<
pk_sem.o: pk_sem.c
	$(CC) $(CCFLAGS) -c $<
pk_diff.o: pk_diff.c
	$(CC) $(CCFLAGS) -c $<
token.o: token.c
	$(CC) $(CCFLAGS) -c $<
virtmach:
	make -C ./StackProc
clean:	
	make -C ./StackProc clean
	$(CLEAN)
