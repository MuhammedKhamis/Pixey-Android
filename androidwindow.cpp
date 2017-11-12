#include "androidwindow.h"
#include "androidimage.h"

#include<QMainWindow>
#include<QtWidgets>
#include<QMenu>
#include<QAction>
#include <QPalette>

AndroidWindow::AndroidWindow(){

    //amr
    QMenu* menu = new QMenu ;

    QAction* loady = new QAction(tr("load"));

    menu->addAction(loady);

    this->menuBar()->addMenu(menu);

   image = new AndroidImage;

    connect(loady,SIGNAL(triggered(bool)),image,SLOT(getImage()));


    image->setStyleSheet("background-color : gray;");

    this->setCentralWidget(image);

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

    zoomer = new QSlider(Qt::Vertical);
    zoomer->setRange(1,50);
    zoomer->setValue(25);

    zoomer->setFocusPolicy(Qt::NoFocus);

    rotator = new QDial();
    rotator->setValue(0);

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

void AndroidWindow::handle(){


 }
