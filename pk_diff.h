#ifndef PK_DIFF
#define PK_DIFF

#include "pk_tree.h"

node* diff_tree(node* tree, int var, FILE* out);

int tex_dump(node* tree, FILE* out);

node* first_optimize(node* tree, int* end_flag);

int second_optimize(node* tree);

#endif
