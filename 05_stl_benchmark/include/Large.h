#pragma once

#include <random>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{};

        for (double &i : data) {
            i = dis(gen);
        }
    }

    bool operator<(const Large &rhs) const {
        auto j = std::begin(rhs.data);
        for(auto i = std::begin(data); i < std::end(data); ++i)
        {
            if (*i > *j)
                return false;
            j++;
        }
        return true;
    }

    bool operator==(const Large &rhs) const {
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
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {
            long double res = 0;
            int idx = 1;
            for(auto i = std::begin(d.data); i < std::end(d.data); ++i)
            {
                res += *i * idx;
            }
            return res;
        }
    };
}
