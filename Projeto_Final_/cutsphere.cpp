#include "cutsphere.h"
#include <cmath>
#include "sculptor.h"
#include "figurageometrica.h"

CutSphere::CutSphere(int x, int y, int z, int raio){
    this->x=x;
    this->y=y;
    this->z=z;
    this->raio=raio;
}

CutSphere::~CutSphere(){}

void CutSphere::draw(Sculptor &s){
    for(int i=(x-raio); i<=(x+raio); i++){
        for(int j=(y-raio); j<=(y+raio); j++){
            for(int k=(z-raio); k<=(z+raio); k++){
                if(pow((i-x),2) + pow((j-y),2) + pow((k-z),2) <= pow(raio,2)){
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
