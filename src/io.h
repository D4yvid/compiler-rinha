#ifndef IO_H
#define IO_H

#include "types.h"

void readfile(char *path, char *buffer, i32 size);
i32 getfilesize(char *path);

i32 spawncmd(char *program);

#endif /** IO_H */
