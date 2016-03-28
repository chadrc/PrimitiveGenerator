#include "primintivedrawingwidget.h"

#include "primitive.h"
#include "Primitives/square.h"
#include "Primitives/cube.h"
#include "Primitives/circle.h"
#include "Primitives/sphere.h"

#include <QFile>
#include <QTimer>

PrimitiveDrawingWidget::PrimitiveDrawingWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    currentPrimitive(nullptr)
{
    updating = false;
    currentPrimitive = new Cube();
}

PrimitiveDrawingWidget::~PrimitiveDrawingWidget()
{
    if (currentPrimitive)
    {
        delete currentPrimitive;
    }
}

QSize PrimitiveDrawingWidget::minimumSizeHint() const
{
//    qDebug() << "min size hint";
    return QSize(50, 50);
}

QSize PrimitiveDrawingWidget::sizeHint() const
{
//    qDebug() << "size hint";
    return QSize(600, 600);
}

void PrimitiveDrawingWidget::setPrimitive(Primitive *prim)
{
    if (prim == nullptr)
    {
        return;
    }

    updating = true;

    if (currentPrimitive != nullptr)
    {
        delete currentPrimitive;
    }

    currentPrimitive = prim;
    vertexBuffer.bind();
    vertexBuffer.allocate(currentPrimitive->VertexData(), sizeof(Vertex) * currentPrimitive->VertexCount());
    vertexBuffer.release();
    updating = false;
}

void PrimitiveDrawingWidget::queueUpdate()
{
    this->update();

    QTimer::singleShot(100, Qt::PreciseTimer, this, SLOT(queueUpdate()));
}

void PrimitiveDrawingWidget::initializeGL()
{
//    qDebug() << "Initialize";

    initializeOpenGLFunctions();

    program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":shaders/default.vert");
    program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":shaders/default.frag");

    program.link();

    vao.create();
    vao.bind();
    program.bind();

    viewMatAttr = program.uniformLocation("viewMat");
    projMatAttr = program.uniformLocation("projMat");
    modelMatAttr = program.uniformLocation("modelMat");
    positionAttr = program.attributeLocation("position");
    normalAttr = program.attributeLocation("normal");
    colorAttr = program.attributeLocation("color");

    vertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(currentPrimitive->VertexData(), sizeof(Vertex) * currentPrimitive->VertexCount());

    program.enableAttributeArray(positionAttr);
    program.enableAttributeArray(normalAttr);
    program.enableAttributeArray(colorAttr);
    program.setAttributeBuffer(positionAttr, GL_FLOAT, 0, 3, sizeof(Vertex));
    program.setAttributeBuffer(normalAttr, GL_FLOAT, sizeof(QVector3D), 3, sizeof(Vertex));
    program.setAttributeBuffer(colorAttr, GL_FLOAT, sizeof(QVector3D)*2, 4, sizeof(Vertex));

    viewMatrix.translate(0, 0, -2);

    vao.release();
    program.release();

    glClearColor(0,0,0, 1);

    QTimer::singleShot(100, Qt::PreciseTimer, this, SLOT(queueUpdate()));
}

void PrimitiveDrawingWidget::paintGL()
{
    if (updating)
    {
        return;
    }

    // Update
    currentPrimitive->rotate(0, 2, 0);

    // Draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);

    vao.bind();
    program.bind();

    program.setUniformValue(modelMatAttr, currentPrimitive->transform());
    program.setUniformValue(viewMatAttr, viewMatrix);
    program.setUniformValue(projMatAttr, projectionMatrix);

    glDrawArrays(GL_TRIANGLES, 0, currentPrimitive->VertexCount());
    //glDrawElements(GL_TRIANGLES, currentPrimitive->indexCount(), GL_UNSIGNED_INT, 0);

    vao.release();
    program.release();
}

void PrimitiveDrawingWidget::resizeGL(int width, int height)
{
//    qDebug() << "Resize GL: " << (float)width/height;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(60.0f, (float)width/(float)height, .01, 10.0f);
}
