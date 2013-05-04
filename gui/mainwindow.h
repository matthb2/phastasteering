#ifndef __SCENEVIEWER_H__
#define __SCENEVIEWER_H__
#include <QtGui>
#include <QWidget>
#include <zmq.hpp>

class MainWindow :public QWidget
{
Q_OBJECT
	public:
		MainWindow(QWidget* p = NULL);
		~MainWindow();
	public slots:
		void connecttosolver(bool);
	protected:
		QLineEdit* ip;
		QLineEdit* port;
		QLineEdit* pressure;
		zmq::context_t* zmqcontext;
	private:
		QGridLayout* layout;
};
#endif
