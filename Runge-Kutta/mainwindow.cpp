#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QDoubleValidator(ui->lineEdit));
    ui->lineEdit_2->setValidator(new QDoubleValidator(ui->lineEdit_2));
    ui->lineEdit_3->setValidator(new QDoubleValidator(ui->lineEdit_3));
    ui->lineEdit_4->setValidator(new QDoubleValidator(ui->lineEdit_4));
    ui->lineEdit_5->setValidator(new QDoubleValidator(ui->lineEdit_5));
    ui->lineEdit_6->setValidator(new QDoubleValidator(ui->lineEdit_6));
    ui->lineEdit_7->setValidator(new QDoubleValidator(ui->lineEdit_7));
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

    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(res.first, res.second);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("x, м");
    ui->widget->yAxis->setLabel("y, м");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(-1, 1);
    ui->widget->yAxis->setRange(0, 1);
    ui->widget->replot();
}

void MainWindow::on_pushButton_clicked()
{
    double t=ui->lineEdit->text().toDouble();
    double dt=ui->lineEdit_2->text().toDouble();
    double x=ui->lineEdit_3->text().toDouble();
    double y=ui->lineEdit_4->text().toDouble();
    double Ux=ui->lineEdit_5->text().toDouble();
    double Uy=ui->lineEdit_6->text().toDouble();
    double g=ui->lineEdit_7->text().toDouble();
    std::pair<QVector<double>, QVector<double>> test=Runge_Kutta::calc(t,dt,x,y,Ux,Uy,g);
}

