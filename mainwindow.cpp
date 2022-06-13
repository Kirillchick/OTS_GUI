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

    timer->start(10);
    //timer->start(100);
}

void MainWindow::Iteration()
{
    QFile logFile("C:/Projects/Qt/OTS/OTS_Project/log.txt");
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cannot open";
        return;
    }
    QTextStream out(&logFile);
    if (numIteration < 500)
    {
        simulationModel->Iteration(numIteration);
    }
    else
    {
        timer->stop();
        for (int i = 0; i < simulationModel->GetLogTable().size(); ++i)
        {
            for (int j = 0; j < simulationModel->GetLogTable()[i].size(); ++j)
            {
                out << simulationModel->GetLogTable()[i][j] << " ";
            }
            out << "\n";
        }
        qDebug() << "END";
    }
    numIteration += 5;
}
