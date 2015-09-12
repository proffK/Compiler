CC=gcc
CCFLAGS=-Wall -O2
CLEAN=rm -f *.o 
PROGRAM_NAME=PKvirtmach
$(PROGRAM_NAME): PKvirtmach.o libstack.a libstk_processors.a PK_asm PK_disasm
	$(CC) $(CCFLAGS) $< -o $@ -L. -lstk_processors -lstack -lm
PKvirtmach.o: PKvirtmach.c
	$(CC) $(CCFLAGS) -c $< 
libstk_processors.a: stk_processors.o
	ar rcs $@ $<
stk_processors.o: stk_processors.c 
	$(CC) $(CCFLAGS) -c $<
libstack.a: pk_stack.o
	ar rcs $@ $<
pkstack.o: pk_stack.c
	$(CC) $(CCFLAGS) -c $<
PK_asm: PK_asm.o libstack.a
	$(CC) $(CCFLAGS) $< -o $@ -L. -lstack
PK_asm.o: PK_asm.c
	$(CC) $(CCFLAGS) -c $<
PK_disasm: PK_disasm.o libstack.a
	$(CC) $(CCFLAGS) $< -o $@ -L. -lstack
PK_disasm.o: PK_disasm.c
	$(CC) $(CCFLAGS) -c $<
clean:
	$(CLEAN)
	rm -f *.a
