#include "cutellipsoid.h"
#include "sculptor.h"
#include "figurageometrica.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int x, int y, int z, int raiox, int raioy, int raioz){
    this->x=x;
    this->y=y;
    this->z=z;
    this->raiox=raiox;
    this->raioy=raioy;
    this->raioz=raioz;
}

CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &s){
    for(int i=(x-raiox); i<=(x+raiox); i++){
        for(int j=(y-raioy); j<=(y+raioy); j++){
            for(int k=(z-raioz); k<=(z+raioz); k++){
                if(pow(float(i-x)/float(raiox),2) + pow(float(j-y)/float(raioy),2) + pow(float(k-z)/float(raioz),2) <= 1){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
