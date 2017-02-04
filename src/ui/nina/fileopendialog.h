#ifndef FILEOPENDIALOG_H
#define FILEOPENDIALOG_H

// Nina includes
#include <filedialogbase.h>



class FileOpenDialog: public FileDialogBase
{
    Q_OBJECT

  public:
    FileOpenDialog();

  public:
    Q_INVOKABLE void open();
};

#endif  // FILEOPENDIALOG_H
