/********************************************************************************
** Form generated from reading UI file 'mainwindowqbFDeA.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWQBFDEA_H
#define MAINWINDOWQBFDEA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
	QWidget *centralWidget;
	QGridLayout *mainwin_grid_layout;
	QGroupBox *dotColor;
	QGridLayout *gridLayout_3;
	QLabel *dcrLabel;
	QLabel *ccgLabel_3;
	QDoubleSpinBox *dcrValue;
	QDoubleSpinBox *dcbValue;
	QDoubleSpinBox *dcgValue;
	QLabel *ccbLabel_2;
	QSpacerItem *horizontalSpacer;
	QGroupBox *baseControl;
	QGridLayout *gridLayout_2;
	QSlider *bdBar;
	QLabel *bdLabel;
	QSlider *alphaBar;
	QSlider *adBar;
	QLabel *tolLable;
	QLabel *adLabel;
	QLabel *AlphaLabel;
	QSlider *tolBar;
	QGroupBox *colorControl;
	QGridLayout *gridLayout_7;
	QLabel *ccgLabel;
	QLabel *ccgLabel_2;
	QDoubleSpinBox *ccrValue;
	QDoubleSpinBox *ccbValue;
	QDoubleSpinBox *ccgValue;
	QLabel *ccbLabel;
	QGroupBox *operate;
	QGridLayout *gridLayout_4;
	QPushButton *bt_quit;
	QPushButton *bt_reset;
	QPushButton *bt_dec;
	QPushButton *bt_inc;
	QStatusBar *statusBar;

	void setupUi(QMainWindow *MainWindow)
	{
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
		MainWindow->setEnabled(true);
		MainWindow->resize(1100, 700);
		MainWindow->setMinimumSize(QSize(750, 600));
		centralWidget = new QWidget(MainWindow);
		centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
		mainwin_grid_layout = new QGridLayout(centralWidget);
		mainwin_grid_layout->setSpacing(6);
		mainwin_grid_layout->setContentsMargins(11, 11, 11, 11);
		mainwin_grid_layout->setObjectName(QString::fromUtf8("mainwin_grid_layout"));
		dotColor = new QGroupBox(centralWidget);
		dotColor->setObjectName(QString::fromUtf8("dotColor"));
		gridLayout_3 = new QGridLayout(dotColor);
		gridLayout_3->setSpacing(6);
		gridLayout_3->setContentsMargins(11, 11, 11, 11);
		gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
		dcrLabel = new QLabel(dotColor);
		dcrLabel->setObjectName(QString::fromUtf8("dcrLabel"));

		gridLayout_3->addWidget(dcrLabel, 1, 1, 1, 1);

		ccgLabel_3 = new QLabel(dotColor);
		ccgLabel_3->setObjectName(QString::fromUtf8("ccgLabel_3"));

		gridLayout_3->addWidget(ccgLabel_3, 2, 1, 1, 1);

		dcrValue = new QDoubleSpinBox(dotColor);
		dcrValue->setObjectName(QString::fromUtf8("dcrValue"));
		QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(dcrValue->sizePolicy().hasHeightForWidth());
		dcrValue->setSizePolicy(sizePolicy);
		dcrValue->setMaximum(1.000000000000000);
		dcrValue->setSingleStep(0.010000000000000);
		dcrValue->setValue(0.400000000000000);

		gridLayout_3->addWidget(dcrValue, 1, 2, 1, 1);

		dcbValue = new QDoubleSpinBox(dotColor);
		dcbValue->setObjectName(QString::fromUtf8("dcbValue"));
		dcbValue->setMaximum(1.000000000000000);
		dcbValue->setSingleStep(0.010000000000000);
		dcbValue->setValue(0.930000000000000);

		gridLayout_3->addWidget(dcbValue, 3, 2, 1, 1);

		dcgValue = new QDoubleSpinBox(dotColor);
		dcgValue->setObjectName(QString::fromUtf8("dcgValue"));
		sizePolicy.setHeightForWidth(dcgValue->sizePolicy().hasHeightForWidth());
		dcgValue->setSizePolicy(sizePolicy);
		dcgValue->setMaximum(1.000000000000000);
		dcgValue->setSingleStep(0.010000000000000);
		dcgValue->setValue(0.850000000000000);

		gridLayout_3->addWidget(dcgValue, 2, 2, 1, 1);

		ccbLabel_2 = new QLabel(dotColor);
		ccbLabel_2->setObjectName(QString::fromUtf8("ccbLabel_2"));

		gridLayout_3->addWidget(ccbLabel_2, 3, 1, 1, 1);


		mainwin_grid_layout->addWidget(dotColor, 3, 1, 1, 1);

		horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		mainwin_grid_layout->addItem(horizontalSpacer, 1, 0, 1, 1);

		baseControl = new QGroupBox(centralWidget);
		baseControl->setObjectName(QString::fromUtf8("baseControl"));
		baseControl->setEnabled(true);
		gridLayout_2 = new QGridLayout(baseControl);
		gridLayout_2->setSpacing(6);
		gridLayout_2->setContentsMargins(11, 11, 11, 11);
		gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
		bdBar = new QSlider(baseControl);
		bdBar->setObjectName(QString::fromUtf8("bdBar"));
		QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(bdBar->sizePolicy().hasHeightForWidth());
		bdBar->setSizePolicy(sizePolicy1);
		bdBar->setOrientation(Qt::Horizontal);

		gridLayout_2->addWidget(bdBar, 3, 1, 1, 1);

		bdLabel = new QLabel(baseControl);
		bdLabel->setObjectName(QString::fromUtf8("bdLabel"));

		gridLayout_2->addWidget(bdLabel, 3, 0, 1, 1);

		alphaBar = new QSlider(baseControl);
		alphaBar->setObjectName(QString::fromUtf8("alphaBar"));
		sizePolicy1.setHeightForWidth(alphaBar->sizePolicy().hasHeightForWidth());
		alphaBar->setSizePolicy(sizePolicy1);
		alphaBar->setValue(99);
		alphaBar->setOrientation(Qt::Horizontal);

		gridLayout_2->addWidget(alphaBar, 1, 1, 1, 1);

		adBar = new QSlider(baseControl);
		adBar->setObjectName(QString::fromUtf8("adBar"));
		sizePolicy1.setHeightForWidth(adBar->sizePolicy().hasHeightForWidth());
		adBar->setSizePolicy(sizePolicy1);
		adBar->setOrientation(Qt::Horizontal);

		gridLayout_2->addWidget(adBar, 2, 1, 1, 1);

		tolLable = new QLabel(baseControl);
		tolLable->setObjectName(QString::fromUtf8("tolLable"));

		gridLayout_2->addWidget(tolLable, 4, 0, 1, 1);

		adLabel = new QLabel(baseControl);
		adLabel->setObjectName(QString::fromUtf8("adLabel"));

		gridLayout_2->addWidget(adLabel, 2, 0, 1, 1);

		AlphaLabel = new QLabel(baseControl);
		AlphaLabel->setObjectName(QString::fromUtf8("AlphaLabel"));

		gridLayout_2->addWidget(AlphaLabel, 1, 0, 1, 1);

		tolBar = new QSlider(baseControl);
		tolBar->setObjectName(QString::fromUtf8("tolBar"));
		sizePolicy1.setHeightForWidth(tolBar->sizePolicy().hasHeightForWidth());
		tolBar->setSizePolicy(sizePolicy1);
		tolBar->setOrientation(Qt::Horizontal);

		gridLayout_2->addWidget(tolBar, 4, 1, 1, 1);


		mainwin_grid_layout->addWidget(baseControl, 1, 1, 1, 1);

		colorControl = new QGroupBox(centralWidget);
		colorControl->setObjectName(QString::fromUtf8("colorControl"));
		gridLayout_7 = new QGridLayout(colorControl);
		gridLayout_7->setSpacing(6);
		gridLayout_7->setContentsMargins(11, 11, 11, 11);
		gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
		ccgLabel = new QLabel(colorControl);
		ccgLabel->setObjectName(QString::fromUtf8("ccgLabel"));

		gridLayout_7->addWidget(ccgLabel, 1, 1, 1, 1);

		ccgLabel_2 = new QLabel(colorControl);
		ccgLabel_2->setObjectName(QString::fromUtf8("ccgLabel_2"));

		gridLayout_7->addWidget(ccgLabel_2, 2, 1, 1, 1);

		ccrValue = new QDoubleSpinBox(colorControl);
		ccrValue->setObjectName(QString::fromUtf8("ccrValue"));
		sizePolicy.setHeightForWidth(ccrValue->sizePolicy().hasHeightForWidth());
		ccrValue->setSizePolicy(sizePolicy);
		ccrValue->setMaximum(1.000000000000000);
		ccrValue->setSingleStep(0.010000000000000);
		ccrValue->setValue(0.930000000000000);

		gridLayout_7->addWidget(ccrValue, 1, 2, 1, 1);

		ccbValue = new QDoubleSpinBox(colorControl);
		ccbValue->setObjectName(QString::fromUtf8("ccbValue"));
		ccbValue->setMaximum(1.000000000000000);
		ccbValue->setSingleStep(0.050000000000000);
		ccbValue->setValue(0.930000000000000);

		gridLayout_7->addWidget(ccbValue, 3, 2, 1, 1);

		ccgValue = new QDoubleSpinBox(colorControl);
		ccgValue->setObjectName(QString::fromUtf8("ccgValue"));
		sizePolicy.setHeightForWidth(ccgValue->sizePolicy().hasHeightForWidth());
		ccgValue->setSizePolicy(sizePolicy);
		ccgValue->setMaximum(1.000000000000000);
		ccgValue->setSingleStep(0.050000000000000);
		ccgValue->setValue(0.930000000000000);

		gridLayout_7->addWidget(ccgValue, 2, 2, 1, 1);

		ccbLabel = new QLabel(colorControl);
		ccbLabel->setObjectName(QString::fromUtf8("ccbLabel"));

		gridLayout_7->addWidget(ccbLabel, 3, 1, 1, 1);


		mainwin_grid_layout->addWidget(colorControl, 2, 1, 1, 1);

		operate = new QGroupBox(centralWidget);
		operate->setObjectName(QString::fromUtf8("operate"));
		gridLayout_4 = new QGridLayout(operate);
		gridLayout_4->setSpacing(6);
		gridLayout_4->setContentsMargins(11, 11, 11, 11);
		gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
		bt_quit = new QPushButton(operate);
		bt_quit->setObjectName(QString::fromUtf8("bt_quit"));

		gridLayout_4->addWidget(bt_quit, 1, 1, 1, 1);

		bt_reset = new QPushButton(operate);
		bt_reset->setObjectName(QString::fromUtf8("bt_reset"));
		sizePolicy.setHeightForWidth(bt_reset->sizePolicy().hasHeightForWidth());
		bt_reset->setSizePolicy(sizePolicy);

		gridLayout_4->addWidget(bt_reset, 1, 0, 1, 1);

		bt_dec = new QPushButton(operate);
		bt_dec->setObjectName(QString::fromUtf8("bt_dec"));

		gridLayout_4->addWidget(bt_dec, 0, 1, 1, 1);

		bt_inc = new QPushButton(operate);
		bt_inc->setObjectName(QString::fromUtf8("bt_inc"));
		sizePolicy.setHeightForWidth(bt_inc->sizePolicy().hasHeightForWidth());
		bt_inc->setSizePolicy(sizePolicy);

		gridLayout_4->addWidget(bt_inc, 0, 0, 1, 1);


		mainwin_grid_layout->addWidget(operate, 4, 1, 1, 1);

		MainWindow->setCentralWidget(centralWidget);
		statusBar = new QStatusBar(MainWindow);
		statusBar->setObjectName(QString::fromUtf8("statusBar"));
		MainWindow->setStatusBar(statusBar);

		retranslateUi(MainWindow);

		QMetaObject::connectSlotsByName(MainWindow);
	} // setupUi

	void retranslateUi(QMainWindow *MainWindow)
	{
		MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cow view", nullptr));
		dotColor->setTitle(QApplication::translate("MainWindow", "Dot Color", nullptr));
		dcrLabel->setText(QApplication::translate("MainWindow", "R", nullptr));
		ccgLabel_3->setText(QApplication::translate("MainWindow", "G", nullptr));
		ccbLabel_2->setText(QApplication::translate("MainWindow", "B", nullptr));
		baseControl->setTitle(QApplication::translate("MainWindow", "Alpha Type", nullptr));
		bdLabel->setText(QApplication::translate("MainWindow", "uBd", nullptr));
		tolLable->setText(QApplication::translate("MainWindow", "uTol", nullptr));
		adLabel->setText(QApplication::translate("MainWindow", "uAd", nullptr));
		AlphaLabel->setText(QApplication::translate("MainWindow", "Alpha", nullptr));
		colorControl->setTitle(QApplication::translate("MainWindow", "Cow Color", nullptr));
		ccgLabel->setText(QApplication::translate("MainWindow", "R", nullptr));
		ccgLabel_2->setText(QApplication::translate("MainWindow", "G", nullptr));
		ccbLabel->setText(QApplication::translate("MainWindow", "B", nullptr));
		operate->setTitle(QApplication::translate("MainWindow", "Operate", nullptr));
		bt_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
		bt_reset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
#ifndef QT_NO_STATUSTIP
		bt_dec->setStatusTip(QApplication::translate("MainWindow", "decrease size", nullptr));
#endif // QT_NO_STATUSTIP
		bt_dec->setText(QApplication::translate("MainWindow", "Dec size", nullptr));
#ifndef QT_NO_STATUSTIP
		bt_inc->setStatusTip(QApplication::translate("MainWindow", "Increase size", nullptr));
#endif // QT_NO_STATUSTIP
		bt_inc->setText(QApplication::translate("MainWindow", "Inc size", nullptr));
	} // retranslateUi

};

namespace Ui {
	class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWQBFDEA_H
