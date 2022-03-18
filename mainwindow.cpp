#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <csvreader.h>
#include <csvwriter.h>
#include <QString>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchLes(){
    csvreader csv_r("D:/MIET/OOP/lab3/datebase.csv");

    if(csv_r.is_open()){

        lessons = csv_r.readall();
    }
    for(const auto &l: lessons){
        if(l.lesname==ui->input_search->text()){
            ui->output->append(l.lesname+", "+QString::number(l.lesaud)+", "+l.type_of_les+";");

        }
    }
}

void MainWindow::addLes(){
les l;

l.numb = ui->input_ID->text().toInt();
l.lesname = ui->input_subj->text();
l.lesaud = ui->input_aud->text().toInt();
l.type_of_les = ui->input_type->text();





//ui->output->append(l.lesname+", "+QString::number(l.lesaud)+", "+l.type_of_les+";");
csvwriter csv_w("D:/MIET/OOP/lab3/datebase.csv");
csv_w.write(l);
}

