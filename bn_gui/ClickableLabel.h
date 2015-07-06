#include <QtWidgets/QLabel>
#include <vector>
#include <LineSegment.cpp>
#include <qpainter.h>
#include "bn.h"

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

		if (highlight_idx > -1)
		{
			bn::LineSegment ls = lp[highlight_idx];
			painter.setPen(QPen(Qt::blue, 4, Qt::SolidLine, Qt::RoundCap));
			painter.drawLine(ls.p.x, ls.p.y, ls.q.x, ls.q.y);
		}

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

	void enable_highlight(int idx)
	{
		highlight_idx = idx;
		update();
	}

	void disable_highlight()
	{
		highlight_idx = -1;
		update();
	}

	int closest_line(const QPoint& pos) const
	{
		for (unsigned int i = 0; i < lp.size(); ++i)
		{
			if (point_line_distance(lp[i].p, lp[i].q, cv::Point2d(pos.x(), pos.y())) < 4)
				return i;
		}

		return -1;
	}

signals:
	void clicked(const QPoint& pos);
protected:
	void mousePressEvent(QMouseEvent* event);
private:
	std::vector<bn::LineSegment> lp;
	bool draw_point;
	int highlight_idx;
	QPoint point;
};