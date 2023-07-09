#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette p;
    p.setColor(backgroundRole(),QColor(64,64,64));
    this->setPalette(p);


    setStyleSheet("background-color:rgb(64,64,64)");


    ui->setupUi(this);
    setStyleSheet("color:#fff");
    ui->label->setFrameStyle(QFrame::NoFrame);
     ui->label->setStyleSheet("color: #fff; font-family: 'DigitalFont'; font-size: 24px");
    DateTime = new QTimer();
    connect(DateTime,SIGNAL(timeout()),this,SLOT(Time_Display()));
    DateTime->setInterval(1000);
    DateTime->start();
    Time_Display();
}



MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Time_Display(){
    QString dateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    ui->label->setText(dateTime);
}
