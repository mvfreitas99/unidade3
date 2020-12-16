#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica{
    int x, y, z, raio;
public:
    CutSphere(int x, int y, int z, int raio);
    ~CutSphere();
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
