#include "putsphere.h"
#include "sculptor.h"
#include "figurageometrica.h"
#include <cmath>

PutSphere::PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a){
    this->x=x;
    this->y=y;
    this->z=z;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
    this->raio=raio;
}

PutSphere::~PutSphere(){}

void PutSphere::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    for(int i=(x-raio); i<=(x+raio); i++){
        for(int j=(y-raio); j<=(y+raio); j++){
            for(int k=(z-raio); k<=(z+raio); k++){
                if(pow((i-x),2) + pow((j-y),2) + pow((k-z),2) <= pow(raio,2)){
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
