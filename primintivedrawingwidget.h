#ifndef PRIMINTIVEDRAWINGWIDGET_H
#define PRIMINTIVEDRAWINGWIDGET_H

#include <QOpenGLWidget>

class Primitive;

class PrimintiveDrawingWidget : public QOpenGLWidget
{
public:
    PrimintiveDrawingWidget(QWidget* parent = 0);
    ~PrimintiveDrawingWidget();

signals:

public slots:

protected:
    void initializeGL(); Q_DECL_OVERRIDE
    void paintGL(); Q_DECL_OVERRIDE
    void resizeGL(); Q_DECL_OVERRIDE

private:
    Primitive* currentPrimitive;
};

#endif // PRIMINTIVEDRAWINGWIDGET_H
