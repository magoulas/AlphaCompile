all: lex , bison , gcc

lex: al.l
	lex --outfile=al.c al.l
bison: parserM.y
	bison --yacc --defines --output=parser.c parserM.y
gcc: al.c parser.c Table.h P3M.h
	gcc -o scannerM al.c parser.c Table.h P3M.h
clean:
	rm scannerM
	rm al.c
	rm parser.c
	rm parser.h




