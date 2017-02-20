
#include "triangle.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

Hit Triangle::intersect(const Ray &ray)
{
    //Calculating Normal of Triangle plane
    Vector N = (b - a).cross(c - a).normalized();
    
    double LdotN = ray.D.dot(N);
    
    if (LdotN == 0) {
        return Hit::NO_HIT();
    }
    
    double t = (a - ray.O).dot(N) / LdotN;
    
    if (t < 0) {
        return Hit::NO_HIT();
    }
    
    Point intersect = ray.at(t);
    
    if (! (checkInside(a, b, intersect, N) && (checkInside(b, c, intersect, N)) && (checkInside(c, a, intersect, N)))) {
        return Hit::NO_HIT();
    }
    return Hit(t,N);
}

bool Triangle::checkInside(Point v1, Point v2, Point intersect, Vector N) {
    Vector edge = v2 - v1;
    Vector interV = intersect - v1;
    Vector C = edge.cross(interV);
    
    return (N.dot(C) >= 0);
}
