#ifndef ABSTRACTSINGLEITEMVIEW_H
#define ABSTRACTSINGLEITEMVIEW_H

#include <QAbstractItemModel>
#include <QAbstractScrollArea>

class AbstractSingleItemView  : public QAbstractScrollArea
{
    Q_OBJECT

signals:
    // will be emitted if the corresponding data in the model has changed
    void modelDataChanged(QList<int> roles=QList<int>());

    // will be emitted if the index display by the view changed
    void indexChanged(QModelIndex idx);

    // will be emitted if the model has changed
    void modelChanged(QAbstractItemModel*old);

public:
    virtual void setModel(QAbstractItemModel * model);
    virtual QAbstractItemModel * getModel() {return model;}

    virtual void setIndex(QModelIndex const & index);
    QModelIndex getIndex() const {return index;}

    virtual void setReadonly();
    bool readonly() const {return is_readonly;}

protected:
    // Prevent the model from being created
    AbstractSingleItemView();
    AbstractSingleItemView(AbstractSingleItemView const &) = delete;

private:
    void disconnectModel();
    void connectModel();


    QAbstractItemModel * model;
    QModelIndex index;
    bool is_readonly = false;
};

#endif // ABSTRACTSINGLEITEMVIEW_H
