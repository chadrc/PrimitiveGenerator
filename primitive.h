#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QVector>
#include <QVector3D>
#include <QMatrix4x4>

class Primitive
{
public:
    ~Primitive();

    int vertexCount();
    int indexCount();
    const QVector3D* vertexData();
    const int* indexData();
    QMatrix4x4 transform();

protected:
    Primitive();

    QVector<QVector3D> vertices;
    QVector<int> indices;

private:
    QVector3D position;
    QVector3D rotation;
    QVector3D scale;
};

#endif // PRIMITIVE_H
