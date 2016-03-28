#include "square.h"

Square::Square()
{
    QVector3D bottomLeft = QVector3D(-.5, -.5, 0);
    QVector3D topLeft = QVector3D(-.5, .5, 0);
    QVector3D topRight = QVector3D(.5, .5, 0);
    QVector3D bottomRight = QVector3D(.5, -.5, 0);

    QVector3D normal = QVector3D(0, 0, 1);

    vertices.append(Vertex(bottomLeft, normal));
    vertices.append(Vertex(topLeft, normal));
    vertices.append(Vertex(topRight, normal));

    vertices.append(Vertex(bottomLeft, normal));
    vertices.append(Vertex(topRight, normal));
    vertices.append(Vertex(bottomRight, normal));
}

Square::~Square()
{
}

