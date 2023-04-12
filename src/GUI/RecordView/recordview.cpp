#include "recordview.h"

RecordView::RecordView()
{

}

void RecordView::setModel(AbstractDatabaseTableModel *model)
{
    AbstractSingleItemView::setModel(model);
    tableModel = model;
}

void RecordView::setLayout()
{

}
