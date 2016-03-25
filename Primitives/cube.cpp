#include "cube.h"

Cube::Cube()
{
    addVertexPoint(-.5, -.5, -.5);  // 0: back bottom left
    addVertexPoint(-.5, .5, -.5);   // 1: back top left
    addVertexPoint(.5, -.5, -.5);   // 2: back bottom right
    addVertexPoint(.5, .5, -.5);    // 3: back top right

    addVertexPoint(-.5, -.5, .5);   // 4: front bottom left
    addVertexPoint(-.5, .5, .5);    // 5: front top left
    addVertexPoint(.5, -.5, .5);    // 6: front bottom right
    addVertexPoint(.5, .5, .5);     // 7: front top right

    // Back Quad
    indices.append(0); indices.append(1); indices.append(2);
    indices.append(1); indices.append(3); indices.append(2);
    // Front Quad
    indices.append(4); indices.append(5); indices.append(6);
    indices.append(5); indices.append(7); indices.append(6);
    // Top Quad
    indices.append(5); indices.append(1); indices.append(3);
    indices.append(5); indices.append(3); indices.append(7);
    // Bottom Quad
    indices.append(4); indices.append(0); indices.append(2);
    indices.append(4); indices.append(2); indices.append(6);
    // Right Quad
    indices.append(6); indices.append(7); indices.append(3);
    indices.append(6); indices.append(3); indices.append(2);
    // Left Quad
    indices.append(4); indices.append(5); indices.append(1);
    indices.append(4); indices.append(1); indices.append(0);
}

Cube::~Cube()
{

}

