#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QList>

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;


class Vertex : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(VertexColor color READ color WRITE setColor)
    Q_ENUMS(VertexColor)
public:
    Vertex(qreal x, qreal y);

    void addInEdge(Edge *edge);
    void addOutEdge(Edge *edge);

    bool removeInEdge(Edge *edge);
    bool removeOutEdge(Edge *edge);


    QList<Edge *> inEdges() const {return inEdgeList;}
    QList<Edge *> outEdges() const {return outEdgeList;}

    enum { Type = UserType + 1 };
    int type() const Q_DECL_OVERRIDE { return Type; }

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    enum VertexColor{Init, Visited,  Source, Destination, Discovered};
    static QColor vertexColor[5][2];


    static int interconnect;

    VertexColor color() const {return m_color;}
    void setColor(VertexColor);

    int getId() const {return id;}

    void setAssociate(int m) {m_associate = m;}
    int associate() const {return m_associate;}

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QList<Edge *> inEdgeList;
    QList<Edge *> outEdgeList;
    QPointF newPos;
    static int vertexID;//new

    int m_associate;
    int id;//new
    VertexColor m_color;
};

#endif // VERTEX_H
