#ifndef DFS_H
#define DFS_H

#include "algorithm.h"

class MainWindow;
class Edge;
class Vertex;
class QSequentialAnimationGroup;

class DFSAnimation : public Algorithm
{
    Q_OBJECT
public:
    DFSAnimation(MainWindow *mainWindow);

    Algorithm::AlgType type() const override {return Algorithm::DFS;}
    Edge *newEdge(Vertex *, Vertex *) override;

protected:
    void generateAnimationList() override;
private:
    void DFSVertex(Vertex *v);

    QSequentialAnimationGroup *animationGroup;

};

#endif // DFS_H
