#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);


//    QHBoxLayout* mainLayout = new QHBoxLayout();
//    PrimintiveDrawingWidget* primWid = new PrimintiveDrawingWidget();
//    mainLayout->addWidget(primWid);

    setCentralWidget(new MainWidget(this));

}

MainWindow::~MainWindow()
{
    delete ui;
}
