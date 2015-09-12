#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "stk_processors.h"
#include "resourses.h"
#include <assert.h>

#define ARG_TO_INT(argument) if (!(sscanf(optarg, "%d",\
									&(argument)))) {\
					printf("Invalid argument\n%s", help_msg);\
					return 2;\
				}

int main(int argc, char* argv[]){
	int opt = 0;
	FILE* firmware_file = 0;
	char* firmware_file_name = NULL;
	double* firmware = 0;
	long firmware_size = 0;
	char sign[2] = {};
	processor* proc = NULL;
	char help_msg[] = 
	"Written by Proff_K:\n"
	"PKvirtmach - simple stack base virtual machine\n"
	"default parameters in resourses.h\n"
	"Usage:\n"
	"PKvirtmach -imsrh flash.kvm\n"
	"-i - input file\n"
	"-m - processors memory size\n"
	"-s - processors stack size\n"
	"-r - processors number of registers\n"
	"-h - print this message\n";
	
	while ((opt = getopt(argc, argv, "i:m:s:r:h")) != -1) {
		
		switch (opt) {
			
			case 'h':
				printf(help_msg);
				return 0;
			case 'i':
				firmware_file_name = optarg;
				break;
			case 's':
				ARG_TO_INT(PROCESSOR_STACK_SIZE);
				break;
			case 'm':
				ARG_TO_INT(PROCESSOR_MEMORY);
				break;
			case 'r':
				ARG_TO_INT(NUMBER_OF_REGISTORS);
				break;
			default:
				printf(help_msg);
			
		}
	}
		
	if (optind < argc) {
		printf("Invalid options\n");
		printf(help_msg);
		return 1;
	}
	
	if (!(firmware_file = fopen(firmware_file_name, "rb"))) {
		
		printf("Incorrect input file\n");
		return 2;
		
	}

	fread(sign, sizeof(char), 2, firmware_file);
	
	if (sign[0] != 'k' || sign[1] != 'k') {
		
		processor_delete(proc);
		free(firmware);
		
		printf("Incorrect firmware sign\n");
		return 3;
	}
		
	proc = processor_create(PROCESSOR_STACK_SIZE,NUMBER_OF_REGISTORS,\
	PROCESSOR_MEMORY);
	
	assert(proc);
	
	firmware = (double*) calloc (MAX_BYTE_CODE_SIZE, sizeof(double));

	assert(firmware);
	
	firmware_size = fread(firmware, sizeof(double), MAX_BYTE_CODE_SIZE, firmware_file);

	if (processor_flash(proc, firmware, firmware_size)) {
		
		printf("Incorrect firmware\n");
		return 4;
		
	}	

	processor_start(proc, stdin, stdout);

	processor_delete(proc);

	fclose(firmware_file);

	free(firmware);
	return 0;
}
	
	
	
	
 
