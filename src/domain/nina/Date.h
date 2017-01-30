#ifndef NINA_DOMAIN_DATE_H
#define NINA_DOMAIN_DATE_H

// STL includes
#include <string>



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

  public:
    std::string toString() const;

  private:
    bool m_useToday;
    size_t m_day;
    size_t m_month;
    size_t m_year;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_DATE_H
