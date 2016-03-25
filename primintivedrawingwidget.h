#ifndef PRIMINTIVEDRAWINGWIDGET_H
#define PRIMINTIVEDRAWINGWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include <QSize>
#include <QResizeEvent>

class Primitive;

class PrimintiveDrawingWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    PrimintiveDrawingWidget(QWidget* parent = 0);
    ~PrimintiveDrawingWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

signals:

public slots:
    void queueUpdate();

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);

private:
    Primitive* currentPrimitive;

    QOpenGLShaderProgram program;
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;

    int viewProjMatAttr;
    int modelMatAttr;
    int positionAttr;
};

#endif // PRIMINTIVEDRAWINGWIDGET_H
