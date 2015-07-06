#include <QtWidgets/QLabel>
#include <vector>
#include <LineSegment.cpp>
#include <qpainter.h>

class ClickableLabel : public QLabel
{
	Q_OBJECT
public:
	explicit ClickableLabel(const QString& text = "", QWidget* parent = 0);
	explicit ClickableLabel(QWidget* parent) : ClickableLabel("", parent) {}
	
	~ClickableLabel();


	void paintEvent(QPaintEvent *pe)
	{
		QLabel::paintEvent(pe);
		QPainter painter(this);
		painter.setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap));

		for (auto itr = lp.begin(); itr != lp.end(); ++itr)
			painter.drawLine(itr->p.x, itr->p.y, itr->q.x, itr->q.y);

		painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine, Qt::RoundCap));
		for (auto itr = lp.begin(); itr != lp.end(); ++itr)
		{
			painter.drawPoint(itr->p.x, itr->p.y);
			painter.drawPoint(itr->q.x, itr->q.y);
		}

		if (draw_point)
			painter.drawPoint(point);
	}

	void add_line(const bn::LineSegment& ls)
	{
		lp.push_back(ls);
		update();
	}

	void remove_line(int idx)
	{
		lp.erase(lp.begin() + idx);
		update();
	}

	void load_lines(const std::vector<bn::LineSegment>& lp_)
	{
		lp.clear();
		lp = lp_;
		update();
	}

	void enable_point(const QPoint& point_)
	{
		point = point_;
		draw_point = true;
		update();
	}

	void disable_point()
	{
		draw_point = false;
		update();
	}

signals:
	void clicked(const QPoint& pos);
protected:
	void mousePressEvent(QMouseEvent* event);
private:
	std::vector<bn::LineSegment> lp;
	bool draw_point;
	QPoint point;
};