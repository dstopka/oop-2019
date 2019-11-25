#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_map>

static void smallUnorderedMapEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

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
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

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
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

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
        std::unordered_map<Small, Small> unorderedMap;
        for(int i = 0; i < size; ++i)
            unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});
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
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});
    Small s;
    for(auto _ : state)
    {
        state.PauseTiming();
        unorderedMap.insert({s = Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
        state.ResumeTiming();
        unorderedMap.erase(s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});
    Small s;

    for(auto _ : state)
    {
        unorderedMap.insert({s = Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
        state.PauseTiming();
        unorderedMap.erase(s);
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

    std::unordered_map<Small, Small> unorderedMap2;
    for(int i = 0; i < size; ++i)
        unorderedMap2.insert({Small{(char)i}, Small{(char)(rand()%size)}});

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
    std::unordered_map<Small, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});
    }

    for(auto _ : state)
    {
        unorderedMap.at(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        unorderedMap[Small{(char)(rand()%size)}];
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        unorderedMap.count(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void smallUnorderedMapFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});


    for(auto _ : state)
    {
        unorderedMap.find(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});
    }

    for(auto _ : state)
    {
        unorderedMap.equal_range(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapEqualRange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallUnorderedMapRehash(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

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
    std::unordered_map<Small, Small> unorderedMap;
    for(int i = 0; i < size; ++i)
        unorderedMap.insert({Small{(char)i}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        unorderedMap.reserve(rand()%size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallUnorderedMapReserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();



