#include "primitive.h"

Primitive::Primitive()
{
    scale = QVector3D(1,1,1);
    rotation = QVector3D(0,0,0);
    position = QVector3D(0,0,0);
}

void Primitive::addVertexPoint(float x, float y, float z)
{
    vertices.append(QVector3D(x,y,z));
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

void Primitive::setRotation(QVector3D angles)
{
    rotation = angles;
}

void Primitive::rotate(QVector3D angles)
{
    rotation += angles;
}

void Primitive::setRotation(float x, float y, float z)
{
    setRotation(QVector3D(x,y,z));
}

void Primitive::rotate(float x, float y, float z)
{
    rotate(QVector3D(x,y,z));
}

void Primitive::setPosition(QVector3D position)
{
    this->position = position;
}

void Primitive::translate(QVector3D posDelta)
{
    this->position += posDelta;
}

void Primitive::setPosition(float x, float y, float z)
{
    setPosition(QVector3D(x,y,z));
}

void Primitive::translate(float x, float y, float z)
{
    translate(QVector3D(x,y,z));
}
