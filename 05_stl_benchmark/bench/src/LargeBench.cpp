#include "Large.h"
#include "BenchIncludes.h"

static void LargeLessOperator(State& state)
{
    Large large1{};
    Large large2{};
    large1.randomize();
    large2.randomize();
    //ensure pessimistic  complexity
    for(double& x : large1.data)
        x--;
    for(auto _ : state)
    {
        auto result = large1 < large2;
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(LargeLessOperator)->Range(1,1)->Complexity();

static void LargeEqualOperator(State& state)
{
    Large large1{};
    Large large2{};
    large1.randomize();
    //ensure pessimistic  complexity
    std::copy(std::begin(large1.data), std::end(large1.data), std::begin(large2.data));
    for(auto _ : state)
    {
        auto result = large1 == large2;
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(LargeEqualOperator)->Range(1,1)->Complexity();

static void LargeHash(State& state)
{
    Large large{};
    large.randomize();
    std::hash<Large> hash;

    for(auto _ : state)
    {
        auto result = hash(large);
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(LargeHash)->Range(1,1)->Complexity();

