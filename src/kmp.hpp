#pragma once
#include <vector>
#include <string>

struct KMP {
    std::string pat;
    std::vector<int> lps;

    explicit KMP(std::string p): pat(std::move(p)), lps(pat.size(), 0){
        build_lps();
    }
    void build_lps(){
        int len = 0;
        for (size_t i=1; i<pat.size(); ++i){
            while (len>0 && pat[i]!=pat[len]) len = lps[len-1];
            if (pat[i]==pat[len]) ++len;
            lps[i]=len;
        }
    }
    long long search_first(const std::string& text) const{
        int j=0;
        for (size_t i=0; i<text.size(); ++i){
            while (j>0 && text[i]!=pat[j]) j = lps[j-1];
            if (text[i]==pat[j]) ++j;
            if (j==(int)pat.size()) return (long long)(i - pat.size() + 1);
        }
        return -1;
    }
};
