#ifndef JSON_H
#define JSON_H

#include "types.h"

enum JSONValueType
{
	JSON_TYPE_NULL,
	JSON_TYPE_BOOLEAN,
	JSON_TYPE_NUMBER,
	JSON_TYPE_STRING,
	JSON_TYPE_OBJECT,
	JSON_TYPE_ARRAY
};

struct JSONValue
{
	enum JSONValueType type;

	union {
		void *data;

		i8 *boolean;
		f32 *number;
		char *string;

		struct JSONArray *array;
		struct JSONObject *object;
	};
};

struct JSONObjectPair
{
	char key[255];
	struct JSONValue *value;
};

struct JSONArray
{
	struct JSONValue base;
	i32 elemCount;
	struct JSONValue *values;
};

struct JSONObject
{
	struct JSONValue base;
	i32 pairCount;
	struct JSONObjectPair *pairs;
};

struct JSONParser
{
	i32 p;
	char *cbuf;
};

struct JSONValue *JSONParse(struct JSONParser *parser);
void JSONFree(struct JSONValue *value);

#endif /** JSON_H */
