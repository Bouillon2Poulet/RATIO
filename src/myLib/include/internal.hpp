#ifndef __INTERNAL__HPP
#define __INTERNAL__HPP
/// \brief return the sign of val or zero if val is equal to zero
/// \param val : the value to get the sign from
/// \return the sign of value, zero if value is equal to zero
template<typename T>
int sign(T val)
{
    return (T{0} < val) - (val < T{0});
}

#endif