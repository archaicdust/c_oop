#ifndef GAURD_Object_h
#define GAURD_Object_h

#include <stdio.h>

extern const void *Object; /* new(Object); */

extern const void *Class; /* new(Class, "name", super, size, sel, meth, ...0); */

void * new(const void *class, ...);

void delete(void *self);

int differ(const void *self, const void *b);

int puto(const void * self, FILE *fp);

void * ctor(void *self, va_list *app);
void * dtor(void *self);


const void * classOf(const void *self);
size_t sizeOf(const void *self);


#endif

