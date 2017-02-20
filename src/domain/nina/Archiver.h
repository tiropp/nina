#ifndef NINA_DOMAIN_ARCHIVER_H
#define NINA_DOMAIN_ARCHIVER_H

// STL includes
#include <string>

// Fwd declarations
namespace nina { namespace domain {
    class Invoice;
    class DefaultSettings;
}}



namespace nina {
namespace domain {


/// \brief Class saves and loads invoice to and from file
class Archiver
{
  public:
    /// \brief Store \a invoice into file with name \a filename
    static void save(const Invoice& invoice, const std::string& filename);

    /// \brief Create invoice from file \a filename
    static Invoice load(const std::string& filename);

    /// \brief Store default settings contained in \a invoice to default
    /// location
    static void saveDefaultSettings(const DefaultSettings& settings);

    /// \brief Loads the default settings from default location
    static DefaultSettings loadDefaultSettings();
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_ARCHIVER_H
