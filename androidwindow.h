#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QSlider>
#include<QDial>
#include<QMainWindow>

namespace Ui {
    class AndroidWindow;
}

class AndroidImage;

class AndroidWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AndroidWindow(QWidget *parent=0);
    ~AndroidWindow();
private:

    Ui::AndroidWindow *ui;

    void addConnections();

    void disableActions();

    AndroidImage* image;
    QSlider* zoomer;
    QDial* rotator;
    QAction* load;
    QAction* save;
    QAction* crop;
    QAction* undo ;
    QAction* reset;
    QAction* exit;
    QPushButton* importTest;


private slots:
    void updateActions();

};

#endif // WIDGET_H
