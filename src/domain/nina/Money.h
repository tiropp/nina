#ifndef NINA_DOMAIN_MONEY_H
#define NINA_DOMAIN_MONEY_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class Money
{
  public:
    Money();
    explicit Money(double money);
    Money(const Money& other);

  public:
    Money& operator=(const Money& other);
    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    Money& operator*=(double factor);
    Money& operator/=(double factor);
    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;

  public:
    /// \brief Round the value for the given precision
    Money round(double precision = 0.05, unsigned digits = 2) const;

    /// \brief Returns difference between value and rounded value
    ///
    /// Example: A value 8.72 is rounded to 8.70. In this case would the
    /// rounding mistake be r(8.72) - 8.72 = 8.70 - 8.72 = -0.02.
    Money roundMistake(double precision = 0.05, unsigned digits = 2) const;

  public:
    /// \brief Return value converted to string
    ///
    /// The string is rounded with the given \a precision and formatted to have
    /// the given number of \a digits behind the point.
    std::string toString(double precision = 0.05, unsigned digits = 2) const;

    /// \brief Convert money value to double
    double toDouble() const { return m_money; }



    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, money);
    }


    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    double m_money;
};

Money operator+(const Money& lhs, const Money& rhs);
Money operator-(const Money& lhs, const Money& rhs);
Money operator*(const Money& money, double factor);
Money operator/(const Money& money, double factor);

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_MONEY_H
