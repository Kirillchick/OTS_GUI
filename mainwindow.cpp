#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Iteration()));
    //connect(timer, &QTimer::timeout, this, MainWindow::Iteration(simulationModel));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_simulate_Button_clicked()
{
    double truePointCoordX = ui->x_input->text().toDouble();
    double truePointCoordY = ui->y_input->text().toDouble();
    double baseL = ui->L_input->text().toDouble();
    double maxAngleError = ui->e_input->text().toDouble();
    simulationModel = new Model(truePointCoordX, truePointCoordY, baseL, maxAngleError);

    timer->start(1000);
    //timer->start(100);
}

void MainWindow::Iteration()
{
    if (numIteration < 200)
    {
        simulationModel->Iteration(numIteration);
        qDebug() << numIteration;
    }
    else
    {
        timer->stop();
        qDebug() << simulationModel->GetLogTable();
    }
    numIteration += 5;
}
