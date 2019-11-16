#include "Small.h"
#include "BenchIncludes.h"

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
    state.SetComplexityN(state.range(0));
}

BENCHMARK(smallLessOperator)->Range(1,1)->Complexity();

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
    state.SetComplexityN(state.range(0));
}

BENCHMARK(smallEqualOperator)->Range(1,1)->Complexity();

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
    state.SetComplexityN(state.range(0));
}

BENCHMARK(smallHash)->Range(1,1)->Complexity();
