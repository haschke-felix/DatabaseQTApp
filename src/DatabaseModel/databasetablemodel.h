#ifndef DATABASETABLEMODEL_H
#define DATABASETABLEMODEL_H

#include <QAbstractTableModel>

class AbstractDatabaseTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    AbstractDatabaseTableModel();

    QModelIndex index(int x, int y);
    QVariant data(QModelIndex idx);

};

#endif // DATABASETABLEMODEL_H
