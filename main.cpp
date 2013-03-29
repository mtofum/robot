#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  mainwindow window;
  window.show();
  return app.exec();
}

