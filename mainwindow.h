/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(int numBtns, QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
