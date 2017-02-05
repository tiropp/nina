#ifndef NINA_DOMAIN_POSITION_H
#define NINA_DOMAIN_POSITION_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Position
{
    /*************/
    /*** TYPES ***/
    /*************/
  public:
    enum Flags {
        none,
        freeOfCharge
    };


    /******************/
    /*** CTOR, DTOR ***/
    /******************/
  private:
    /// \brief Default ctor used by serialization
    Position();

  public:
    /// \brief Ctor for a standard position having a number of units and a unit
    /// price
    Position(const std::string& description,
             const std::string& unit,
             double pricePerUnit,
             double numUnits
        );

    /// \brief Ctor with a flat price
    Position(const std::string& description,
             double price
        );

    /// \brief Ctor only with description
    Position(const std::string& description, Flags flags = none);


    /***************/
    /*** GETTERS ***/
    /***************/
  public:
    const std::string& getDescription()     const { return m_description; }
    const std::string& getUnit()            const { return m_unit; }
    double             getPricePerUnit()    const { return m_pricePerUnit; }
    double             getNumUnits()        const { return m_numUnits; }
    double             getPrice()           const { return m_price; }
    bool               hasOnlyDescription() const { return m_hasOnlyDescription; }
    bool               isFreeOfCharge()     const { return m_isFreeOfCharge; }
    bool               isFlatPrice()        const { return m_isFlatPrice; }


    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, description);
        NINA_SERIALIZE(ar, unit);
        NINA_SERIALIZE(ar, pricePerUnit);
        NINA_SERIALIZE(ar, numUnits);
        NINA_SERIALIZE(ar, price);
        NINA_SERIALIZE(ar, hasOnlyDescription);
        NINA_SERIALIZE(ar, isFreeOfCharge);
        NINA_SERIALIZE(ar, isFlatPrice);
    }


    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    std::string m_description;
    std::string m_unit;
    double      m_pricePerUnit;
    double      m_numUnits;
    double      m_price;
    bool        m_hasOnlyDescription;
    bool        m_isFreeOfCharge;
    bool        m_isFlatPrice;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_POSITION_H
