#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QSlider>
#include<QDial>
#include<QMainWindow>

class AndroidImage;

class AndroidWindow : public QMainWindow
{
    Q_OBJECT

public:
    AndroidWindow();
    void handle();

private:

    AndroidImage* image;

    QPushButton* load;
    QPushButton* save;
    QPushButton* quit;
    QPushButton* zoom;
    QPushButton* crop;
    QSlider* zoomer;
    QDial* rotator;
    QPushButton* undo;
    QPushButton* reset;

};

#endif // WIDGET_H
