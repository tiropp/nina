#ifndef NINA_DOMAIN_TEST_FIXTURE_H
#define NINA_DOMAIN_TEST_FIXTURE_H

// nina includes
#include <nina/Invoice.h>



namespace nina {
namespace domain {
namespace test {

struct Fixture
{
    Invoice invoice;

    Fixture() {
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

        Misc misc;
        misc.setTitle("Rechnung");
        misc.setTextBeforePositions("some text for rechnung");
        misc.setTextAfterPositions("some final words");

        invoice.setSender( sender );
        invoice.setReceiver( receiver );
        invoice.setMisc( misc );
        invoice.add( Position("Monday:12.12.16") );
        invoice.add( Position("@Latten", "m", Money(17), 3) );
        invoice.add( Position("@Arbeit", "h", Money(50), 10) );
        invoice.add( Position("@Anfahrt", Money(100)) );
        invoice.add( Position("@Strom", Position::freeOfCharge) );
    }
};


} // End namespace test
} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_TEST_FIXTURE_H
