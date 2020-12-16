#include "interpretador.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
using namespace std;

Interpretador::Interpretador(){}

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}

std::vector<FiguraGeometrica *> Interpretador::parse(std::string filename){

    vector<FiguraGeometrica*> figuras;
    ifstream entrada;
    stringstream sst;
    string s, token;
    entrada.open(filename.c_str());
    if(!entrada.is_open()){
        cout << "Erro interpretador" << endl;
        exit(0);
    }

    while(entrada.good()){
        getline(entrada, s);
        if(entrada.good()){
            sst.clear();
            sst.str(s);
            sst >> token;
            if(sst.good()){
                if(token.compare("dim") == 0){
                    sst >> dimx >> dimy >> dimz;
                }
                else if(token.compare("putvoxel") == 0){
                    int x, y, z;
                    sst >> x >> y >> z >> r >> g >> b >> a;
                    figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));
                }
                else if(token.compare("cutvoxel") == 0){
                    int x, y, z;
                    sst >> x >> y >> z;
                    figuras.push_back(new CutVoxel(x, y, z));
                }
                else if(token.compare("putbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    sst >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if(token.compare("cutbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    sst >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putsphere") == 0){
                    int x, y, z, raio;
                    sst >> x >> y >> z >> raio >> r >> g >> b >> a;
                    figuras.push_back(new PutSphere(x, y, z, raio, r, g, b, a));
                }
                else if(token.compare("cutsphere") == 0){
                    int x, y, z, raio;
                    sst >> x >> y >> z >> raio;
                    figuras.push_back(new CutSphere(x, y, z, raio));
                }
                else if(token.compare("putellipsoid") == 0){
                    int x, y, z, raiox, raioy, raioz;
                    sst >> x >> y >> z >> raiox >> raioy >> raioz >> r >> g >> b >> a;
                    figuras.push_back(new PutEllipsoid(x, y, z, raiox, raioy, raioz, r, g, b, a));
                }
                else if(token.compare("cutellipsoid") == 0){
                    int x, y, z, raiox, raioy, raioz;
                    sst >> x >> y >> z >> raiox >> raioy >> raioz;
                    figuras.push_back(new CutEllipsoid(x, y, z, raiox, raioy, raioz));
                }
            }
        }
    }
    return(figuras);
}
