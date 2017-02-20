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

#ifndef CYLINDER_H_INCLUDE
#define CYLINDER_H_INCLUDE

#include "object.h"

class Cylinder : public Object
{
public:
    Cylinder(Point position1, Point position2, double r) : position1(position1), position2(position2), r(r) { }

    virtual Hit intersect(const Ray &ray);

    const Point position1;
    const Point position2;
    const double r;
};

#endif /* end of include guard: SPHERE_H_115209AE */
