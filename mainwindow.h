#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "PaintWidget.h"
#include <QTimer>
#include "Model.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Iteration();

private slots:
    void on_simulate_Button_clicked();

    //void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    int numIteration = 0;
    //PaintWidget* pW;
    QTimer* timer;
    Model* simulationModel;
};
#endif // MAINWINDOW_H
