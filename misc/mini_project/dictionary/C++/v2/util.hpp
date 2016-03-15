#ifndef UTIL_HPP
#define UTIL_HPP
#include "dict.hpp"

namespace Util {
    // parse a string and return a linked list of
    // its words
    Text *parser(const string &);

    // translate a linked list
    Text *translator (Text *, int l, Entry *);

    // construct a string from a linked list
    string construct_string(Text *);
}

#include "util.cpp"
#endif
