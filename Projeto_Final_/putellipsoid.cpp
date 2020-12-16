#include "sculptor.h"
#include "figurageometrica.h"
#include "putellipsoid.h"
#include <cmath>

PutEllipsoid::PutEllipsoid(int x, int y, int z, int raiox, int raioy, int raioz, float r, float g, float b, float a){
    this->x=x;
    this->y=y;
    this->z=z;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
    this->raiox=raiox;
    this->raioy=raioy;
    this->raioz=raioz;
}

PutEllipsoid::~PutEllipsoid(){}

void PutEllipsoid::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    for(int i=(x-raiox); i<=(x+raiox); i++){
        for(int j=(y-raioy); j<=(y+raioy); j++){
            for(int k=(z-raioz); k<=(z+raioz); k++){
                if(pow(float(i-x)/float(raiox),2) + pow(float(j-y)/float(raioy),2) + pow(float(k-z)/float(raioz),2) <= 1){
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
