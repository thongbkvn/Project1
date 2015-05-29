#ifndef ALGORITHM_H
#define ALGORITHM_H

class MainWindow;
class GraphScene;
class Vertex;
class Edge;
class QAction;
class QAbstractAnimation;

#include <QVector>
#include <QList>
#include <QObject>
#include <QToolBar>
#include <memory>

class Algorithm: public QObject
{
    Q_OBJECT
public:
    Algorithm(MainWindow *mainWindow);
    enum AlgType{DFS, BFS, ShortestPath};

     void incEdge() {++nEdge;}
     void decEdge() {--nEdge;}
     void clearEdge() {nEdge = 0;}

    QToolBar* getAnimationToolBar();

    virtual Edge* newEdge(Vertex*, Vertex*) = 0;

    void setSelectedVertex(Vertex *);

    static Algorithm *getAlgorithm(AlgType, MainWindow*);

    virtual AlgType type() const = 0;

    friend class GraphScene;

    void resetState();
public slots:
    void setSource();
    void setDest();

    void addVertex(Vertex *);
    void removeVertex(Vertex *);

protected:
    MainWindow *mainWindow;
    int nEdge;

    QList<Vertex*> vertexList;

    Vertex *selectedVertex;
    Vertex *sourceVertex;
    Vertex *destVertex;



    void timerEvent(QTimerEvent *) override;
    virtual void generateAnimationList() = 0;
    void generateBFSAnimationList(); //debug

    QList<std::shared_ptr<QAbstractAnimation> > animationList;
    QList<std::shared_ptr<QAbstractAnimation> >::iterator currentAnimation;

    void setDelay(int dl) {delay = dl;}

    void createToolBar();
    void createActions();

protected slots:
    void finishAnimation();
    void initAllItem();


private:
    int delay;
    int timerId;

    bool isPaused;
    bool isStarted;
    bool isAutoPlay;
    bool isForward;

    QAction *playAction;
    QAction *nextAction;
    QAction *prevAction;
    QAction *stopAction;

    QToolBar *animationToolBar;
private slots:
    void play();
    void next();
    void prev();
    void stop();
};

#endif // ALGORITHM_H
