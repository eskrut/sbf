#include "sbfAdditions.h"


std::string sbf::makeFilledSuffix(int id, int width, char f) {
    std::stringstream sstr;
    sstr << std::setw(width) << std::setfill(f) << id;
    return sstr.str();
}

std::string sbf::makeNameWithStep(const std::string &base, std::size_t id, std::size_t width, char f)
{
    return base + makeFilledSuffix(id, width, f);
}
