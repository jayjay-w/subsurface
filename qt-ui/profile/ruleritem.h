#ifndef RULERITEM_H
#define RULERITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsObject>

struct plot_data;
class RulerItem2;

class RulerNodeItem2 : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT
	friend class RulerItem2;
public:
	explicit RulerNodeItem2(QGraphicsItem* parent);
	void setRuler(RulerItem2 *r);
	void recalculate();

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant & value );

private:
	struct plot_data *entry;
	RulerItem2* ruler;
};

class RulerItem2 : public QGraphicsObject
{
	Q_OBJECT
public:
	explicit RulerItem2(QGraphicsItem* parent,
			   RulerNodeItem2 *sourceMarker,
			   RulerNodeItem2 *destMarker);
	void recalculate();

	RulerNodeItem2* sourceNode() const;
	RulerNodeItem2* destNode() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget = 0);
	QRectF boundingRect() const;
	QPainterPath shape() const;

private:
	QPointF startPoint, endPoint;
	RulerNodeItem2 *source, *dest;
	QString text;
	int height;
	int paint_direction;
};
#endif