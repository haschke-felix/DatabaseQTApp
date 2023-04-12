#ifndef ABSTRACTDATABASEMODEL_H
#define ABSTRACTDATABASEMODEL_H

#include <vector>
#include <memory.h>
#include <QAbstractItemModel>


#include "abstract_index.h"

/// Model that models the entire database (collection of tables)
class AbstractDatabaseModel : public QAbstractItemModel
{
    Q_OBJECT

private:
    AbstractDatabaseModel();
public:
    /// pure virtual functions

    // TODO Decision: allow drag and drop for tables?
    // bool canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const final override;

    // TODO Later:
    // canFetchMore(const QModelIndex &parent) const override;



public:
    virtual int rowCount() const = 0;
    int rowCount(const QModelIndex &parent=QModelIndex()) const final override {columnCount();}

    int columnCount(const QModelIndex &parent=QModelIndex()) const final override {return 1;}

    // TODO: Implement
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override final;
        
    virtual std::unique_ptr<AbstractTableIndex> getTableIndex(QModelIndex const & idx) const = 0;

    virtual AbstractDatabaseTableModel * getTableModel(QModelIndex const &index) const = 0;

    // TODO: Implement
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    
    
    // TODO: Implement
    // QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override final {return index(row); }


private:
    /// Create a table-model with known DatabaseIndex
    virtual AbstractDatabaseTableModel * getTableModel(AbstractTableIndex const& tableId) = 0;

    /// pure virtual taken over from QAbstractItemModel
    // virtual bool insertRows(int row, int count) override;



};

#endif // ABSTRACTDATABASEMODEL_H
