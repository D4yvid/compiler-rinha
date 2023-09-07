#include <alloca.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <malloc.h>
#include "io.h"
#include "json.h"
#include "types.h"
#include <linux/limits.h>

int main(int argc, char **argv)
{
	i32 size;
	char *buffer;
	struct JSONParser parser;

	if (argc <= 1)
	{
		fprintf(stderr, "Usage: %s <file name>\n", basename(argv[0]));
		return 1;
	}

	size = getfilesize(argv[1]);

	if (size < 0) {
		fprintf(stderr, "Could not read file!\n");
		return 1;
	}

	buffer = alloca(size);
	readfile(argv[1], buffer, size);

	parser.cbuf = buffer;
	parser.p = 0;

	JSONParse(&parser);

	return 0;
}
