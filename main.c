#include "pk_syn.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char* argv[]){
	FILE* input_file = NULL;
    char* input_file_name = NULL;
	FILE* output_file = NULL;
    char* output_file_name = NULL;
	token* tk = NULL;
    int opt = 0;
    char help_msg[] = 
        "pslc - Proff_K Stupid Language Compiler\n"
        "Usage:\n"
        "-i - input file\n"
        "-o - output file\n"
        "-h - print this message";
	
    while ((opt = getopt(argc, argv, "hi:o:")) != -1) {

        switch (opt) {

            case 'h':
                printf(help_msg);
                return 0;
            case 'i':
                input_file_name = optarg;
                break;
            case 'o':
                output_file_name = optarg;
                break;
            default:
                printf("Unknown option -%c", opt);
                return 1;

        }

    }

    if (optind < argc) {

        printf("Invalid arguments");
        return 2;

    }
	
	input_file = fopen(input_file_name, "r");
	output_file = fopen(output_file_name,  "w");

	tk = lexical_analize(input_file);
	
	if (tk == NULL) {
		
		printf("\nLexical error\n");
		free(tk);
		fclose(input_file);
		fclose(output_file);
		return 3;
		
	}
	else {
		
		printf("Lexical analize complete.\n");
		
	}
	
	if (syntax_analize(tk, output_file)){
		
		printf("\nSyntax error\n");
		free(tk);
		fclose(input_file);
		fclose(output_file);
		return 4;
		
	}
	
	printf("Syntax analize complete.\nParse tree build.\nCompilation complete.\n");
	free(tk);
	fclose(input_file);
	fclose(output_file);

	return 0;
}


