#pragma once
#include <string>
#include <algorithm>
#include <cctype>

namespace util {
inline std::string only_digits(std::string s){
    s.erase(std::remove_if(s.begin(), s.end(),
           [](unsigned char c){ return !std::isdigit(c); }), s.end());
    return s;
}

inline std::string trim(const std::string& s){
    size_t a = s.find_first_not_of(" \t\n\r");
    if (a==std::string::npos) return "";
    size_t b = s.find_last_not_of(" \t\n\r");
    return s.substr(a, b-a+1);
}

inline std::string nice_int(std::size_t n){
    std::string s = std::to_string(n);
    for (int i = (int)s.size()-3; i>0; i-=3) s.insert((size_t)i, 1, ' ');
    return s;
}
}
