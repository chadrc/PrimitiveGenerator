#include "primitive.h"

Primitive::Primitive()
{
    scale = QVector3D(1,1,1);
    rotation = QVector3D(0,0,0);
    position = QVector3D(0,0,0);
}

Primitive::~Primitive()
{

}

int Primitive::vertexCount()
{
    return vertices.size();
}

int Primitive::indexCount()
{
    return indices.size();
}

const QVector3D *Primitive::vertexData()
{
    return vertices.constData();
}

const int *Primitive::indexData()
{
    return indices.constData();
}

QMatrix4x4 Primitive::transform()
{
    QMatrix4x4 m;
    m.scale(scale);
    m.rotate(rotation.x(), QVector3D(1, 0, 0));
    m.rotate(rotation.y(), QVector3D(0, 1, 0));
    m.rotate(rotation.z(), QVector3D(0, 0, 1));
    m.translate(position);
    return m;
}
