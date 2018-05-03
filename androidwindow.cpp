#include "androidwindow.h"
#include "androidimage.h"
#include "ui_mainwindow.h"


#include<QMainWindow>
#include<QtWidgets>
#include<QMenu>
#include<QAction>
#include <Qt>


AndroidWindow::AndroidWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::And){

    ui->setupUi(this);

    //amr

    importTest = new QPushButton(tr("import"));

    QMenu* menu = new QMenu ;

    /////////////////////////////// Actions ////////////////////////////////////////
    load = new QAction(tr("load"));
    menu->addAction(load);

    save = new QAction(tr("Save"));
    menu->addAction(save);

    crop = new QAction(tr("Crop"));
    menu->addAction(crop);

    undo = new QAction(tr("Undo"));
    menu->addAction(undo);

    reset = new QAction(tr("Reset"));
    menu->addAction(reset);

    exit = new QAction(tr("Exit"));
    menu->addAction(exit);


    this->menuBar()->addMenu(menu);
//    this->menuBar()->setNativeMenuBar(false);


    /////////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////// Sliders ///////////////////////////////////

    zoomer = new QSlider(Qt::Vertical);
    zoomer->setRange(1,50);
    zoomer->setValue(25);

    /////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////  Dial ///////////////////////////////////////

    rotator = new QDial();
    rotator->setRange(1,50);
    rotator->setValue(25);

    /////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////// Image Holder //////////////////////////////////
    image = new AndroidImage;

    image->setStyleSheet("background-color : red;");
    //////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////// LayOut /////////////////////////////////

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(image,0,0,10,25);

    layout->addWidget(zoomer,1,29,4,4);

    layout->addWidget(rotator,6,28,4,4);

    layout->addWidget(importTest,10,29);


    /////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////// Building GUI /////////////////////////////////////

    QWidget* widget = new QWidget(this);

    widget->setLayout(layout);

    setCentralWidget(widget);

    //////////////////////////// Connections ////////////////////////////////////////////

    addConnections();

    /////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////// Disable Buttons ////////////////////////////////////
    disableActions();


    /*

    load = new QPushButton(tr("&Export"));
    load->setFocusPolicy(Qt::NoFocus);

    save = new QPushButton(tr("&Save"));
    save->setFocusPolicy(Qt::NoFocus);

    quit = new QPushButton(tr("&Quit"));
    quit->setFocusPolicy(Qt::NoFocus);

    zoom = new QPushButton(tr("&Zoom"));
    zoom->setFocusPolicy(Qt::NoFocus);

    crop = new QPushButton(tr("&Crop"));
    crop->setFocusPolicy(Qt::NoFocus);

    undo = new QPushButton(tr("&Undo"));
    undo->setFocusPolicy(Qt::NoFocus);

    reset = new QPushButton(tr("&Reset"));
    reset->setFocusPolicy(Qt::NoFocus);



    zoomer->setFocusPolicy(Qt::NoFocus);

    Connect Slot with the button signals;
      Android Image implementaion goes here

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(load,0,0);
    layout->addWidget(save,1,0);
    layout->addWidget(crop,3,0);
    layout->addWidget(undo,5,0);
    layout->addWidget(reset,6,0);
    layout->addWidget(quit,8,0);
    layout->addWidget(zoomer,1,28,4,4);
    layout->addWidget(rotator,6,28,4,4);
    layout->addWidget(image,0,1,10,25);

    setLayout(layout);
    setWindowTitle(tr("Viewer"));
    resize(550,370);
    */
}


void AndroidWindow::addConnections(){
    ////////////////////////////// Load ////////////////////////////
    connect(load,SIGNAL(triggered(bool)),image,SLOT(getImage()));
    connect(importTest,SIGNAL(clicked(bool)),image,SLOT(getImage()));
    //////////////////////// Save ////////////////////////////////

    //////////////////////// Zoom ////////////////////////////////
    connect(zoomer,SIGNAL(valueChanged(int)),image,SLOT(zoom(int)));
    //////////////////////// Crop //////////////////////////////////

    //////////////////////// Rotate ///////////////////////////////
    connect(rotator,SIGNAL(valueChanged(int)),image,SLOT(rotate(int)));
    /////////////////////// Undo /////////////////////////////////

    ////////////////////// Reset ////////////////////////////////

    ////////////////////// Exit /////////////////////////////////
    connect(exit,SIGNAL(triggered(bool)),this,SLOT(close()));

    ////////////////////// Actions Enabling /////////////////////
    connect(image,SIGNAL(imageLoaded()),this,SLOT(updateActions()));

}

void AndroidWindow::updateActions(){
    save->setEnabled(true);
    crop->setEnabled(true);
    undo->setEnabled(true);
    reset->setEnabled(true);
    zoomer->setEnabled(true);
    rotator->setEnabled(true);
}
void AndroidWindow::disableActions(){
    bool flag = false;
    save->setEnabled(flag);
    crop->setEnabled(flag);
    undo->setEnabled(flag);
    reset->setEnabled(flag);
    zoomer->setEnabled(flag);
    rotator->setEnabled(flag);
}

AndroidWindow::~AndroidWindow(){
    delete ui;
}
