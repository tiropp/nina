#include "Archiver.h"

// STL includes
#include <fstream>

// BOOST includes
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/filesystem.hpp>

// Nina domain includes
#include <nina/Invoice.h>
#include <nina/DefaultSettings.h>
#include <nina/Exceptions.h>

// Namespace aliases
namespace bfs = boost::filesystem;



namespace nina {
namespace domain {



namespace {

template<class T>
void
save(const T& t, const std::string& objName, const std::string& filename)
{
    std::ofstream ofs( filename );
    boost::archive::xml_oarchive oa( ofs );
    oa << boost::serialization::make_nvp(objName.c_str(), t);
}

template<class T>
T
load(const std::string& objName, const std::string& filename)
{
    std::ifstream ifs( filename );
    boost::archive::xml_iarchive ia( ifs );
    T t;
    ia >> boost::serialization::make_nvp(objName.c_str(), t);
    return t;
}

bfs::path
getDefaultSettingsFilename()
{
  #if defined(WIN32)
    const char* baseDir = "APPDATA";
  #else
    const char* baseDir = "HOME";
  #endif
    bfs::path ninaDir = bfs::path( getenv(baseDir) ) / ".nina";
    bfs::create_directory( ninaDir );
    return ninaDir / "settings";
}

} // End unnamed namespace



void
Archiver::save(const Invoice& invoice, const std::string& filename)
{
    domain::save(invoice, "invoice", filename);
}

Invoice
Archiver::load(const std::string& filename)
{
    return domain::load<Invoice>("invoice", filename);
}

void
Archiver::saveDefaultSettings(const DefaultSettings& settings)
{
    domain::save(settings, "settings", getDefaultSettingsFilename().native());
}

DefaultSettings
Archiver::loadDefaultSettings()
{
    bfs::path filename = getDefaultSettingsFilename();
    if( !bfs::exists(filename) )
        return DefaultSettings();

    return domain::load<DefaultSettings>("settings", filename.native());
}

} // End namespace domain
} // End namespace nina
