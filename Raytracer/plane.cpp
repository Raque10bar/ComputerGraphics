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

#include "plane.h"
#include <iostream>
#include <math.h>

/************************** Sphere **********************************/

Hit Plane::intersect(const Ray &ray)
{
    // place holder for actual intersection calculation

    double LdotN = ray.D.dot(N);
    if (LdotN == 0) {
        return Hit::NO_HIT();
    }
    
    double t = ((point - ray.O).dot(N)) / LdotN;
    if (t < 0) {
        return Hit::NO_HIT();
    }
    
    return Hit(t,N);
}
