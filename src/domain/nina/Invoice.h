#ifndef NINA_DOMAIN_INVOICE_H
#define NINA_DOMAIN_INVOICE_H

// BOOST includes
#include <boost/serialization/access.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/version.hpp>

// Nina includes
#include <nina/Settings.h>
#include <nina/Date.h>
#include <nina/Sender.h>
#include <nina/Receiver.h>
#include <nina/PositionContainer.h>
#include <nina/Vat.h>
#include <nina/Misc.h>
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {



class Invoice
{
    /******************/
    /*** CTOR, DTOR ***/
    /******************/
  public:
    Invoice() {}
    Invoice(const Sender& sender, const Receiver& receiver)
        : m_sender( sender )
        , m_receiver( receiver )
    {}


    /*****************/
    /*** MODIFIERS ***/
    /*****************/
  public:
    void setSettings(const Settings& settings) { m_settings = settings; }
    void setDate(const Date& date) { m_date = date; }
    void setSender(const Sender& sender) { m_sender = sender; }
    void setReceiver(const Receiver& receiver) { m_receiver = receiver; }
    void setVat(const Vat& vat) { m_vat = vat; }
    void add(const Position& pos) { m_positions.add(pos); }
    void setPositions(const PositionContainer& positions) { m_positions = positions; }
    void setMisc(const Misc& misc) { m_misc = misc; }


    /*****************/
    /*** ACCESSORS ***/
    /*****************/
  public:
    const Settings& getSettings() const { return m_settings; }
    const Date& getDate() const { return m_date; }
    const Sender& getSender() const { return m_sender; }
    const Receiver& getReceiver() const { return m_receiver; }
    const Vat& getVat() const { return m_vat; }
    const PositionContainer& getPositions() const { return m_positions; }
    const Misc& getMisc() const { return m_misc; }


    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void load(Archive& ar, const unsigned int version) {
        if( version == 0 )
            loadVersion0(ar);
        else
            loadVersion1(ar);
    }
    template<class Archive> void loadVersion0(Archive& ar) {
        std::string m_title;
        std::string m_textBeforePositions;
        std::string m_textAfterPositions;
        NINA_SERIALIZE(ar, title);
        NINA_SERIALIZE(ar, settings);
        NINA_SERIALIZE(ar, date);
        NINA_SERIALIZE(ar, sender);
        NINA_SERIALIZE(ar, receiver);
        NINA_SERIALIZE(ar, positions);
        NINA_SERIALIZE(ar, vat);
        NINA_SERIALIZE(ar, textBeforePositions);
        NINA_SERIALIZE(ar, textAfterPositions);

        m_misc.setTitle( m_title );
        m_misc.setTextBeforePositions( m_textBeforePositions );
        m_misc.setTextAfterPositions ( m_textAfterPositions );

    }
    template<class Archive> void loadVersion1(Archive& ar) {
        NINA_SERIALIZE(ar, settings);
        NINA_SERIALIZE(ar, date);
        NINA_SERIALIZE(ar, sender);
        NINA_SERIALIZE(ar, receiver);
        NINA_SERIALIZE(ar, positions);
        NINA_SERIALIZE(ar, vat);
        NINA_SERIALIZE(ar, misc);
    }
    template<class Archive> void save(Archive& ar, const unsigned int /*version*/) const {
        NINA_SERIALIZE(ar, settings);
        NINA_SERIALIZE(ar, date);
        NINA_SERIALIZE(ar, sender);
        NINA_SERIALIZE(ar, receiver);
        NINA_SERIALIZE(ar, positions);
        NINA_SERIALIZE(ar, vat);
        NINA_SERIALIZE(ar, misc);
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()


    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    Settings m_settings;
    Date m_date;
    Sender m_sender;
    Receiver m_receiver;
    PositionContainer m_positions;
    Vat m_vat;
    Misc m_misc;
};


} // End namespace domain
} // End namespace nina


// The current version used in the format
BOOST_CLASS_VERSION(nina::domain::Invoice, 1)



#endif  // NINA_DOMAIN_INVOICE_H
