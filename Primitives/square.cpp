#include "square.h"

Square::Square()
{
    vertices.append(QVector3D(-.5, -.5, 0));
    vertices.append(QVector3D(-.5, .5, 0));
    vertices.append(QVector3D(.5, .5, 0));
    vertices.append(QVector3D(.5, -.5, 0));

    indices.append(0);
    indices.append(1);
    indices.append(2);

    indices.append(0);
    indices.append(2);
    indices.append(3);
}

Square::~Square()
{

}

