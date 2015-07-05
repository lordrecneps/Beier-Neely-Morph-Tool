#ifndef BN_GUI_H
#define BN_GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bn_gui.h"
#include <iostream>
#include <qfiledialog.h>
#include "bn.cpp"

class bn_gui : public QMainWindow
{
	Q_OBJECT

public:
	bn_gui(QWidget *parent = 0);
	~bn_gui();

public slots:
	void open_first()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
		ui.listWidget->addItem(new QListWidgetItem(fileName));
	}

	void open_second()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
		ui.listWidget->addItem( new QListWidgetItem(fileName) );
	}

	void load_lines()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
	}

	void add_line()
	{
		if (add_line_state == 0)
			add_line_state = 1;
	}

	void first_image_clicked()
	{
		if (add_line_state == 1)
		{
			add_line_state = 2;
			return;
		}

		if (add_line_state == 2)
		{
			add_line_state = 3;
			return;
		}
	}

	void second_image_clicked()
	{
		if (add_line_state == 3)
		{
			add_line_state = 4;
			return;
		}

		if (add_line_state == 4)
		{
			add_line_state = 0;
			return;
		}
	}

	void remove_line()
	{
		qDeleteAll( ui.listWidget->selectedItems() );
	}

	void start_morph()
	{
		morph("../../03.jpg", "../../04.jpg", "../../lines34.txt", "../../nwf/out.jpg");
	}

	void set_output_file()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
	}

private:
	Ui::bn_guiClass ui;
	int add_line_state;

};

#endif // BN_GUI_H
