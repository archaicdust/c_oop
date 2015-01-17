#ifndef _GUARD_NEW_h
#define _GUARD_NEW_h

void * new(const void *class, ...); /* new(Point, x, y); */

void delete(void *item);

void draw(const void *self);

#endif
