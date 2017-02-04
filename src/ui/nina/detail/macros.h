#ifndef NINA_DETAIL_MACROS_H
#define NINA_DETAIL_MACROS_H

#define NINA_SETPROPERTY_VALUE(propertyName) \
    if( m_##propertyName == propertyName ) \
        return;                    \
    m_##propertyName = propertyName;         \
    emit propertyName##Changed();

#define NINA_SETPROPERTY(class, funcName, type, propertyName)     \
    void class :: funcName ( type propertyName ) { NINA_SETPROPERTY_VALUE(propertyName) }

#endif  // NINA_DETAIL_MACROS_H
