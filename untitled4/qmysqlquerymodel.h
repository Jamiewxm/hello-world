#ifndef QMYSQLTALBLEMODEL_H
#define QMYSQLTABLEMODEL_H
#include <QSqlTableModel>
#include <QWidget>
class QMySqlTableModel:public QSqlTableModel
{
public:
    explicit QMySqlTableModel(QWidget *parent = nullptr,QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // QMYSQLQUERYMODEL_H
