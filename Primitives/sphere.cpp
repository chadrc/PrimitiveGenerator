#include "sphere.h"
#include <QtMath>
#include <QtGlobal>

Sphere::Sphere()
{
    int hDiv = 20;
    int vDiv = 20;

    int mhDiv = hDiv-1;

    float angHInc = qDegreesToRadians(180.0/hDiv);
    float angVInc = qDegreesToRadians(360.0/vDiv);
    float angH = qDegreesToRadians(90.0) - angHInc;

    float topY = sin(angH);
    float topRadius = cos(angH);
    float angV = 0;
    QVector3D topPoint(0, 1, 0);
    QVector3D lastPoint(cos(angV)*topRadius, topY, sin(angV)*topRadius);

    for (int i=0; i<vDiv; i++)
    {
        angV += angVInc;
        QVector3D nextPoint(cos(angV)*topRadius, topY, sin(angV)*topRadius);
        // Calc Normal
        QVector3D normal = QVector3D::crossProduct((lastPoint - topPoint).normalized(),
                                                   (topPoint - nextPoint).normalized()).normalized();

        vertices.append(Vertex(topPoint, normal));
        vertices.append(Vertex(lastPoint, normal));
        vertices.append(Vertex(nextPoint, normal));

        lastPoint = nextPoint;
    }

    angH -= angHInc;
    float lowY = sin(angH);
    float lowRadius = cos(angH);

    for (int i=0; i<mhDiv; i++)
    {
        angV = 0;
        QVector3D lastTopPoint(cos(angV)*topRadius, topY, sin(angV)*topRadius);
        QVector3D lastLowPoint(cos(angV)*lowRadius, lowY, sin(angV)*lowRadius);

        for (int j=0; j<vDiv; j++)
        {
            angV += angVInc;
            QVector3D nextTopPoint(cos(angV)*topRadius, topY, sin(angV)*topRadius);
            QVector3D nextLowPoint(cos(angV)*lowRadius, lowY, sin(angV)*lowRadius);

            // Normal Calc
            QVector3D normal = QVector3D::crossProduct((lastLowPoint - lastTopPoint).normalized(),
                                                       (lastTopPoint - nextTopPoint).normalized()).normalized();
            //QVector4D color((qrand()%255)/255.0,(qrand()%255)/255.0,(qrand()%255)/255.0,1);

            // Tri 1
            vertices.append(Vertex(lastTopPoint, normal));//, color));
            vertices.append(Vertex(lastLowPoint, normal));//, color));
            vertices.append(Vertex(nextLowPoint, normal));//, color));

                // Tri 2
            vertices.append(Vertex(lastTopPoint, normal));//, color));
            vertices.append(Vertex(nextLowPoint, normal));//, color));
            vertices.append(Vertex(nextTopPoint, normal));//, color));

            lastTopPoint = nextTopPoint;
            lastLowPoint = nextLowPoint;
        }

        topY = lowY;
        topRadius = lowRadius;
        angH -= angHInc;
        lowY = sin(angH);
        lowRadius = cos(angH);
        angV = 0;
    }


    topPoint = QVector3D(0, -1, 0);
    lastPoint = QVector3D(cos(angV)*topRadius, lowY, sin(angV)*topRadius);
    angV = 0;
    for (int i=0; i<vDiv; i++)
    {
        angV += angVInc;
        QVector3D nextPoint(cos(angV)*topRadius, lowY, sin(angV)*topRadius);
        // Calc Normal
        QVector3D normal = QVector3D::crossProduct((lastPoint - topPoint).normalized(),
                                                   (nextPoint - lastPoint).normalized()).normalized();

        vertices.append(Vertex(topPoint, normal));
        vertices.append(Vertex(lastPoint, normal));
        vertices.append(Vertex(nextPoint, normal));

        lastPoint = nextPoint;
    }
}

