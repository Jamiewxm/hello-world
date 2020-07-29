#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class TextFinder; }
QT_END_NAMESPACE

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    ~TextFinder();
    void removeHat(char cat);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TextFinder *ui;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role) ;
    QSqlTableModel *model;


};
#endif // TEXTFINDER_H
