#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QtGui>
#include <QtDebug>
#include "ui_wd.h"

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<termios.h>
#include<sys/types.h>
#include<sys/stat.h>

#define u8 unsigned char
struct Datastruct
{
  u8 head[3];//={0xfe,0x55,0xaa};
  u8 lenth;//=2;
  u8 cmd;//=0xbc;
  u8 para[128];
} ;


class mainwindow :public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow ui;
    int servoValue[100];
    int fd;
    u8 dwPolynomial;
    Datastruct serialData;
    void ComInit(void);
    u8 cal_crc (u8 *ptr, int len);
public:
  mainwindow(QMainWindow *parent=0);

private slots:
  void on_Slider0_valueChanged(int value);
  void on_Slider1_valueChanged(int value);
  void on_Slider2_valueChanged(int value);
  void on_Slider3_valueChanged(int value);
  void on_Slider4_valueChanged(int value);
  void on_Slider5_valueChanged(int value);
  void on_Slider6_valueChanged(int value);
  void on_Slider7_valueChanged(int value);
  void on_Slider8_valueChanged(int value);
  void on_Slider9_valueChanged(int value);
  void on_Slider10_valueChanged(int value);
  void on_Slider11_valueChanged(int value);
  void on_Slider12_valueChanged(int value);
  void on_Slider13_valueChanged(int value);
  void on_Slider14_valueChanged(int value);
  void on_Slider15_valueChanged(int value);
  void on_spinBox0_valueChanged(int arg1);
  void on_spinBox1_valueChanged(int arg1);
  void on_spinBox2_valueChanged(int arg1);
  void on_spinBox3_valueChanged(int arg1);
  void on_spinBox4_valueChanged(int arg1);
  void on_spinBox5_valueChanged(int arg1);
  void on_spinBox6_valueChanged(int arg1);
  void on_spinBox7_valueChanged(int arg1);
  void on_spinBox8_valueChanged(int arg1);
  void on_spinBox9_valueChanged(int arg1);
  void on_spinBox10_valueChanged(int arg1);
  void on_spinBox11_valueChanged(int arg1);
  void on_spinBox12_valueChanged(int arg1);
  void on_spinBox13_valueChanged(int arg1);
  void on_spinBox14_valueChanged(int arg1);
  void on_spinBox15_valueChanged(int arg1);
};
#endif
