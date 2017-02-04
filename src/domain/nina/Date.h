#ifndef NINA_DOMAIN_DATE_H
#define NINA_DOMAIN_DATE_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Date
{
  public:
    /// \brief Use today's date
    Date();

    /// \brief Ctor with specific date
    Date(size_t day, size_t month, size_t year);

  public:
    bool useToday() const { return m_useToday; }
    size_t getDay() const { return m_day; }
    size_t getMonth() const { return m_month; }
    size_t getYear() const { return m_year; }

  public:
    std::string toString() const;

  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, useToday);
        NINA_SERIALIZE(ar, day);
        NINA_SERIALIZE(ar, month);
        NINA_SERIALIZE(ar, year);
    }

  private:
    bool m_useToday;
    size_t m_day;
    size_t m_month;
    size_t m_year;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_DATE_H
