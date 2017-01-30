#ifndef NINA_DOMAIN_POSITION_H
#define NINA_DOMAIN_POSITION_H

// STL includes
#include <string>



namespace nina {
namespace domain {

class Position
{
  public:
    enum Flags {
        none,
        freeOfCharge
    };

  public:
    /// \brief Ctor
    Position(const std::string& description,
             const std::string& unit,
             float pricePerUnit,
             float numUnits
        );

    /// \brief Ctor with a flat price
    Position(const std::string& description,
             float price
        );

    /// \brief Ctor only with description
    Position(const std::string& description, Flags flags = none);



  public:
    const std::string& getDescription()     const { return m_description; }
    const std::string& getUnit()            const { return m_unit; }
    float              getPricePerUnit()    const { return m_pricePerUnit; }
    float              getNumUnits()        const { return m_numUnits; }
    float              getPrice()           const { return m_price; }
    bool               hasOnlyDescription() const { return m_hasOnlyDescription; }
    bool               isFreeOfCharge()     const { return m_isFreeOfCharge; }
    bool               isFlatPrice()        const { return m_isFlatPrice; }

  private:
    std::string m_description;
    std::string m_unit;
    float       m_pricePerUnit;
    float       m_numUnits;
    float       m_price;
    bool        m_hasOnlyDescription;
    bool        m_isFreeOfCharge;
    bool        m_isFlatPrice;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_POSITION_H
