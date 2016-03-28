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

class PrimitiveDrawingWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    PrimitiveDrawingWidget(QWidget* parent = 0);
    ~PrimitiveDrawingWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setPrimitive(Primitive* prim);

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

    bool updating;

    int projMatAttr;
    int viewMatAttr;
    int modelMatAttr;
    int positionAttr;
    int normalAttr;
    int colorAttr;
};

#endif // PRIMINTIVEDRAWINGWIDGET_H
