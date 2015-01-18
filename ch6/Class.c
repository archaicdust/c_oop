#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

#include "Object.r"


static void * Class_dtor(void *_self)
{
    struct Class *self = _self;

    fprintf(stderr, "%s: cannot destroy class\n", self->name);
    return 0;
}


const void * super(const void *_self)
{
    const struct Class *self = _self;

    assert(self && self->super);
    return self->super;
}


static void * Class_ctor(void *_self, va_list *app)
{
    struct Class *self = _self;

    self->name = va_arg(*app, char*);
    self->super = va_arg(*app, struct Class *);
    self->size = va_arg(*app, size_t);
    assert(self->super);

    const size_t offset = offsetof(struct Class, ctor);
    /* ... */
    memcpy((char *) self + offset,  (char *) self->super + offset, sizeOf(self->super) - offset);

    {
        typedef void (*voidf) (); /* generic function pointer */

        voidf selector;
        va_list ap = *app;

        while ((selector = va_arg(ap, voidf))
        {
            voidf method = va_arg(ap, voidf);

            if (selector == (voidf) ctor)
                * (voidf *) & self->ctor = method;
            else if (selector == (voidf) dtor)
            * (voidf *) & self->dtor = method;
            else if (selector == (voidf) differ)
            * (voidf *) & self->differ = method;
            else if (selector == (voidf) puto)
            * (voidf *) & self->puto = method;
        }
        return self;
    }
}
