#ifndef NINA_DOMAIN_POSITIONCONTAINER_H
#define NINA_DOMAIN_POSITIONCONTAINER_H

// STL includes
#include <vector>

// BOOST includes
#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>

// Nina includes
#include <nina/Position.h>
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {

class PositionContainer
{
    /*************/
    /*** TYPES ***/
    /*************/
  private:
    typedef std::vector<Position> position_container_type;
  public:
    typedef position_container_type::const_iterator  const_iterator;


    /*****************/
    /*** MODIFIERS ***/
    /*****************/
  public:
    void add(const Position& position) { m_positions.push_back(position); }


    /*****************/
    /*** ACCESSORS ***/
    /*****************/
  public:
    size_t getSize() const { return m_positions.size(); }
    const_iterator begin() const { return m_positions.begin(); }
    const_iterator end  () const { return m_positions.end  (); }
    size_t getPrice() const;


    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, positions);
    }


    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    position_container_type m_positions;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_POSITIONCONTAINER_H
