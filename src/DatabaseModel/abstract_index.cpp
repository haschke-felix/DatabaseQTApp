#include "abstract_index.h"


AbstractRecordIndex::AbstractRecordIndex(const QModelIndex &idx)
    : AbstractIndex(idx)
{

}

AbstractTableIndex::AbstractTableIndex(const QModelIndex &idx)
    : AbstractIndex(idx)
{

}
