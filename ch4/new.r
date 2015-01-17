#ifndef _GAURD_NEW_R
#define _GAURD_NEW_R

struct Class {
    size_t size;
    void * (*ctor) (void *self, va_list *app);
    void * (*dtor) (void *item);
    void (*draw)(const void *self);
};

#endif

