#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix, pix2;
    //pix.load("file:///C:/Users/mrhli/Pictures/miui_back_desktop.jpg");
    //pix.load("C:/Users/mrhli/Pictures/miui_back_desktop.jpg");

    QString backImage = QDir::currentPath() + "/../vedit/stylesheet/miui_back_desktop.jpg";
    qDebug() << "image path:" << backImage;
    pix.load(backImage);

    pix2.load(QDir::currentPath() + "/../vedit/stylesheet/city_1.jpg");

    qDebug() << "current path:" << QDir::currentPath();
    ui->label->setPixmap(pix);
    ui->listWidget->setIconSize(QSize(100,80));
    qDebug() << " set image ok";

    for(auto i = 0; i < 40; i++){
        QListWidgetItem *item = new QListWidgetItem();
        //item->setIcon(QIcon(pix.scaled(QSize(200, 200))));
        if(i%2 == 0)
            item->setIcon(QIcon(pix));
        else
            item->setIcon(QIcon(pix2));
        ui->listWidget->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

