#include "Archiver.h"

// STL includes
#include <fstream>
#include <codecvt>

// System includes
#if defined(_WIN32)
# include <shlobj.h>
#endif

// BOOST includes
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/filesystem.hpp>
#if defined(_WIN32)
# include <boost/locale.hpp>
#endif

// Nina domain includes
#include <nina/Invoice.h>
#include <nina/DefaultSettings.h>
#include <nina/Exceptions.h>

// Namespace aliases
namespace bfs = boost::filesystem;
namespace blc = boost::locale;


namespace {

bfs::path
convertToPath(const std::string& path)
{
#if defined(_WIN32)
    std::wstring pathUtf16 = blc::conv::to_utf<wchar_t>(path, "UTF-8");
    return bfs::path( pathUtf16 );
#else
    return bfs::path( path );
#endif
}

} // End unnamed namespace


namespace nina {
namespace domain {



namespace {

template<class T>
void
save(const T& t, const std::string& objName, const std::string& filename)
{
    bfs::ofstream ofs( convertToPath(filename) );
    boost::archive::xml_oarchive oa( ofs );
    oa << boost::serialization::make_nvp(objName.c_str(), t);
}

template<class T>
T
load(const std::string& objName, const std::string& filename)
{
    bfs::ifstream ifs( convertToPath(filename) );
    boost::archive::xml_iarchive ia( ifs );
    T t;
    ia >> boost::serialization::make_nvp(objName.c_str(), t);
    return t;
}

bfs::path
getDefaultSettingsFilename()
{
  #if defined(_WIN32)
    char homeDir[MAX_PATH];
    if( FAILED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, homeDir)) )
        throw NoHomeDir();
  #else
    const char* homeEnv = "HOME";
    char* homeDir = getenv( homeEnv );
  #endif
    bfs::path ninaDir = bfs::path( homeDir ) / ".nina";
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
    domain::save(settings, "settings", getDefaultSettingsFilename().string());
}

DefaultSettings
Archiver::loadDefaultSettings()
{
    bfs::path filename = getDefaultSettingsFilename();
    if( !bfs::exists(filename) )
        return DefaultSettings();

    return domain::load<DefaultSettings>("settings", filename.string());
}

} // End namespace domain
} // End namespace nina
