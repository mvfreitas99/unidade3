#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutEllipsoid : public FiguraGeometrica{
    int x, y, z, raiox, raioy, raioz;
public:
    PutEllipsoid(int x, int y, int z, int raiox, int raioy, int raioz, float r, float g, float b, float a);
    ~PutEllipsoid();
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
