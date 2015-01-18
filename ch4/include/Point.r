#ifndef _GUARD_POINT_R
#define _GUARD_POINT_R

struct Point {
    const void *class;
    int x, y;
};

#define x(p) (((const struct Point *)(p)) -> x)
#define y(p) (((const struct Point *)(p)) -> y)

#endif
