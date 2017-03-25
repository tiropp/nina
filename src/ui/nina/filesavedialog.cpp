#include "filesavedialog.h"

// Qt includes
#include <QFileDialog>
#include <QDir>



FileSaveDialog::FileSaveDialog()
{
}

void
FileSaveDialog::open()
{
    QString fileUrl = QFileDialog::getSaveFileName(
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
