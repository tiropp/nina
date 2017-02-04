#include "Archiver.h"

// STL includes
#include <fstream>

// BOOST includes
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// Nina domain includes
#include <nina/Invoice.h>



namespace nina {
namespace domain {


void
Archiver::save(const Invoice& invoice, const std::string& filename)
{
    std::ofstream ofs( filename );
    boost::archive::xml_oarchive oa( ofs );
    oa << boost::serialization::make_nvp("invoice", invoice);
}

Invoice
Archiver::load(const std::string& filename)
{
    std::ifstream ifs( filename );
    boost::archive::xml_iarchive ia( ifs );
    Invoice invoice;
    ia >> boost::serialization::make_nvp("invoice", invoice);
    return invoice;
}


} // End namespace domain
} // End namespace nina
