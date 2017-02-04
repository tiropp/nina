#include "fileopendialog.h"

// Qt includes
#include <QFileDialog>



FileOpenDialog::FileOpenDialog()
{
}

void
FileOpenDialog::open()
{
    QString fileUrl = QFileDialog::getOpenFileName(NULL, title(), folder(), getNameFiltersString());
    if( fileUrl.isEmpty() )
        emit rejected();
    else {
        setFileUrl( fileUrl );
        emit accepted();
    }
}
