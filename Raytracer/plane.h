//
//  Framework for a raytracer
//  File: sphere.h
//
//  Created for the Computer Science course "Introduction Computer Graphics"
//  taught at the University of Groningen by Tobias Isenberg.
//
//  Authors:
//    Maarten Everts
//    Jasper van de Gronde
//
//  This framework is inspired by and uses code of the raytracer framework of
//  Bert Freudenberg that can be found at
//  http://isgwww.cs.uni-magdeburg.de/graphik/lehre/cg2/projekt/rtprojekt.html
//

#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include "object.h"

class Plane : public Object
{
public:
    
    Plane(Point point, Vector N) : point(point), N(N) {
    }
    
    Plane(Point p1, Point p2, Point p3) : point(p1), N((p2 - p1).cross(p3 - p1)) {
        cout << N;
    }
    
    virtual Hit intersect(const Ray &ray);
    
    const Point point;
    const Vector N;
};

#endif
