#include <boost/test/unit_test.hpp>

// STL includes
#include <iostream>

// nina includes
#include <nina/PdfCreator.h>
#include <nina/Invoice.h>



BOOST_AUTO_TEST_SUITE(nina)
BOOST_AUTO_TEST_SUITE(domain)

BOOST_AUTO_TEST_CASE( foo )
{
    Address senderAddress;
    senderAddress.setName("Florian Huber");
    senderAddress.setStreet("Sch\"utzenstrasse 11");
    senderAddress.setZipCode(9506);
    senderAddress.setPlace("Lommis");
    Sender sender( senderAddress );
    sender.setBank( Bank("UBS AG Zurich", "230-90734525.0", "UBSWCHZH80A", "CH5800230230907345250") );
    sender.setPhone("+41 52 376 13 54");
    sender.setMobilePhone("+41 77 442 84 86");

    Address receiverAddress;
    receiverAddress.setName("Joseph the Great");
    receiverAddress.setCompany("J System");
    receiverAddress.setStreet("J street 12");
    receiverAddress.setZipCode(14552);
    receiverAddress.setPlace("J Town");
    receiverAddress.setCountry("J country");
    Receiver receiver;
    receiver.setSalutation("Herr");
    receiver.setAddress( receiverAddress );


    Invoice invoice(sender, receiver);
    invoice.setTitle("Rechnung");
    invoice.setTextBeforePositions("some text for rechnung");
    invoice.setTextAfterPositions("some final words");

    invoice.add( Position("Monday:12.12.16") );
    invoice.add( Position("@Latten", "m", Money(17), 3) );
    invoice.add( Position("@Arbeit", "h", Money(50), 10) );
    invoice.add( Position("@Anfahrt", Money(100)) );
    invoice.add( Position("@Strom", Position::freeOfCharge) );


    PdfCreator pdfCreator;
    std::string errorMsg;
    auto fn = pdfCreator(invoice, errorMsg);
    std::cout << "FILENAME: " << fn << "\n";
}


BOOST_AUTO_TEST_SUITE_END() // domain
BOOST_AUTO_TEST_SUITE_END() // nina
