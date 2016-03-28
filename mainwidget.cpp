#include "mainwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QTabWidget>
#include <QPushButton>

#include "primintivedrawingwidget.h"
#include "Primitives/square.h"
#include "Primitives/circle.h"
#include "Primitives/cube.h"
#include "Primitives/sphere.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    auto prim = new PrimitiveDrawingWidget();
    glWidget = prim;

    auto squareBtn = new QPushButton("Square");
    connect(squareBtn, SIGNAL(clicked(bool)),
            this, SLOT(OnSquareBtnClicked(bool)));

    auto circleBtn = new QPushButton("Circle");
    connect(circleBtn, SIGNAL(clicked(bool)),
            this, SLOT(OnCircleBtnClicked(bool)));

    auto cubeBtn = new QPushButton("Cube");
    connect(cubeBtn, SIGNAL(clicked(bool)),
            this, SLOT(OnCubeBtnClicked(bool)));

    auto sphereBtn = new QPushButton("Sphere");
    connect(sphereBtn, SIGNAL(clicked(bool)),
            this, SLOT(OnSphereBtnClicked(bool)));

    auto btnLayout = new QGridLayout();

    btnLayout->addWidget(squareBtn, 0, 0);
    btnLayout->addWidget(circleBtn, 0, 1);
    btnLayout->addWidget(cubeBtn, 1, 0);
    btnLayout->addWidget(sphereBtn, 1, 1);

    auto generateBox = new QGroupBox("Generate");
    generateBox->setLayout(btnLayout);

    auto modifyBox = new QGroupBox("Modify");

    auto mainV = new QVBoxLayout();
    mainV->addWidget(generateBox);
    mainV->addWidget(modifyBox);

    auto infoWid = new QWidget();
    infoWid->setLayout(mainV);


    auto box = new QHBoxLayout();
    box->addWidget(infoWid);
    box->addWidget(prim);

    setLayout(box);
}

void MainWidget::OnSquareBtnClicked(bool)
{
    glWidget->setPrimitive(new Square());
}

void MainWidget::OnCircleBtnClicked(bool)
{
    glWidget->setPrimitive(new Circle());
}

void MainWidget::OnCubeBtnClicked(bool)
{
    glWidget->setPrimitive(new Cube());
}

void MainWidget::OnSphereBtnClicked(bool)
{
    glWidget->setPrimitive(new Sphere());
}

