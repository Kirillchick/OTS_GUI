#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PaintWidget.h"
#include <QTimer>
#include "Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static int numIteration;

private slots:
    void on_simulate_Button_clicked();
    void paintEvent(QPaintEvent *event);
    void Iteration(Model* model);

private:
    Ui::MainWindow *ui;
    PaintWidget* pW;
    QTimer* timer;
    Model* simulationModel;
};
#endif // MAINWINDOW_H
