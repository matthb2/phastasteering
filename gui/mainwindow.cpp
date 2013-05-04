#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wpedantic"
#include <QtGui>
#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <iostream>
#include "mainwindow.h"
#include <zmq.hpp>
#pragma clang diagnostic pop

MainWindow::MainWindow(QWidget* p) : QWidget(p)
{
	setWindowTitle("");
	layout = new QGridLayout;
	layout->setColumnStretch(0,100);
	layout->setRowStretch(0,100);
	//layout->addWidget(viewer, 0,0);
	ip = new QLineEdit();
	QLabel* iplabel = new QLabel("Solver Hostname");
	layout->addWidget(ip);
	layout->addWidget(iplabel);	
	ip->setText("localhost");
	port = new QLineEdit();
	QLabel* portlabel = new QLabel("Solver Port");
	layout->addWidget(port);
	layout->addWidget(portlabel);
	port->setText("5555");
	pressure = new QLineEdit();
	QLabel* pressurelabel = new QLabel("Pressure");
	layout->addWidget(pressure);
	layout->addWidget(pressurelabel);
	pressure->setText("0.00");
	QPushButton* submitbutton = new QPushButton("Submit");
	layout->addWidget(submitbutton);
	QObject::connect(submitbutton, SIGNAL(clicked(bool)), 
		this, SLOT(connecttosolver(bool)));	
	setLayout(layout);
	zmqcontext = new zmq::context_t(1);
}
MainWindow::~MainWindow()
{
}
void MainWindow::connecttosolver(bool e)
{
	std::string url("tcp://");
	url.append(ip->text().toStdString());
	url.append(":");
	url.append(port->text().toStdString());
	std::cout << url << std::endl;
	printf("Clicked\n");
	zmq::socket_t socket(*zmqcontext, ZMQ_PAIR);
	socket.connect(url.c_str());
	const char* pressure_data = pressure->text().toStdString().c_str();
	int len = strlen(pressure_data)+1;
	if(len > 99) len = 99;
	zmq::message_t request(len);
	memcpy((void*) request.data(), pressure_data, len);
	socket.send(request);
	socket.close();
}
