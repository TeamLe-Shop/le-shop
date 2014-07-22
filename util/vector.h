#ifndef UTIL_VECTOR_H
#define UTIL_VECTOR_H

#include <stdlib.h>

typedef struct
{
	void* ptr;
	size_t length;
} Vector;

Vector* Vector_new(void);
void Vector_impl_grow(Vector* v, size_t size);
#define Vector_add(vec, type, item) \
	Vector_impl_grow(vec, sizeof(type)); \
	Vector_at(vec, type, ((vec)->length - 1)) = item;

#define Vector_at(vec, type, index) ((type*)vec->ptr)[(index)]
void Vector_free(Vector* v);
size_t Vector_len(Vector* v);

#endif /* UTIL_VECTOR_H */
