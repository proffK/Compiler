#ifndef PK_LEX
#define PK_LEX

#include "token.h"
#include <stdio.h>

token* lexical_analize(FILE* inp);

char* create_buffer(FILE* inp);

void space_checker(void);

#endif

