/********************************************************************************
** Form generated from reading UI file 'bn_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BN_GUI_H
#define UI_BN_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_bn_guiClass
{
public:
    QAction *actionOpen_first_image;
    QAction *actionOpen_second_image;
    QAction *actionExit;
    QAction *actionReadme;
    QAction *actionAbout;
    QAction *actionOpen_Line_File;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    ClickableLabel *first_pic;
    ClickableLabel *second_pic;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bn_guiClass)
    {
        if (bn_guiClass->objectName().isEmpty())
            bn_guiClass->setObjectName(QStringLiteral("bn_guiClass"));
        bn_guiClass->resize(1065, 884);
        actionOpen_first_image = new QAction(bn_guiClass);
        actionOpen_first_image->setObjectName(QStringLiteral("actionOpen_first_image"));
        actionOpen_second_image = new QAction(bn_guiClass);
        actionOpen_second_image->setObjectName(QStringLiteral("actionOpen_second_image"));
        actionExit = new QAction(bn_guiClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionReadme = new QAction(bn_guiClass);
        actionReadme->setObjectName(QStringLiteral("actionReadme"));
        actionAbout = new QAction(bn_guiClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionOpen_Line_File = new QAction(bn_guiClass);
        actionOpen_Line_File->setObjectName(QStringLiteral("actionOpen_Line_File"));
        centralWidget = new QWidget(bn_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1624, 783));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        first_pic = new ClickableLabel(scrollAreaWidgetContents);
        first_pic->setObjectName(QStringLiteral("first_pic"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(first_pic->sizePolicy().hasHeightForWidth());
        first_pic->setSizePolicy(sizePolicy);
        first_pic->setPixmap(QPixmap(QString::fromUtf8(":/bn_gui/metig2.jpg")));
        first_pic->setScaledContents(false);

        horizontalLayout_2->addWidget(first_pic);

        second_pic = new ClickableLabel(scrollAreaWidgetContents);
        second_pic->setObjectName(QStringLiteral("second_pic"));
        sizePolicy.setHeightForWidth(second_pic->sizePolicy().hasHeightForWidth());
        second_pic->setSizePolicy(sizePolicy);
        second_pic->setPixmap(QPixmap(QString::fromUtf8(":/bn_gui/tiger.jpg")));
        second_pic->setScaledContents(false);

        horizontalLayout_2->addWidget(second_pic);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(2);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(listWidget);

        bn_guiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(bn_guiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1065, 18));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        bn_guiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bn_guiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        bn_guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(bn_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        bn_guiClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOpen->addAction(actionOpen_first_image);
        menuOpen->addAction(actionOpen_second_image);
        menuOpen->addAction(actionOpen_Line_File);
        menuOpen->addAction(actionExit);
        menuHelp->addAction(actionReadme);
        menuHelp->addAction(actionAbout);

        retranslateUi(bn_guiClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), bn_guiClass, SLOT(remove_line()));
        QObject::connect(actionOpen_second_image, SIGNAL(triggered()), bn_guiClass, SLOT(open_second()));
        QObject::connect(actionOpen_first_image, SIGNAL(triggered()), bn_guiClass, SLOT(open_first()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), bn_guiClass, SLOT(set_output_file()));
        QObject::connect(first_pic, SIGNAL(clicked(QPoint)), bn_guiClass, SLOT(first_image_clicked(QPoint)));
        QObject::connect(actionOpen_Line_File, SIGNAL(triggered()), bn_guiClass, SLOT(load_lines()));
        QObject::connect(second_pic, SIGNAL(clicked(QPoint)), bn_guiClass, SLOT(second_image_clicked(QPoint)));
        QObject::connect(pushButton, SIGNAL(clicked()), bn_guiClass, SLOT(add_line()));

        QMetaObject::connectSlotsByName(bn_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *bn_guiClass)
    {
        bn_guiClass->setWindowTitle(QApplication::translate("bn_guiClass", "bn_gui", 0));
        actionOpen_first_image->setText(QApplication::translate("bn_guiClass", "Open first image", 0));
        actionOpen_second_image->setText(QApplication::translate("bn_guiClass", "Open second image", 0));
        actionExit->setText(QApplication::translate("bn_guiClass", "Exit", 0));
        actionReadme->setText(QApplication::translate("bn_guiClass", "Readme", 0));
        actionAbout->setText(QApplication::translate("bn_guiClass", "About", 0));
        actionOpen_Line_File->setText(QApplication::translate("bn_guiClass", "Open Line File", 0));
        first_pic->setText(QString());
        second_pic->setText(QString());
        label_3->setText(QApplication::translate("bn_guiClass", "Frames:", 0));
        pushButton->setText(QApplication::translate("bn_guiClass", "Add Line", 0));
        pushButton_3->setText(QApplication::translate("bn_guiClass", "Remove Line", 0));
        pushButton_4->setText(QApplication::translate("bn_guiClass", "...", 0));
        pushButton_2->setText(QApplication::translate("bn_guiClass", "Morph", 0));
        menuOpen->setTitle(QApplication::translate("bn_guiClass", "Open", 0));
        menuHelp->setTitle(QApplication::translate("bn_guiClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class bn_guiClass: public Ui_bn_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BN_GUI_H
