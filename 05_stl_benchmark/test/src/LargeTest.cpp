#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}


TEST(LargeTest, OperatorSmaller) {

    Large large1{};
    Large large2{};
    large1.randomize();
    std::copy(std::begin(large1.data), std::end(large1.data), std::begin(large2.data));
    ASSERT_EQ(false, large1 < large2);
    for(double& x : large1.data)
        x--;
    ASSERT_EQ(true, large1 < large2);
    large1.data[100] += 2;
    ASSERT_EQ(false, large1 < large2);
}

TEST(LargeTest, OperatorEqual) {

    Large large1{};
    Large large2{};
    large1.randomize();
    std::copy(std::begin(large1.data), std::end(large1.data), std::begin(large2.data));
    ASSERT_EQ(true, large1 == large2);
    large2.data[0]--;
    ASSERT_EQ(false, large1 == large2);
    large2.data[0]++;
    large1.data[255]++;
    ASSERT_EQ(false, large1 == large2);
}


TEST(LargeTest, Hash) {

    Large large1{};
    Large large2{};
    std::hash<Large> hash;
    large1.randomize();
    std::copy(std::begin(large1.data), std::end(large1.data), std::begin(large2.data));
    ASSERT_EQ(true, hash(large1) == hash(large2));
    large2.randomize();
    ASSERT_EQ(false, hash(large1) == hash(large2));
}
