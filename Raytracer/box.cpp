
#include "box.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>


Hit Box::intersect(const Ray &ray)
{
    //Calculating Normal of Triangle plane
    Vector ab = b - a;
    Vector ac = c - a;


    Vector N = ab.cross(ac);
    Vector P = ray.D.cross(ac);
    float det = ab.dot(P);
    cout<< det<<" ";
    if(det > -(std::numeric_limits<float>::epsilon())  && det < std::numeric_limits<float>::epsilon() ){
        //no hit
        cout<<"here1";
        return Hit::NO_HIT();
    }

    float inv_det = 1.f/det;

    Vector T = ray.O - a;

    float u = T.dot(P);

    if(u<0.f || u>1){
        //no hit
        return Hit::NO_HIT();
    }

    Vector Q = ray.D.cross(ab);

    float v = ray.D.dot(Q)* inv_det;

    if(v<0.f || u+v >1){
        //no hit
        cout<<"here3";
        return Hit::NO_HIT();
    }

    float t = ac.dot(Q)*inv_det;

    if(t<=std::numeric_limits<float>::epsilon()){
        //no hit
        cout<<"here4";
        return Hit::NO_HIT();
    }




    cout<<"HIT";
    return Hit(t,N);
}
