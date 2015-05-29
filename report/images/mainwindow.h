#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <algorithm.h>
class GraphScene;
class GraphWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Algorithm::AlgType algo,QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSelect_triggered();

    void on_actionDrawVertex_triggered();

    void on_actionDrawEdge_triggered();

private:
    Ui::MainWindow *ui;
    QActionGroup *modeActionGroup;

    GraphWidget *graphWidget;
    GraphScene *m_scene;
    Algorithm *algorithm;

};

#endif // MAINWINDOW_H
