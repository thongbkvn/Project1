#ifndef BFS_H
#define BFS_H
#include "algorithm.h"
#include <QSequentialAnimationGroup>
class MainWindow;
class Edge;
class Vertex;


#include "edge.h"

class BFSAnimation : public Algorithm
{
    Q_OBJECT
public:
    BFSAnimation(MainWindow *mainWindow);

    Algorithm::AlgType type() const override {return Algorithm::BFS;}
    Edge* newEdge(Vertex *, Vertex *) override;
protected:
    void generateAnimationList() override;
private:
    void BFSVertex(Vertex *v);
    //void discoverVertex(Vertex *v);

    QSequentialAnimationGroup *animationGroup;

};

#endif // BFS_H
