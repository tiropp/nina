#ifndef NINA_DOMAIN_EXCEPTIONS_H
#define NINA_DOMAIN_EXCEPTIONS_H

// Nina includes
#include <nina/Exception.h>



namespace nina {
namespace domain {

class SaveFailed: public Exception
{
  public:
    SaveFailed(const std::string& string)
        : Exception("Save failed: " + string)
    {}
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_EXCEPTIONS_H
