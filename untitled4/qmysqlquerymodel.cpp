#include "qmysqlquerymodel.h"
#include <QSqlDatabase>
QMySqlTableModel::QMySqlTableModel(QWidget *parent, QSqlDatabase db) : QSqlTableModel(parent,db)
{

}

QVariant QMySqlTableModel::data(const QModelIndex &item, int role) const

{
    QVariant value = QSqlQueryModel::data(item, role);
    if(role ==  Qt::TextAlignmentRole )
    {
        value   =   (Qt::AlignCenter);
        return value;
    }
    return value;
}
