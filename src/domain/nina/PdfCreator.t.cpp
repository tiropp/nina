#include <boost/test/unit_test.hpp>

// STL includes
#include <iostream>

// nina includes
#include <nina/PdfCreator.h>
#include <nina/test/Fixture.h>



BOOST_AUTO_TEST_SUITE(nina)
BOOST_AUTO_TEST_SUITE(domain)
BOOST_AUTO_TEST_SUITE(PdfCreator_)


BOOST_FIXTURE_TEST_CASE(CreatePdf, test::Fixture)
{
    PdfCreator pdfCreator;
    std::string errorMsg;
    auto fn = pdfCreator(invoice, errorMsg);
    std::cout << "FILENAME: " << fn << "\n";
}


BOOST_AUTO_TEST_SUITE_END() // PdfCreator_
BOOST_AUTO_TEST_SUITE_END() // domain
BOOST_AUTO_TEST_SUITE_END() // nina
