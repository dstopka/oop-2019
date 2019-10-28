#include "TestIncludes.h"

#include <unordered_set>

TEST(SetInt, RemoveElements) {

    std::set<int> set{2, 3, 1};
    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));

    set.erase(set.find(2));

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(0u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
}

TEST(SetDouble, ElementsSortedWhenIterating) {

    std::set<double> set{};

    ASSERT_TRUE(set.empty());
    std::initializer_list<double> list = {3.3, 2.2};
    set.insert(list);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));

    list = {4.4, 1.1};
    set.insert(list);

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));
    EXPECT_EQ(1u, set.count(4.4));
    EXPECT_EQ(1u, set.count(1.1));

    set.insert(0.0);

    auto iter = set.begin();
    EXPECT_EQ(0.0, *iter++);
    EXPECT_EQ(1.1, *iter++);
    EXPECT_EQ(2.2, *iter++);
    EXPECT_EQ(3.3, *iter++);
    EXPECT_EQ(4.4, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetString, ElementsSortedInReversedAplhabeticalOrderWhenIterating) {

    struct Comparator {
        bool operator()(const std::string& lhs, const std::string& rhs) const {
            return lhs > rhs;
        }
    };

    std::set<std::string, Comparator> set{"Bb", "Ba", "Ab", "Aa"};

    auto iter = set.begin();
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

    set.insert("Ca");

    iter = set.begin();
    EXPECT_EQ("Ca", *iter++);
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

}

TEST(SetInt, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const {
                return false;
        }
    };

    std::set<int, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(1);

    ASSERT_EQ(1u, set.size());

    set.insert(2);

    ASSERT_EQ(1u, set.size());
}

TEST(SetInt, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
            bool operator()(const int& lhs, const int& rhs) const {
                return true;
            }
    };

    std::set<int, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(1);

    ASSERT_EQ(1u, set.size());

    set.insert(1);

    ASSERT_EQ(2u, set.size());
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        int x;
        int y;
    };

    struct Comparator {
        bool operator()(const Value& lhs, const Value& rhs) const {
            if(lhs.x < rhs.x)
                return true;
            else return lhs.y < rhs.y;
        }
    };

    std::set<Value, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(Value{3, 0});

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));

    set.insert(Value{6, 0});

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));

    set.insert(Value{3, 3});

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));

    set.insert(Value{6, 6});

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));
    EXPECT_EQ(1u, set.count(Value{6, 6}));
}

TEST(SetInt, ElementsGreaterThanGivenValue) {

    std::set<int> set{1,2,3,4,5};

    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    auto iter = set.find(3);

    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    std::map<std::string, std::string> map{{"CN", "China"}, {"GR","Greece"}, {"FR", "France"}};

    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("China", map["CN"]);
    EXPECT_EQ("Greece", map["GR"]);
    EXPECT_EQ("France", map["FR"]);
}

TEST(MapMapStringInt, NestedCollections) {

    std::map<std::string, std::map<std::string, int>> map;
    std::map<std::string, int> innerMap;

    ASSERT_TRUE(map.empty());

    innerMap.insert(std::make_pair("1", 12));
    innerMap.insert(std::make_pair("2", 4));
    innerMap.insert(std::make_pair("3", 2));
    innerMap.insert(std::make_pair("4", 7));
    map.insert(std::make_pair("count", innerMap));

    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("count"));

    ASSERT_EQ(4u, map["count"].size());
    EXPECT_EQ(12, map["count"]["1"]);
    EXPECT_EQ(4, map["count"]["2"]);
    EXPECT_EQ(2, map["count"]["3"]);
    EXPECT_EQ(7, map["count"]["4"]);
}

TEST(MultisetInt, RemoveRangeOfElements) {

    std::multiset<int> multiset{};
    for(int i = 1; i <= 12; i++)
        multiset.insert(2);
    for(int i = 1; i <= 3; i++)
        multiset.insert(3);
    multiset.insert(1);

    ASSERT_EQ(16, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(12, multiset.count(2));
    EXPECT_EQ(3, multiset.count(3));

    multiset.erase(2);

    ASSERT_EQ(4, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(3, multiset.count(3));
}

TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
       int x;
       int y;
       int z;
    };

    struct Hash {
        std::size_t operator()(const Value& val) const noexcept {
            return 1;
        }
    };

    struct Equal {
        bool operator()(const Value& lhs, const Value& rhs) const{
            return (!(lhs.x < rhs.x) && !(rhs.x < lhs.x)) && (!(lhs.y < rhs.y) && !(rhs.y < lhs.y)) &&
                   (!(lhs.z < rhs.z) && !(rhs.z < lhs.z));
        }
    };

    std::unordered_set<Value, Hash, Equal> unordered_set;

    ASSERT_TRUE(unordered_set.empty());

    unordered_set.insert(Value{1,1,1});

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    unordered_set.insert(Value{1,1,1});

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++)
            for(int k = 1; k <= 2; k++)
                unordered_set.insert(Value{i, j, k});

    ASSERT_EQ(8u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 2}));
}

TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    std::unordered_set<int> unordered_set;

    unordered_set.insert(1);
    unordered_set.insert(1);

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(2);

    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(3);
    unordered_set.insert(1);
    unordered_set.insert(1);

    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(4);

    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(5);

    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    for(int i = 7; i < 12; i++)
        unordered_set.insert(i);
    for(int i = 1; i < 6; i++)
        unordered_set.insert(i);

    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(20);

    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
