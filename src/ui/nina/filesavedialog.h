#ifndef FILESAVEDIALOG_H
#define FILESAVEDIALOG_H

// Nina includes
#include <filedialogbase.h>



class FileSaveDialog: public FileDialogBase
{
    Q_OBJECT

  public:
    FileSaveDialog();

  public:
    Q_INVOKABLE void open();
};

#endif // FILESAVEDIALOG_H
