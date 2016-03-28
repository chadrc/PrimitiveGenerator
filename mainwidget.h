#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class PrimitiveDrawingWidget;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

private slots:
    void OnSquareBtnClicked(bool);
    void OnCircleBtnClicked(bool);
    void OnCubeBtnClicked(bool);
    void OnSphereBtnClicked(bool);

private:
    PrimitiveDrawingWidget* glWidget;
};

#endif // MAINWIDGET_H
