#include "fileopendialog.h"

// Qt includes
#include <QFileDialog>
#include <QDir>



FileOpenDialog::FileOpenDialog()
{
}

void
FileOpenDialog::open()
{
    QString fileUrl = QFileDialog::getOpenFileName(
        NULL,
        title(),
        QDir::home().path(),
        getNameFiltersString()
        );
    if( fileUrl.isEmpty() )
        emit rejected();
    else {
        setFileUrl( fileUrl );
        emit accepted();
    }
}
