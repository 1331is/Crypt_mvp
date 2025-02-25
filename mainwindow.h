#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <QMainWindow>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void makePlot();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


