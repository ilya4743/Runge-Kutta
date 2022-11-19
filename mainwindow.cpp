#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->lineEdit->setValidator(new QDoubleValidator(ui->lineEdit));
//    ui->lineEdit_2->setValidator(new QDoubleValidator(ui->lineEdit_2));
//    ui->lineEdit_3->setValidator(new QDoubleValidator(ui->lineEdit_3));
//    ui->lineEdit_4->setValidator(new QDoubleValidator(ui->lineEdit_4));
//    ui->lineEdit_5->setValidator(new QDoubleValidator(ui->lineEdit_5));
//    ui->lineEdit_6->setValidator(new QDoubleValidator(ui->lineEdit_6));
//    ui->lineEdit_7->setValidator(new QDoubleValidator(ui->lineEdit_7));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_3_triggered()
{
    QCoreApplication:: quit();
}


void MainWindow::on_action_triggered()
{
    QMessageBox messageBox;
    messageBox.information(0,"О программе","\nЛабораторная работа студента К3-32М\nМФ МГТУ им Н. Э. Баумана\nСоломатина Ильи\n"
    "ilasolomatin29@gmail.com\nСистема дифференциальных уравнений с начальными условиями");
}

void MainWindow::makeGraph(std::pair<QVector<double>, QVector<double>> res)
{
    double x0=*std::min_element(res.first.begin(),res.first.end());
    double y0=*std::min_element(res.second.begin(),res.second.end());
    double x=*std::max_element(res.first.begin(),res.first.end());
    double y=*std::max_element(res.second.begin(),res.second.end());

    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(res.first, res.second);
    ui->widget->xAxis->setLabel("x, м");
    ui->widget->yAxis->setLabel("y, м");
    ui->widget->xAxis->setRange(x0, x);
    ui->widget->yAxis->setRange(y0, y);
    ui->widget->replot();
}

void MainWindow::on_pushButton_clicked()
{
    double x0=ui->lineEdit->text().toDouble();
    double x=ui->lineEdit_8->text().toDouble();
    double y0=ui->lineEdit_2->text().toDouble();
//    double x0=ui->lineEdit_3->text().toDouble();
//    double y0=ui->lineEdit_4->text().toDouble();
    double h=ui->lineEdit_5->text().toDouble();
//    double Uy=ui->lineEdit_6->text().toDouble();
//    double g=ui->lineEdit_7->text().toDouble();
    //std::pair<QVector<double>, QVector<double>> test=Runge_Kutta::calc(t,dt,x0,y0,Ux,Uy,g);

    std::pair<QVector<double>, QVector<double>> test=Runge_Kutta1::calc(x0,x,y0,h);
    makeGraph(test);
}
