#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_map>

static void smallUnorderedMapEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void smallUnorderedMapClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state)
    {
        state.PauseTiming();
        std::unordered_map<int, Small> unorderedMap;
        Small s1;
        for(int i = 0; i < size; ++i)
        {
            s1.randomize();
            unorderedMap.insert({i, s1});
        }
        state.ResumeTiming();
        unorderedMap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i+1, s1});
    }

    for(auto _ : state)
    {
        state.PauseTiming();
        unorderedMap.insert({0, s1});
        state.ResumeTiming();
        unorderedMap.erase(0);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i + 1, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.insert({0, s1});
        state.PauseTiming();
        unorderedMap.erase(0);
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }
    std::unordered_map<int, Small> unorderedMap2;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap2.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.swap(unorderedMap2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.at(rand()%size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap[rand()%size];
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.count(rand());
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void smallUnorderedMapFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.find(rand());
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.equal_range(rand());
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapEqualRange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapRehash(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.rehash(rand()%size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapRehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapReserve(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({i, s1});
    }

    for(auto _ : state)
    {
        unorderedMap.reserve(rand()%size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapReserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();



