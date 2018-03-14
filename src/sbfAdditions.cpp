#include "sbfAdditions.h"


std::string sbf::makeFilledSuffix(int id, int width, char f) {
    std::stringstream sstr;
    sstr << std::setw(width) << std::setfill(f) << id;
    return sstr.str();
}
