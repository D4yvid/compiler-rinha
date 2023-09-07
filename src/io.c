#include "io.h"
#include "types.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void readfile(char *path, char *buffer, i32 size)
{
	i32 gsize;
	FILE *fp;

	if (access(path, R_OK) != 0) {
		fprintf(stderr, "Could not access file '%s': %s\n", path, strerror(errno));

		return;
	}

	fp = fopen(path, "r");

	if (!fp)
	{
		fprintf(stderr, "Could not open file '%s': %s\n", path, strerror(errno));

		return;
	}

	if ((gsize = fread(buffer, sizeof(char), size, fp)) != size * sizeof(char)) {
		fprintf(stderr, "WARN: Requested %d bytes, got %d bytes in stream %p", size, gsize, (void *) fp);
	}

	*(buffer + size) = 0;

	fclose(fp);
}

i32 getfilesize(char *path)
{
	static struct stat st;

	if (stat(path, &st) != 0)
	{
		fprintf(stderr, "Could not stat file '%s': %s\n", path, strerror(errno));

		return -1;
	}

	return st.st_size;
}

i32 spawncmd(char *program)
{
	FILE *prog = popen(program, "r");

	if (!prog)
	{
		fprintf(stderr, "Could not run '%s': %s\n", program, strerror(errno));

		return -1;
	}

	return pclose(prog);
}
