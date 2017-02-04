#ifndef NINA_DOMAIN_DETAIL_SERIALIZATION_HELPER_H
#define NINA_DOMAIN_DETAIL_SERIALIZATION_HELPER_H

// BOOST includes
#include <boost/serialization/nvp.hpp>



#define NINA_SERIALIZE(archive, variable) \
    archive & boost::serialization::make_nvp(#variable, m_##variable)

#endif  // NINA_DOMAIN_DETAIL_SERIALIZATION_HELPER_H
