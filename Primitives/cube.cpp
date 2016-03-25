#include "cube.h"

Cube::Cube()
{
    QVector3D backBottomLeft = QVector3D(-.5, -.5, -.5);
    QVector3D backTopLeft = QVector3D(-.5, .5, -.5);
    QVector3D backBottomRight = QVector3D(.5, -.5, -.5);
    QVector3D backTopRight = QVector3D(.5, .5, -.5);

    QVector3D frontBottomLeft = QVector3D(-.5, -.5, .5);
    QVector3D frontTopLeft = QVector3D(-.5, .5, .5);
    QVector3D frontBottomRight = QVector3D(.5, -.5, .5);
    QVector3D frontTopRight = QVector3D(.5, .5, .5);

    QVector3D frontNormal = QVector3D(0, 0, 1);
    QVector3D backNormal = QVector3D(0, 0, -1);
    QVector3D topNormal = QVector3D(0, 1, 0);
    QVector3D bottomNormal = QVector3D(0, -1, 0);
    QVector3D rightNormal = QVector3D(1, 0, 0);
    QVector3D leftNormal = QVector3D(-1, 0, 0);

    // Back Quad
    vertices.append(Vertex(backBottomLeft, backNormal));
    vertices.append(Vertex(backTopLeft, backNormal));
    vertices.append(Vertex(backBottomRight, backNormal));

    vertices.append(Vertex(backTopLeft, backNormal));
    vertices.append(Vertex(backTopRight, backNormal));
    vertices.append(Vertex(backBottomRight, backNormal));

    // Front Quad
    vertices.append(Vertex(frontBottomLeft, frontNormal));
    vertices.append(Vertex(frontTopLeft, frontNormal));
    vertices.append(Vertex(frontBottomRight, frontNormal));

    vertices.append(Vertex(frontTopLeft, frontNormal));
    vertices.append(Vertex(frontTopRight, frontNormal));
    vertices.append(Vertex(frontBottomRight, frontNormal));

    // Top Quad
    vertices.append(Vertex(frontTopLeft, topNormal));
    vertices.append(Vertex(backTopLeft, topNormal));
    vertices.append(Vertex(backTopRight, topNormal));

    vertices.append(Vertex(frontTopLeft, topNormal));
    vertices.append(Vertex(backTopRight, topNormal));
    vertices.append(Vertex(frontTopRight, topNormal));

    // Bottom Quad
    vertices.append(Vertex(frontBottomLeft, bottomNormal));
    vertices.append(Vertex(backBottomLeft, bottomNormal));
    vertices.append(Vertex(backBottomRight, bottomNormal));

    vertices.append(Vertex(frontBottomLeft, bottomNormal));
    vertices.append(Vertex(backBottomRight, bottomNormal));
    vertices.append(Vertex(frontBottomRight, bottomNormal));

    // Right Quad
    vertices.append(Vertex(frontTopRight, rightNormal));
    vertices.append(Vertex(backTopRight, rightNormal));
    vertices.append(Vertex(backBottomRight, rightNormal));

    vertices.append(Vertex(frontTopRight, rightNormal));
    vertices.append(Vertex(backBottomRight, rightNormal));
    vertices.append(Vertex(frontBottomRight, rightNormal));

    // Left Quad
    vertices.append(Vertex(frontTopLeft, leftNormal));
    vertices.append(Vertex(backTopLeft, leftNormal));
    vertices.append(Vertex(backBottomLeft, leftNormal));

    vertices.append(Vertex(frontTopLeft, leftNormal));
    vertices.append(Vertex(backBottomLeft, leftNormal));
    vertices.append(Vertex(frontBottomLeft, leftNormal));
}

Cube::~Cube()
{

}

