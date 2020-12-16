#include <iostream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "interpretador.h"
using namespace std;

int main(){

    Sculptor *s;
    Interpretador parser;
    vector<FiguraGeometrica*> figuras;

    figuras = parser.parse((char*)"/home/daniel/Projeto_One/ler.txt");
    s = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figuras.size(); i++){
        figuras[i]->draw(*s);
    }

    s->limpaVoxels();
    s->writeOFF((char*)"/home/daniel/Projeto_One/compilando.off");

    for(size_t i=0; i<figuras.size(); i++){
        delete figuras[i];
    }
    delete s;

    cout << "Deu certo, bora tomar uma!" << endl;
    return 0;
}
