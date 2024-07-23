#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MarketDataDownloader.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::makePlot(){
    MarketDataDownloader a;
    a.parse();
    QVector<double> x(a.for_x.size()+20), y(a.for_y.size()+20); // initialize with entries 0..100
    for (int i=0; i<a.for_x.size()-1; i++)
    {
        x[i] = a.for_x[i] - a.for_x[0]; // unix -> a.for_x[i]
        y[i] = a.for_y[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 200000000);
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->replot();
    //a.let_me_see();
    //system("wget 'https://data.binance.vision/data/spot/monthly/klines/ADABKRW/1h/ADABKRW-1h-2020-08.zip'")
}

void MainWindow::on_pushButton_clicked()
{


    makePlot();
    ui->label->setText("asdzxcqwe");
}

