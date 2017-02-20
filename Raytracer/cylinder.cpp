//
//  Framework for a raytracer
//  File: sphere.cpp
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

#include "cylinder.h"
#include <iostream>
#include <math.h>

/************************** Sphere **********************************/

Hit Sphere::intersect(const Ray &ray)
{
    // place holder for actual intersection calculation

    double b = 2 * (ray.O - position).dot(ray.D);
    double c = (ray.O - position).dot(ray.O - position) - r*r;
    
    double d = b*b - 4*c;
    double t = (-b - sqrt(d))/2;
    
    if (t < 0) {
        return Hit::NO_HIT();
    }
    
    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, C, r
    * Sought: N
    * 
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/

    Point intersection = ray.at(t);
    Vector N = (intersection - position).normalized();
    
    return Hit(t,N);
}
