#ifndef BN_GUI_H
#define BN_GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bn_gui.h"
#include <iostream>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qprogressdialog.h>
#include "bn.h"
#include <sstream>

class bn_gui : public QMainWindow
{
	Q_OBJECT

public:
	bn_gui(QWidget *parent = 0);
	~bn_gui();

public slots:
	void open_first()
	{
		img_file_1 = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
		QImage imgObj(img_file_1);

		if (imgObj.isNull())
			return;

		QPixmap img = QPixmap::fromImage(imgObj);

		ui.first_pic->setPixmap(img);
	}

	void open_second()
	{
		img_file_2 = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
		QImage imgObj(img_file_2);

		if (imgObj.isNull())
			return;

		QPixmap img = QPixmap::fromImage(imgObj);

		ui.second_pic->setPixmap(img);
	}

	void load_lines()
	{
		if (!pic_sizes_equal())
			return;

		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
		QByteArray array = fileName.toLocal8Bit();
		char* buffer = array.data();
		lp.load(buffer);

		ui.listWidget->clear();
		std::stringstream list_str;
		std::vector<bn::LineSegment> img_lines_1, img_lines_2;
		for (auto itr = lp.line_pairs.begin(); itr != lp.line_pairs.end(); ++itr)
		{
			list_str << *itr;
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(list_str.str()));
			ui.listWidget->addItem(item);
			
			img_lines_1.push_back(itr->l1);
			img_lines_2.push_back(itr->l2);

			list_str.str("");
		}

		ui.first_pic->load_lines(img_lines_1);
		ui.second_pic->load_lines(img_lines_2);
	}

	void add_line()
	{
		if (!pic_sizes_equal())
			return;

		if (add_line_state == 0)
		{
			add_line_state = 1;
		}
	}

	bool select_line(const QPoint& pos, const ClickableLabel* pic)
	{
		if (add_line_state == 0)
		{
			int idx = pic->closest_line(pos);
			if (idx >= 0)
				ui.listWidget->setCurrentRow(idx);
			return true;
		}
		return false;
	}

	void first_image_clicked(const QPoint& pos)
	{
		if (select_line(pos, ui.first_pic))
			return;

		if (add_line_state == 1)
		{
			tp.l1.p.x = pos.x();
			tp.l1.p.y = pos.y();
			ui.first_pic->enable_point(pos);
			add_line_state = 2;
			return;
		}

		if (add_line_state == 2)
		{
			tp.l1.q.x = pos.x();
			tp.l1.q.y = pos.y();
			ui.first_pic->disable_point();
			ui.first_pic->add_line(tp.l1);
			add_line_state = 3;
			return;
		}
	}

	void second_image_clicked(const QPoint& pos)
	{
		if (select_line(pos, ui.second_pic))
			return;

		if (add_line_state == 3)
		{
			tp.l2.p.x = pos.x();
			tp.l2.p.y = pos.y();
			ui.second_pic->enable_point(pos);
			add_line_state = 4;
			return;
		}

		if (add_line_state == 4)
		{
			tp.l2.q.x = pos.x();
			tp.l2.q.y = pos.y();

			ui.second_pic->disable_point();
			ui.second_pic->add_line(tp.l2);

			tp.l1.init_vectors();
			tp.l2.init_vectors();

			lp.add_line(tp);

			std::stringstream list_str;
			list_str << tp;
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(list_str.str()));
			ui.listWidget->addItem(item);

			add_line_state = 0;
			return;
		}
	}

	void remove_line()
	{
		if (ui.listWidget->count() == 0)
		{
			QMessageBox msgBox;
			msgBox.setText("There are no lines to remove.");
			msgBox.exec();
			return;
		}

		int idx = ui.listWidget->currentRow();
		ui.first_pic->remove_line(idx);
		ui.second_pic->remove_line(idx);
		delete ui.listWidget->currentItem();

		lp.line_pairs.erase(lp.line_pairs.begin() + idx);
	}

	void start_morph()
	{
		if (!pic_sizes_equal())
			return;

		QMessageBox msgBox;

		if (lp.line_pairs.empty())
		{
			msgBox.setText("You must have at least 1 pair of lines to perform the morph.");
			msgBox.exec();
			return;
		}

		if (ui.lineEdit->text().isEmpty())
		{
			msgBox.setText("You must set the location and name of the output files.");
			msgBox.exec();
			return;
		}

		int frames = ui.spinBox->value();
		QProgressDialog progress("Performing morph...", QString(), 0, frames + 1, this);
		progress.setWindowModality(Qt::WindowModal);

		morph(img_file_1.toStdString(), img_file_2.toStdString(), lp, out_file.toStdString(), frames, [&progress](int val) {progress.setValue(val); });
	}

	void set_output_file()
	{
		out_file = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("JPEG Files (*.jpg *.jpeg)"));
		ui.lineEdit->setText(out_file);
	}

	void highlight_list(int row)
	{
		if (row < 0 || row >= lp.line_pairs.size())
			return;
		ui.first_pic->enable_highlight(row);
		ui.second_pic->enable_highlight(row);
	}

	bool pic_sizes_equal()
	{
		const QPixmap* img1 = ui.first_pic->pixmap();
		const QPixmap* img2 = ui.second_pic->pixmap();

		if (!img1 || !img2 || img1->size() != img2->size())
		{
			QMessageBox msgBox;
			msgBox.setText("You must load two images with the same dimensions to proceed.");
			msgBox.exec();
			return false;
		}

		return true;
	}

private:
	Ui::bn_guiClass ui;
	int add_line_state;
	bn::LinePairs lp;
	bn::LinePair tp;

	QString img_file_1, img_file_2, out_file;
};

#endif // BN_GUI_H
