#include "Small.h"
#include "BenchIncludes.h"
#include <map>

static void smallMultimapEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 0; i < size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 0; i < size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 0; i < size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state)
    {
        state.PauseTiming();
        std::multimap<Small, Small> multimap;
        for(int i = 0; i < size; ++i)
            multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
        state.ResumeTiming();

        multimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 0; i < size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
    Small s;
    for(auto _ : state)
    {
        state.PauseTiming();
        multimap.insert( {s = Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
        state.ResumeTiming();
        multimap.erase(s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 0; i < size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
    Small s;

    for(auto _ : state)
    {
        multimap.insert( {s = Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
        state.PauseTiming();
        multimap.erase(s);
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    Small s1;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
    }
    std::multimap<Small, Small> multimap2;
    for(int i = 0; i < size; ++i)
    {
        s1.randomize();
        multimap2.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});
    }

    for(auto _ : state)
    {
        multimap.swap(multimap2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 1; i <= size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.count(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 1; i <= size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.find(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 1; i <= size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.equal_range(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapEqualRange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapLowerBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 1; i <= size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.lower_bound(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapLowerBound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallMultimapUpperBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::multimap<Small, Small> multimap;
    for(int i = 1; i <= size; ++i)
        multimap.insert({Small{(char)(rand()%size)}, Small{(char)(rand()%size)}});

    for(auto _ : state)
    {
        multimap.upper_bound(Small{(char)(rand()%size)});
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallMultimapUpperBound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
