#include "vector.h"

Vector* Vector_new(void)
{
	Vector* v = malloc(sizeof(Vector));
	v->ptr = NULL;
	v->length = 0;
	return v;
}

void Vector_free(Vector* v)
{
	free(v->ptr);
	free(v);
}

void Vector_impl_grow(Vector* v, size_t size)
{
	++(v->length);
	v->ptr = realloc(v->ptr, v->length * size);
}

size_t Vector_len(Vector* v)
{
	return v->length;
}
