#include "textfinder.h"
#include "ui_textfinder.h"
#include "QAbstractTableModel"
#include <iostream>
using namespace std;
#include "qmysqlquerymodel.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QStandardItem>
#include <QDebug>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(QApplication::applicationDirPath() + "/" + "MyDataBase.db");
    if (!db.open())
    {
        return ;
    }

//    QSqlQueryModel *model = new QSqlQueryModel;
//    model->setQuery("SELECT * FROM robotloadattributes");	//从给定的数据库db执行sql操作, db需预先制定并打开
//    int column = model->columnCount();	//获取列数
//    int row = model->rowCount();		//获取行数

//    qDebug()<< model->record(1).value(2);//获得数据库中记录的第二条中从左到右的第三个数据值
//    qDebug()<< model->data(model->index(1,2));//同上，从数据库中记录的第二条中从左到右的第三个数据值

//    model->setHeaderData(0, Qt::Horizontal, tr("Id"));	//设置表头，如不设置则使用数据库中的默认表头
//    model->setData(model->index(1,2),45);
//    ui->tableView->resize(800,800);
//    ui->tableView->setModel(model);
//    ui->tableView->show();

     model = new QMySqlTableModel(this);
    //model = new QSqlTableModel(this);
    model->setTable("robotloadattributes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //ui->tableView->resize(800,800);
    ui->tableView->setModel(model);
    ui->tableView->show();

QMap<QString,QVariant> testMap;
testMap["wei"]= 1.56;
testMap["xiao"]= "wei";
qDebug()<<testMap;



typedef int SINT;
typedef unsigned int USINT;
SINT i=9;
USINT J=8;
qDebug()<<i << ";"<<J <<endl;

typedef char* Pstring;
Pstring str= (char*)("This is a string!");
qDebug()<<str;

typedef struct mypoint{
    float x;
    float y;
}Spoint;

Spoint P;
P.x=10.0f;
P.y=20.0f;
qDebug()<<P.x;

}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::on_pushButton_clicked()
{
    //model->database().transaction(); //开始事务操作
    model->submitAll();
}

void TextFinder::on_pushButton_2_clicked()
{
    model->revertAll(); // 撤销步骤
    model->submitAll(); // 提交步骤 -- 更新数据模型 model->select();
}

void TextFinder::on_pushButton_3_clicked()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum);
   // ui->tableView->verticalHeader()->reset();
    model->submitAll();
};

void TextFinder::removeHat(char cat)
 {
     if(cat <= 'Z')
     {
         cout << "cat:"<< cat<<endl;
         removeHat(cat + 1);
     }
     else
     {
         cout << "vom!!"<<endl;
     }
    int def=0;
    qDebug()<< def++;
 }
