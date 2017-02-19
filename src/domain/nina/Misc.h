#ifndef NINA_DOMAIN_MISC_H
#define NINA_DOMAIN_MISC_H

// STL includes
#include <string>

// BOOST includes
#include <boost/serialization/access.hpp>

// Nina includes
#include <nina/detail/SerializationHelper.h>



namespace nina {
namespace domain {


class Misc
{
    /*****************/
    /*** MODIFIERS ***/
    /*****************/
  public:
    void setTitle(const std::string& title) { m_title = title; }
    void setTextBeforePositions(const std::string& text) { m_textBeforePositions = text; }
    void setTextAfterPositions(const std::string& text) { m_textAfterPositions = text; }

    /*****************/
    /*** ACCESSORS ***/
    /*****************/
  public:
    const std::string& getTitle() const { return m_title; }
    const std::string getTextBeforePositions() const { return m_textBeforePositions; }
    const std::string getTextAfterPositions() const { return m_textAfterPositions; }

    /*********************/
    /*** SERIALIZATION ***/
    /*********************/
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, const unsigned /*version*/) {
        NINA_SERIALIZE(ar, title);
        NINA_SERIALIZE(ar, textBeforePositions);
        NINA_SERIALIZE(ar, textAfterPositions);
    }

    /***************/
    /*** MEMBERS ***/
    /***************/
  private:
    std::string m_title;
    std::string m_textBeforePositions;
    std::string m_textAfterPositions;
};


} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_MISC_H
