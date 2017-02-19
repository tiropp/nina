#include <boost/test/unit_test.hpp>

// nina includes
#include <nina/Archiver.h>
#include <nina/test/Fixture.h>



BOOST_AUTO_TEST_SUITE(nina)
BOOST_AUTO_TEST_SUITE(domain)
BOOST_AUTO_TEST_SUITE(Archiver_)


BOOST_FIXTURE_TEST_CASE(Save, test::Fixture)
{
    Archiver::save(invoice, "/tmp/invoice.nina");
}


BOOST_AUTO_TEST_SUITE_END() // Archiver_
BOOST_AUTO_TEST_SUITE_END() // domain
BOOST_AUTO_TEST_SUITE_END() // nina
