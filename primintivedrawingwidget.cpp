#include "primintivedrawingwidget.h"
#include "primitive.h"
#include "Primitives/square.h"

#include <QFile>

PrimintiveDrawingWidget::PrimintiveDrawingWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    currentPrimitive(nullptr)
{

}

PrimintiveDrawingWidget::~PrimintiveDrawingWidget()
{
    if (currentPrimitive)
    {
        delete currentPrimitive;
    }
}

QSize PrimintiveDrawingWidget::minimumSizeHint() const
{
    qDebug() << "min size hint";
    return QSize(50, 50);
}

QSize PrimintiveDrawingWidget::sizeHint() const
{
    qDebug() << "size hint";
    return QSize(400, 400);
}

void PrimintiveDrawingWidget::initializeGL()
{
    initializeOpenGLFunctions();

    currentPrimitive = new Square();

    program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":shaders/default.vert");
    program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":shaders/default.frag");

    program.link();

    vao.create();
    vao.bind();
    program.bind();

    viewProjMatAttr = program.uniformLocation("viewProjMat");
    modelMatAttr = program.uniformLocation("modelMat");
    positionAttr = program.attributeLocation("position");

    vertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(currentPrimitive->vertexData(), sizeof(QVector3D) * currentPrimitive->vertexCount());

    program.enableAttributeArray(positionAttr);
    program.setAttributeBuffer(positionAttr, GL_FLOAT, 0, 3);

    indexBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(currentPrimitive->indexData(), sizeof(int) * currentPrimitive->indexCount());

    projectionMatrix.perspective(45.0f, .5f, .01f, 10.0f);
    viewMatrix.translate(0, 0, -2);

    program.setUniformValue(modelMatAttr, currentPrimitive->transform());
    program.setUniformValue(viewProjMatAttr, projectionMatrix * viewMatrix);

    vao.release();
    program.release();

    glClearColor(.5, .3, .7, 1);
}

void PrimintiveDrawingWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    vao.bind();
    program.bind();

    glDrawElements(GL_TRIANGLES, currentPrimitive->indexCount(), GL_UNSIGNED_INT, 0);

    vao.release();
    program.release();
}

void PrimintiveDrawingWidget::resizeGL()
{

}

