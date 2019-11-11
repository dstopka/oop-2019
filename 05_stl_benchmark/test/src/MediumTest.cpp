#include "TestIncludes.h"
#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Medium.h"

TEST(MediumTest, SizeIsOneKiloByte) {

    EXPECT_EQ(1024u, sizeof(Medium));
}

TEST(MediumTest, CreateObject) {

    Medium medium{};
}

TEST(MediumTest, HasLessThenOperator) {

    Medium a{};
    Medium b{};
    a < b;
}

TEST(MediumTest, HasEqualityOperator) {

    Medium a{};
    Medium b{};
    a == b;
}

TEST(MediumTest, CanBeHashed) {

    Medium medium{};
    std::hash<Medium> hash;
    hash(medium);
}

TEST(MediumTest, Collections) {

    Medium medium{};

    std::vector<Medium> vector{};
    vector.push_back(medium);

    std::array<Medium, 1> array{};
    array[0] = medium;

    std::deque<Medium> deque{};
    deque.push_back(medium);

    std::list<Medium> list{};
    list.push_back(medium);

    std::forward_list<Medium> forward_list{};
    forward_list.push_front(medium);

    std::map<Medium, bool> map{};
    map[medium] = true;

    std::set<Medium> set{};
    set.insert(medium);

    std::unordered_map<Medium, bool> unordered_map{};
    unordered_map[medium] = true;

    std::unordered_set<Medium> unordered_set{};
    unordered_set.insert(medium);
}


TEST(MediumTest, Randomize) {

    Medium medium{};
    medium.randomize();

    auto count = 0u;

    for (int i : medium.data) {
        ASSERT_LE(0, i);
        ASSERT_GE(std::numeric_limits<int>::max(), i);

        if (i != 0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(MediumTest, Clear) {

    Medium medium{};
    medium.randomize();
    medium.clear();

    for (int i : medium.data) {
        ASSERT_EQ(0, i);
    }
}

TEST(MediumTest, OperatorSmaller) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    std::copy(std::begin(medium1.data), std::end(medium1.data), std::begin(medium2.data));
    ASSERT_EQ(false, medium1 < medium2);
    for(int& x : medium1.data)
        x--;
    ASSERT_EQ(true, medium1 < medium2);
    medium1.data[100] += 2;
    ASSERT_EQ(false, medium1 < medium2);
}

TEST(MediumTest, OperatorEqual) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    std::copy(std::begin(medium1.data), std::end(medium1.data), std::begin(medium2.data));
    ASSERT_EQ(true, medium1 == medium2);
    medium2.data[0]--;
    ASSERT_EQ(false, medium1 == medium2);
    medium2.data[0]++;
    medium1.data[255]++;
    ASSERT_EQ(false, medium1 == medium2);
}


TEST(MediumTest, Hash) {

    Medium medium1{};
    Medium medium2{};
    std::hash<Medium> hash;
    medium1.randomize();
    std::copy(std::begin(medium1.data), std::end(medium1.data), std::begin(medium2.data));
    ASSERT_EQ(true, hash(medium1) == hash(medium2));
    medium2.randomize();
    ASSERT_EQ(false, hash(medium1) == hash(medium2));
}
