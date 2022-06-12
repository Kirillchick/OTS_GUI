#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::numIteration = 0;
    connect(timer, &QTimer::timeout, this, MainWindow::Iteration(simulationModel));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_simulate_Button_clicked()
{
    int truePointCoordX = ui->x_input->text().toInt();
    int truePointCoordY = ui->y_input->text().toInt();
    int baseL = ui->L_input->text().toInt();
    int maxAngleError = ui->e_input->text().toInt();
    simulationModel = new Model(truePointCoordX, truePointCoordY, baseL, maxAngleError);
    timer = new QTimer(this);

    //timer->start(100);
}

void MainWindow::Iteration(Model* model)
{
    if (MainWindow::numIteration < 1000)
    {

    }
    MainWindow::numIteration += 5;
}
