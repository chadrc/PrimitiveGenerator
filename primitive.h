#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QVector>
#include <QVector3D>
#include <QMatrix4x4>

class Vertex
{
    QVector3D position;
    QVector3D normal;
    QVector4D color;

public:
    Vertex()
    {
        color = QVector4D(1,1,1,1);
    }

    Vertex(QVector3D position, QVector3D normal, QVector4D color = QVector4D(1,1,1,1)) :
        position(position), normal(normal), color(color)
    {}
};

class Primitive
{
public:
    ~Primitive();

    int VertexCount();
    const Vertex* VertexData();
    QMatrix4x4 transform();

    void setRotation(QVector3D angles);
    void rotate(QVector3D angles);
    void setRotation(float x, float y, float z);
    void rotate(float x, float y, float z);

    void setPosition(QVector3D position);
    void translate(QVector3D posDelta);
    void setPosition(float x, float y, float z);
    void translate(float x, float y, float z);

protected:
    Primitive();

    QVector<Vertex> vertices;

private:
    QVector3D position;
    QVector3D rotation;
    QVector3D scale;
};

#endif // PRIMITIVE_H
