#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
    int x, y, z, raiox, raioy, raioz;
public:
    CutEllipsoid(int x, int y, int z, int raiox, int raioy, int raioz);
    ~CutEllipsoid();
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
