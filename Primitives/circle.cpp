#include "circle.h"
#include <cmath>

Circle::Circle()
{
    int sides = 36;

    float lastx = .5;
    float lasty = 0;

    float angleInc = 360.0/sides;
//    qDebug() << "Inc: " << angleInc;
    angleInc *= (3.14/180.0);

    float angle = angleInc;

    QVector3D forward = QVector3D(0, 0, 1);

    for (int i=0; i<sides; i++)
    {
//        qDebug() << "Angle: " << angle;
//        qDebug() << "LastX: " << lastx;
//        qDebug() << "LastY: " << lasty;
        float nextx = cos(angle) * .5;
        float nexty = sin(angle) * .5;

        vertices.append(Vertex(QVector3D(0,0,0), forward));
        vertices.append(Vertex(QVector3D(lastx,lasty, 0), forward));
        vertices.append(Vertex(QVector3D(nextx,nexty, 0), forward));

        lastx = nextx;
        lasty = nexty;
        angle += angleInc;
    }
//    qDebug() << "LastX: " << lastx;
//    qDebug() << "LastY: " << lasty;
}

