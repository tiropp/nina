#ifndef NINA_DOMAIN_DEFAULTSETTINGS_H
#define NINA_DOMAIN_DEFAULTSETTINGS_H

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/Settings.h>
#include <nina/Sender.h>
#include <nina/Vat.h>
#include <nina/Misc.h>
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {


class DefaultSettings
{
    /******************/
    /*** CTOR, DTOR ***/
    /******************/
  public:
    DefaultSettings() {}
    DefaultSettings(
        const Settings& settings,
        const Sender& sender,
        const Vat& vat,
        const Misc& misc
        )
        : m_settings( settings )
        , m_sender  ( sender   )
        , m_vat     ( vat      )
        , m_misc    ( misc     )
    {}


    /***************/
    /*** GETTERS ***/
    /***************/
  public:
    const Settings& getSettings() const { return m_settings; }
    const Sender& getSender() const { return m_sender; }
    const Vat& getVat() const { return m_vat; }
    const Misc& getMisc() const { return m_misc; }


    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned int /*version*/) {
        NINA_SERIALIZE(ar, settings);
        NINA_SERIALIZE(ar, sender);
        NINA_SERIALIZE(ar, vat);
        NINA_SERIALIZE(ar, misc);
    }


    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    Settings m_settings;
    Sender m_sender;
    Vat m_vat;
    Misc m_misc;
};

} // End namespace domain
} // End namespace nina


#endif  // NINA_DOMAIN_DEFAULTSETTINGS_H
