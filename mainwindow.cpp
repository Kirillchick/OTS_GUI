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
    QFile logFile1("C:/Projects/Qt/OTS/OTS_Project/logd1.txt");
    QFile logFile2("C:/Projects/Qt/OTS/OTS_Project/logd2.txt");
    if (!logFile1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cannot open";
        return;
    }
    if (!logFile2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cannot open";
        return;
    }
    QTextStream out1(&logFile1);
    QTextStream out2(&logFile2);
    if (numIteration < 500)
    {
        simulationModel->Iteration(numIteration);
    }
    else
    {
        timer->stop();
        for (int i = 0; i < simulationModel->GetLogTable().size(); ++i)
        {
            out1 << simulationModel->GetLogTable()[i][0] << "\n";
            out2 << simulationModel->GetLogTable()[i][1] << "\n";
            /*for (int j = 0; j < simulationModel->GetLogTable()[i].size(); ++j)
            {

            }*/
        }
        qDebug() << "END";
    }
    numIteration += 2;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    /*QPainter *paint = new QPainter(this);
    paint->setPen(Qt::red);
    paint->drawLine(500, 500, 600, 600);
    //paint->drawPolygon()*/

}
