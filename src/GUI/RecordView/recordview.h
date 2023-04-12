#ifndef RECORDVIEW_H
#define RECORDVIEW_H

#include "databasetablemodel.h"
#include <QWidget>

class RecordView : public QWidget
{
    Q_OBJECT
public:
    RecordView();

    void setTableModel(AbstractDatabaseTableModel * model);
    void setIndex(QModelIndex const & index);

    void setReadonly();
    bool readonly() const;

signals:
    void dataChanged();

private:
    AbstractDatabaseTableModel * tableModel;
    QModelIndex displayIndex;
};

#endif // RECORDVIEW_H
