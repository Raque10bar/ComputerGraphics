#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include "object.h"

class Box : public Object
{
public:
    Box(Point a, Point b,Point c) : a(a), b(b), c(c) { }

    virtual Hit intersect(const Ray &ray);

    const Point a;
    const Point b;
    const Point c;

private:
    bool checkInside(Point v1, Point v2, Point intersect, Vector N);
};
#endif // BOX_H
