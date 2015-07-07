#include "bn_gui.h"

bn_gui::bn_gui(QWidget *parent)
	: QMainWindow(parent), add_line_state(0)
{
	ui.setupUi(this);
	setWindowTitle("Beier-Neeley Morph Tool");
}

bn_gui::~bn_gui()
{

}
