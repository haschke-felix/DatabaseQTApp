#ifndef ABSTRACTINDEX_H
#define ABSTRACTINDEX_H

#include <QString>
#include <QModelIndex>

template<class IndexType>
class AbstractIndex
{
public:
    virtual QString toString() const = 0;
    virtual bool operator=(IndexType const & other) const = 0;

    /// Functions to store and laod the data
    virtual QByteArray pack() const = 0;
    virtual std::unique_ptr<IndexType> load(QByteArray const &) = 0;

protected:
    // Class is only allowed to be instanciated by derivatives
    AbstractIndex(QModelIndex const &idx) : mIndex(idx) {}
    QModelIndex getModelIndex() const {return mIndex; }
private:
    // TODO: Determine whether it's useful to store the model index here
    // -> Model Index may change while TableIndex reamains the same
    QModelIndex mIndex;
};


class AbstractRecordIndex : public AbstractIndex<AbstractRecordIndex>
{
protected:
    // Class is only allowed to be instanciated by derivatives
    AbstractRecordIndex(QModelIndex const &idx);
};

class AbstractTableIndex : public AbstractIndex<AbstractTableIndex>
{
protected:
    // Class is only allowed to be instanciated by derivatives
    AbstractTableIndex(QModelIndex const &idx);
};

#endif // ABSTRACTINDEX_H
