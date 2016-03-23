#include "mainwidget.h"

#include <QHBoxLayout>

#include "primintivedrawingwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    auto prim = new PrimintiveDrawingWidget();
    auto box = new QHBoxLayout();
    box->addWidget(prim);

    setLayout(box);
}

