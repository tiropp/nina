#ifndef NINA_DOMAIN_ARCHIVER_H
#define NINA_DOMAIN_ARCHIVER_H

// STL includes
#include <string>

// Fwd declarations
namespace nina { namespace domain { class Invoice; }}



namespace nina {
namespace domain {


/// \brief Class saves and loads invoice to and from file
class Archiver
{
  public:
    static void save(const Invoice& invoice, const std::string& filename);
    static Invoice load(const std::string& filename);
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_ARCHIVER_H
