
#include "box.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

Hit Box::intersect(const Ray &ray)
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
    
//    Vector P = ray.D.cross(ac);
//    float det = ab.dot(P);
//    cout<< det<<" ";
//    if(det > -(std::numeric_limits<float>::epsilon())  && det < std::numeric_limits<float>::epsilon() ){
//        //no hit
//        cout<<"here1";
//        return Hit::NO_HIT();
//    }
//
//    float inv_det = 1.f/det;
//
//    Vector T = ray.O - a;
//
//    float u = T.dot(P);
//
//    if(u<0.f || u>1){
//        //no hit
//        return Hit::NO_HIT();
//    }
//
//    Vector Q = ray.D.cross(ab);
//
//    float v = ray.D.dot(Q)* inv_det;
//
//    if(v<0.f || u+v >1){
//        //no hit
//        cout<<"here3";
//        return Hit::NO_HIT();
//    }
//
//    float t = ac.dot(Q)*inv_det;
//
//    if(t<=std::numeric_limits<float>::epsilon()){
//        //no hit
//        cout<<"here4";
//        return Hit::NO_HIT();
//    }
//
//
//
//
//    cout<<"HIT";
    return Hit(t,N);
}

bool Box::checkInside(Point v1, Point v2, Point intersect, Vector N) {
    Vector edge = v2 - v1;
    Vector interV = intersect - v1;
    Vector C = edge.cross(interV);
    
    return (N.dot(C) >= 0);
}
