#include "primintivedrawingwidget.h"
#include "primitive.h"
#include "Primitives/square.h"
#include "Primitives/cube.h"

#include <QFile>
#include <QTimer>

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
//    qDebug() << "min size hint";
    return QSize(50, 50);
}

QSize PrimintiveDrawingWidget::sizeHint() const
{
//    qDebug() << "size hint";
    return QSize(600, 600);
}

void PrimintiveDrawingWidget::queueUpdate()
{
    this->update();

    QTimer::singleShot(100, Qt::PreciseTimer, this, SLOT(queueUpdate()));
}

void PrimintiveDrawingWidget::initializeGL()
{
    initializeOpenGLFunctions();

    currentPrimitive = new Cube();

    program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":shaders/default.vert");
    program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":shaders/default.frag");

    program.link();

    vao.create();
    vao.bind();
    program.bind();

    viewProjMatAttr = program.uniformLocation("viewProjMat");
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

    viewMatrix.translate(0, 0, -3);

    vao.release();
    program.release();

    glClearColor(.5, .3, .7, 1);

    QTimer::singleShot(100, Qt::PreciseTimer, this, SLOT(queueUpdate()));
}

void PrimintiveDrawingWidget::paintGL()
{
    // Update
    currentPrimitive->rotate(0, 5, 0);

    // Draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);

    vao.bind();
    program.bind();

    program.setUniformValue(modelMatAttr, currentPrimitive->transform());
    program.setUniformValue(viewProjMatAttr, projectionMatrix * viewMatrix);

    glDrawArrays(GL_TRIANGLES, 0, currentPrimitive->VertexCount());
    //glDrawElements(GL_TRIANGLES, currentPrimitive->indexCount(), GL_UNSIGNED_INT, 0);

    vao.release();
    program.release();
}

void PrimintiveDrawingWidget::resizeGL(int width, int height)
{
    qDebug() << "Resize GL: " << (float)width/height;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(60.0f, (float)width/(float)height, .01, 10.0f);
}
