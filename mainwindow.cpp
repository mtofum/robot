#include "mainwindow.h"
#include "QtDebug"
mainwindow::mainwindow(QMainWindow *parent):QMainWindow(parent)
{
    ui.setupUi(this);
    dwPolynomial = 0xb7;
    serialData.head[0]=0xfe;
    serialData.head[1]=0x55;
    serialData.head[2]=0xaa;
    serialData.lenth=0x02;
    serialData.cmd=0xbc;
    ComInit();
}

void mainwindow::ComInit(void)
{
  fd = open("/dev/ttyUSB0",O_RDWR);
  if(fd == -1)
    {
      perror("serialport error\n");
    }
  else{
    printf("open %s succesfully\n", ttyname(fd));
  }

  struct termios Opt;
  int status;

  tcgetattr(fd, &Opt);
  //set speed
  cfsetispeed(&Opt, B115200);
  cfsetospeed(&Opt, B115200);
  //set databits
  Opt.c_cflag &= ~CSIZE;
  Opt.c_cflag |= CS8;
  //set parity
  Opt.c_cflag &= ~PARENB;
  Opt.c_iflag &= ~INPCK;
  //set stopbits
  Opt.c_cflag &= ~CSTOPB;
  tcsetattr(fd, TCSANOW, &Opt);
  status = tcsetattr(fd, TCSANOW, &Opt);
  if(status != 0)
    {
      perror("tcsetattr fd1");
      return;
    }
}

u8 mainwindow::cal_crc (u8 *ptr, int len)
{
  u8 xbit;
  u8 data;
  u8 crc = 0xff;
  u8 bits ;
  while(len --)
    {
      xbit = 1 << 7;
      data = *(ptr ++);
      for (bits = 0; bits < 8; bits ++)
        {
          if(crc & 0x80)
            {
              crc <<= 1;
              crc ^= dwPolynomial;
            }
          else
            {
              crc <<= 1;
            }

          if (data & xbit)
            crc ^= dwPolynomial;
          xbit >>= 1;
        }
    }

  return crc;
}



void mainwindow::on_Slider0_valueChanged(int value)
{
    if(value!=servoValue[0])
    {

        servoValue[0]=value;
        ui.spinBox0->setValue(value);
        serialData.para[0]=0;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider1_valueChanged(int value)
{
    if(value!=servoValue[1])
    {

        servoValue[1]=value;
        ui.spinBox1->setValue(value);
        serialData.para[0]=1;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider2_valueChanged(int value)
{
    if(value!=servoValue[2])
    {

        servoValue[2]=value;
        ui.spinBox2->setValue(value);
        serialData.para[0]=2;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider3_valueChanged(int value)
{
    if(value!=servoValue[3])
    {
        servoValue[3]=value;
        ui.spinBox3->setValue(value);
        serialData.para[0]=3;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider4_valueChanged(int value)
{
    if(value!=servoValue[4])
    {
        servoValue[4]=value;
        ui.spinBox4->setValue(value);
        serialData.para[0]=4;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider5_valueChanged(int value)
{
    if(value!=servoValue[5])
    {
        servoValue[5]=value;
        ui.spinBox5->setValue(value);
        serialData.para[0]=5;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider6_valueChanged(int value)
{
    if(value!=servoValue[6])
    {
        servoValue[6]=value;
        ui.spinBox6->setValue(value);
        serialData.para[0]=6;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider7_valueChanged(int value)
{
    if(value!=servoValue[7])
    {
        servoValue[7]=value;
        ui.spinBox7->setValue(value);
        serialData.para[0]=7;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider8_valueChanged(int value)
{
    if(value!=servoValue[8])
    {
        servoValue[8]=value;
        ui.spinBox8->setValue(value);
        serialData.para[0]=8;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider9_valueChanged(int value)
{
    if(value!=servoValue[9])
    {
        servoValue[9]=value;
        ui.spinBox9->setValue(value);
        serialData.para[0]=9;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider10_valueChanged(int value)
{
    if(value!=servoValue[10])
    {
        servoValue[10]=value;
        ui.spinBox10->setValue(value);
        serialData.para[0]=10;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        for(int i=0;i<8;i++)
            printf("%x,",*((&serialData.head[0])+i));
        printf("\n");
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider11_valueChanged(int value)
{
    if(value!=servoValue[11])
    {
        servoValue[11]=value;
        ui.spinBox11->setValue(value);
        serialData.para[0]=11;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider12_valueChanged(int value)
{
    if(value!=servoValue[12])
    {
        servoValue[12]=value;
        ui.spinBox12->setValue(value);
        serialData.para[0]=12;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider13_valueChanged(int value)
{
    if(value!=servoValue[13])
    {
        servoValue[13]=value;
        ui.spinBox13->setValue(value);
        serialData.para[0]=13;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider14_valueChanged(int value)
{
    if(value!=servoValue[14])
    {
        servoValue[14]=value;
        ui.spinBox14->setValue(value);
        serialData.para[0]=14;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_Slider15_valueChanged(int value)
{
    if(value!=servoValue[15])
    {
        servoValue[15]=value;
        ui.spinBox15->setValue(value);
        serialData.para[0]=15;
        serialData.para[1]=(u8)value;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox0_valueChanged(int arg1)
{
    if(arg1!=servoValue[0])
    {
        servoValue[0]=arg1;
        ui.Slider0->setValue(arg1);
        serialData.para[0]=0;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox1_valueChanged(int arg1)
{
    if(arg1!=servoValue[1])
    {
        servoValue[1]=arg1;
        ui.Slider1->setValue(arg1);
        serialData.para[0]=1;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox2_valueChanged(int arg1)
{
    if(arg1!=servoValue[2])
    {
        servoValue[2]=arg1;
        ui.Slider2->setValue(arg1);
        serialData.para[0]=2;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox3_valueChanged(int arg1)
{
    if(arg1!=servoValue[3])
    {
        servoValue[3]=arg1;
        ui.Slider3->setValue(arg1);
        serialData.para[0]=3;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox4_valueChanged(int arg1)
{
    if(arg1!=servoValue[4])
    {
        servoValue[4]=arg1;
        ui.Slider4->setValue(arg1);
        serialData.para[0]=4;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox5_valueChanged(int arg1)
{
    if(arg1!=servoValue[5])
    {
        servoValue[5]=arg1;
        ui.Slider5->setValue(arg1);
        serialData.para[0]=5;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox6_valueChanged(int arg1)
{
    if(arg1!=servoValue[6])
    {
        servoValue[6]=arg1;
        ui.Slider6->setValue(arg1);
        serialData.para[0]=6;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox7_valueChanged(int arg1)
{
    if(arg1!=servoValue[7])
    {
        servoValue[7]=arg1;
        ui.Slider7->setValue(arg1);
        serialData.para[0]=7;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox8_valueChanged(int arg1)
{
    if(arg1!=servoValue[8])
    {
        servoValue[8]=arg1;
        ui.Slider8->setValue(arg1);
        serialData.para[0]=8;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox9_valueChanged(int arg1)
{
    if(arg1!=servoValue[9])
    {
        servoValue[9]=arg1;
        ui.Slider9->setValue(arg1);
        serialData.para[0]=9;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox10_valueChanged(int arg1)
{
    if(arg1!=servoValue[10])
    {
        servoValue[10]=arg1;
        ui.Slider10->setValue(arg1);
        serialData.para[0]=10;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox11_valueChanged(int arg1)
{
    if(arg1!=servoValue[11])
    {
        servoValue[11]=arg1;
        ui.Slider11->setValue(arg1);
        serialData.para[0]=11;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox12_valueChanged(int arg1)
{
    if(arg1!=servoValue[12])
    {
        servoValue[12]=arg1;
        ui.Slider12->setValue(arg1);
        serialData.para[0]=12;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox13_valueChanged(int arg1)
{
    if(arg1!=servoValue[13])
    {
        servoValue[13]=arg1;
        ui.Slider13->setValue(arg1);
        serialData.para[0]=13;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox14_valueChanged(int arg1)
{
    if(arg1!=servoValue[14])
    {
        servoValue[14]=arg1;
        ui.Slider14->setValue(arg1);
        serialData.para[0]=14;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}

void mainwindow::on_spinBox15_valueChanged(int arg1)
{
    if(arg1!=servoValue[15])
    {
        servoValue[15]=arg1;
        ui.Slider15->setValue(arg1);
        serialData.para[0]=15;
        serialData.para[1]=(u8)arg1;
        serialData.para[2] = cal_crc (&serialData.head[0], 7);
        write(fd,&serialData,serialData.lenth+6);
    }
}
