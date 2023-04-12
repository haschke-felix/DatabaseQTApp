#ifndef RECORDVIEW_H
#define RECORDVIEW_H

#include <QWidget>
#include "abstract_single_item_view.h"
#include "abstractdatabasemodel.h"

// views a record

class RecordView : public AbstractSingleItemView
{
    Q_OBJECT
public:
    RecordView();

    // Hide the setModel function in order to receive a more specific model
    using AbstractSingleItemView::setModel;
    void setModel(AbstractDatabaseTableModel * model);

    void setLayout();
    void onIndexChanged();
private:
    AbstractDatabaseTableModel * tableModel;
};

#endif // RECORDVIEW_H
