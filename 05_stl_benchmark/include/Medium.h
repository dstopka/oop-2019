#pragma once

#include <random>
#include <iostream>
struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {
        auto j = std::begin(rhs.data);
        for(auto i = std::begin(data); i < std::end(data); ++i)
        {
            if (*i >= *j)
                return false;
            j++;
        }
        return true;
    }

    bool operator==(const Medium &rhs) const {
        auto j = std::begin(rhs.data);
        for(auto i = std::begin(data); i < std::end(data); ++i)
        {
            if (*i != *j)
                return false;
            j++;
        }
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {
            long res = 0;
            int idx = 1;
            for(auto i = std::begin(d.data); i < std::end(d.data); ++i)
            {
                res += *i * idx;
            }
            return res;
        }
    };
}