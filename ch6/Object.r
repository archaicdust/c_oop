#ifndef GAURD_Object_r
#define GAURD_Object_r


struct Object {
    const struct Class *class;
};

struct Class {
    const struct Object _;      /* class's description */
    const char *name;           /* class's name */
    const struct Class *super;  /* class's super class */
    size_t size;                /* class's objec's size */
    void * (*ctor) (void *self, va_list *app);
    void * (*dtor) (void *self);
    int (*differ) (const void *self, const void *b);
    int (*puto)(const void *self, FILE *fp);
};

#endif

