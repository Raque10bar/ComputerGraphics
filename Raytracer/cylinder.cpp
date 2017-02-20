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

Hit Cylinder::intersect(const Ray &ray)
{
    // place holder for actual intersection calculation
    
//    Vector H = (p2 - p1).normalized();
//    
//    double DdotH = ray.D.dot(H);
//    Vector OP = ray.O - p1;
    
    Vector V = ray.D;
    Vector O = ray.O;
    
    Vector AB = (p2 - p1);
    Vector AO = (O - p1);
    Vector AOxAB = AO.cross(AB); // cross product
    Vector VxAB  = V.cross(AB); // cross product
    double  ab2   = AB.dot(AB); // dot product
    double a      = VxAB.dot(VxAB); // dot product
    double b      = 2 * VxAB.dot(AOxAB); // dot product
    double c      = AOxAB.dot(AOxAB) - (r*r * ab2);
    
//    double a = (ray.D - DdotH * H).dot(ray.D - DdotH * H);
//    double b = 2 * (ray.D - DdotH * H).dot(OP.dot(H)*H);
//    double c = (OP - OP.dot(H) * H).dot(OP - OP.dot(H) * H) - r*r;

    double d = b*b - 4*a*c;
    double t = -1;
    Point intersect;
    if (d >= 0) {
        if (a < 0) {
            t = (-b + sqrt(d))/(2*a);
        } else {
            t = (-b - sqrt(d))/(2*a);
        }
        
        if (t >= 0) {
            intersect = ray.at(t);
            if (!isInsideBody(p1, p2, intersect, AB) ) {
                return Hit::NO_HIT();
            }
        }
    }
    
    Vector Nc1 = (p1 - p2).normalized();
    double LdotN = ray.D.dot(Nc1);
    if (LdotN > 0) {
        double tc1 = ((p1 - ray.O).dot(Nc1)) / LdotN;
        if (tc1 >= 0 && tc1 < t && isInsideCap(p1, ray.at(tc1), r)) {
            t = tc1;
        }
    }
    
    Vector Nc2 = (p2 - p1).normalized();
    LdotN = ray.D.dot(Nc2);
    if (LdotN > 0) {
        double tc2 = ((p2 - ray.O).dot(Nc2)) / LdotN;
        if (tc2 >= 0 && tc2 < t && isInsideCap(p2, ray.at(tc2), r)) {
            t = tc2;
        }
    }
    
    
    if (t < 0) {
        return Hit::NO_HIT();
    }
    
    Vector H = p2 - p1;
    V = intersect - p1;
    Vector N = V - (V.dot(H) * H) / H.dot(H);
    return Hit(t,N.normalized());
}

bool Cylinder::isInsideBody(Point p1, Point p2, Point intersect, Vector H) {
    
    return H.dot(intersect - p1) > 0 && H.dot(intersect - p2) < 0;
}

bool Cylinder::isInsideCap(Point c, Point intersect, double r) {
    return (intersect - c).dot(intersect - c) < r*r;
}
