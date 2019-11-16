#include "Medium.h"
#include "BenchIncludes.h"

static void mediumLessOperator(State& state)
{
    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    medium2.randomize();
    //ensure pessimistic  complexity
    for(int& x : medium1.data)
        x--;
    for(auto _ : state)
    {
        auto result = medium1 < medium2;
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(mediumLessOperator)->Range(1,1)->Complexity();

static void mediumEqualOperator(State& state)
{
    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    //ensure pessimistic  complexity
    std::copy(std::begin(medium1.data), std::end(medium1.data), std::begin(medium2.data));
    for(auto _ : state)
    {
        auto result = medium1 == medium2;
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(mediumEqualOperator)->Range(1,1)->Complexity();

static void mediumHash(State& state)
{
    Medium medium{};
    medium.randomize();
    std::hash<Medium> hash;

    for(auto _ : state)
    {
        auto result = hash(medium);
        DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(mediumHash)->Range(1,1)->Complexity();
