#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsObject>
#include <QColor>

class Vertex;

class Edge : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(EdgeState state READ state WRITE setState)
    Q_ENUMS(EdgeState)
public:
    Edge(Vertex *sourceVertex, Vertex *destVertex);

    Vertex *sourceVertex() const;
    Vertex *destVertex() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; }

    enum EdgeState {Init, Relaxed, InPath, Error};
    static QColor EdgeColor[4];
    EdgeState state() const { return edgeState;}
    void setState(EdgeState state);

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    Vertex *source, *dest;
    EdgeState edgeState;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // EDGE_H
