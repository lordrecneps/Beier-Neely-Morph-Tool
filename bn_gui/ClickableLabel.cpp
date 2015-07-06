#include "ClickableLabel.h"
#include <qevent.h>

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
	: QLabel(parent), draw_point(false)
{
	setText(text);
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
	emit clicked(event->pos());
}