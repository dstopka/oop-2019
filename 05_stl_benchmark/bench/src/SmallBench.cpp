#include "Small.h"
#include "BenchIncludes.h"
#include <deque>
#include <map>

static void smallLessOperator(State& state)
{
    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();

    for(auto _ : state)
    {
        auto result = small1 < small2;
        DoNotOptimize(result);
    }
}

BENCHMARK(smallLessOperator);

static void smallEqualOperator(State& state)
{
    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();

    for(auto _ : state)
    {
        auto result = small1 == small2;
        DoNotOptimize(result);
    }

}

BENCHMARK(smallEqualOperator);

static void smallHash(State& state)
{
    Small small1{};
    small1.randomize();
    std::hash<Small> hash;

    for(auto _ : state)
    {
        auto result = hash(small1);
        DoNotOptimize(result);
    }
}

BENCHMARK(smallHash);

