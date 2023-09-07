#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "json.h"

static void JSONSkipWhitespaceI(struct JSONParser *parser)
{
	while (isspace(parser->cbuf[parser->p]))
		parser->p++;
}

static void JSONParseObjectI(struct JSONParser *parser, struct JSONObject *target)
{
	UNUSED(parser);
	UNUSED(target);
}

struct JSONValue *JSONParse(struct JSONParser *parser)
{
	assert(parser != NULL && "NULL parser given");
	assert(parser->cbuf != NULL && "NULL parser buffer");
	assert(parser->cbuf[parser->p] != 0 && "Nothing to parse at all");

	struct JSONValue *root = malloc(sizeof(struct JSONValue));

	while (1)
	{
		JSONSkipWhitespaceI(parser);

		switch (parser->cbuf[parser->p])
		{
		case '{': // Start of an JSONObject
			root->type = JSON_TYPE_OBJECT;
			root->object = malloc(sizeof(struct JSONObject));

			JSONParseObjectI(parser, root->object);
		}
	}

	return root;
}

void JSONFreeObjectI(struct JSONObject *object)
{
	UNUSED(object);
}

void JSONFreeArrayI(struct JSONArray *array)
{
	UNUSED(array);
}

void JSONFree(struct JSONValue *value)
{
	switch (value->type)
	{
	case JSON_TYPE_NULL:
	case JSON_TYPE_NUMBER:
	case JSON_TYPE_STRING:
	case JSON_TYPE_BOOLEAN:
		free(value->data);
		break;
	case JSON_TYPE_OBJECT:
		JSONFreeObjectI(value->object);
		break;
	case JSON_TYPE_ARRAY:
		JSONFreeArrayI(value->array);
		break;
	}

	free(value);
}

