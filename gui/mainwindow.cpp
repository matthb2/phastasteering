#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wpedantic"
#include <QtGui>
#include "mainwindow.h"
#pragma clang diagnostic pop

MainWindow::MainWindow(QWidget* p) : QWidget(p)
{
	setWindowTitle("");
	layout = new QGridLayout;
	layout->setColumnStretch(0,100);
	layout->setRowStretch(0,100);
	layout->addWidget(viewer, 0,0);
	setLayout(layout);
}
MainWindow::~MainWindow()
{
	delete viewer;
}
