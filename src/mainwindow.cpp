#include "mainwindow.h"
#include "ui.h"



MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);
	m_gl = new NGLScene(this);

	// add opengl widget: 5 sections for ui and 1 for widget
	m_ui->mainwin_grid_layout->addWidget(m_gl, 1, 0, 5, 1);
	connect(m_ui->bt_inc, SIGNAL(clicked()), m_gl, SLOT(changeIncZ()));
	connect(m_ui->bt_dec, SIGNAL(clicked()), m_gl, SLOT(changedecZ()));
	connect(m_ui->bt_reset, SIGNAL(clicked()), m_gl, SLOT(changeresetZ()));
	connect(m_ui->bt_quit, SIGNAL(clicked()), m_gl, SLOT(quit()));
	
	connect(m_ui->alphaBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changealphaValue(int)));
	connect(m_ui->adBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeuadValue(int)));
	connect(m_ui->bdBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeubdValue(int)));
	connect(m_ui->tolBar, SIGNAL(valueChanged(int)), m_gl, SLOT(changeutolValue(int)));



	connect(m_ui->dcgValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcgValue(double)));
	connect(m_ui->dcrValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcrValue(double)));
	connect(m_ui->dcbValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changedcbValue(double)));

	connect(m_ui->ccbValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccbValue(double)));
	connect(m_ui->ccgValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccgValue(double)));
	connect(m_ui->ccrValue, SIGNAL(valueChanged(double)), m_gl, SLOT(changeccrValue(double)));

}
/// \brief dtor
MainWindow::~MainWindow()
{
    delete m_ui;
}


//--------------------------------------------------------------------------
/// @brief suspend simulation
//--------------------------------------------------------------------------
void MainWindow::on_StopButton_clicked()
{    //m_gl->stopSimulate();
}


//--------------------------------------------------------------------------
/// @brief replay simulation
//--------------------------------------------------------------------------
void MainWindow::on_replayButton_clicked()
{
   // m_gl->playSimulate();
}


//--------------------------------------------------------------------------
/// @brief reset all status back to initial
//--------------------------------------------------------------------------
void MainWindow::on_RedoButton_clicked()
{
   /* m_ui->Ground->setCheckState( Qt::Checked );
    m_ui->WindF_V->setValue( -0.6 );

    m_ui->HangingTL->setCheckState( Qt::Checked );
    m_ui->HangingTR->setCheckState( Qt::Checked );
    m_ui->HangingBL->setCheckState( Qt::Checked );
    m_ui->HangingBR->setCheckState( Qt::Checked );

    m_ui->Shear_V->setValue( 1.0 );
    m_ui->Bend_V->setValue( 2.0 );
    m_ui->Stiffness_V->setValue( 1.0 );
    m_ui->Damping_V->setValue( 0.5 );
    m_ui->Ks_V->setValue( 0.7 );

    m_ui->objcollide->setCheckState( Qt::Unchecked );

    m_gl->resetAll();*/
}
