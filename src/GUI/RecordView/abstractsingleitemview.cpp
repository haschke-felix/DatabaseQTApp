#include "abstract_single_item_view.h"

AbstractSingleItemView::abstract_single_item_view()
{

}

void AbstractSingleItemView::setModel(QAbstractItemModel *model)
{
    disconnectModel();
    auto oldModel = this->model;
    this->model = model;
    connectModel();
    emit modelChanged(oldModel);
}

void AbstractSingleItemView::setIndex(const QModelIndex &index)
{
    this->index = index;
    emit indexChanged(index);
}

void AbstractSingleItemView::setReadonly()
{
    is_readonly = true;
}

void AbstractSingleItemView::disconnectModel()
{
    if(this->model)
    {
        // disconnect als signal of the model from this class and vice versa
        AbstractSingleItemView::disconnect(model, nullptr, this, nullptr);
        AbstractSingleItemView::disconnect(this, nullptr, model, nullptr);
    }
}

void AbstractSingleItemView::connectModel()
{
    if(!model)
        return;

    // Only pass the signal, if the index of interest is affected
    auto onDataChanged = [this](QModelIndex const &topLeft,QModelIndex const &bottomRight,QList<int> const & roles){
      if(!(this->index < topLeft) && (this->index < bottomRight || this->index == bottomRight))
      {
          emit modelDdataChanged(roles);
      }
    };

    QObject::connect(this->model, &QAbstractItemModel::dataChanged, this, onDataChanged);
}
