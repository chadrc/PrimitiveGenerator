#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QVector>
#include <QVector3D>
#include <QMatrix4x4>

class Primitive
{
public:
    virtual QVector3D* vertexData() = 0;
    virtual int* indexData() = 0;
    virtual QMatrix4x4 transform() = 0;
};

#endif // PRIMITIVE_H
