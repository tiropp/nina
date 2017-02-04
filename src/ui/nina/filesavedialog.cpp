#include "filesavedialog.h"

// Qt includes
#include <QFileDialog>



FileSaveDialog::FileSaveDialog()
{
}

void
FileSaveDialog::open()
{
    QString fileUrl = QFileDialog::getSaveFileName(NULL, title(), folder(), getNameFiltersString());
    if( fileUrl.isEmpty() )
        emit rejected();
    else {
        setFileUrl( fileUrl );
        emit accepted();
    }
}
