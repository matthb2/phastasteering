#ifndef __SCENEVIEWER_H__
#define __SCENEVIEWER_H__
#include <QtGui>
#include <QWidget>

class MainWindow :public QWidget
{
Q_OBJECT
	public:
		MainWindow(QWidget* p = NULL);
		~MainWindow();
	private:
		QGridLayout* layout;
};
#endif
