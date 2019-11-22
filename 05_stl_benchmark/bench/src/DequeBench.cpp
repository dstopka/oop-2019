#include "Small.h"
#include "BenchIncludes.h"
#include <deque>

static void smallDequeAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.at(0);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque[0];
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void smallDequeBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.back();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeShrinkToFit(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);

    for(auto _ : state)
    {
        deque.shrink_to_fit();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeShrinkToFit)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small s1;

    for(auto _ : state)
    {
        state.PauseTiming();
        std::deque<Small> deque(size);
        for(int i = 0; i < size; ++i)
        {
            s1.randomize();
            deque.push_back(s1);
        }
        state.ResumeTiming();

        deque.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        deque.insert(deque.begin(), s1);
        state.PauseTiming();
        deque.erase(deque.begin());
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        state.PauseTiming();
        deque.insert(deque.begin(), s1);
        state.ResumeTiming();
        deque.erase(deque.begin());
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequePushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        deque.push_back(s1);
        state.PauseTiming();
        deque.pop_back();
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequePushBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequePopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        state.PauseTiming();
        deque.push_back(s1);
        state.ResumeTiming();
        deque.pop_back();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequePopBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequePushFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        deque.push_front(s1);
        state.PauseTiming();
        deque.pop_front();
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequePushFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequePopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque(size);
    Small s1;
    s1.randomize();

    for(auto _ : state)
    {
        state.PauseTiming();
        deque.push_front(s1);
        state.ResumeTiming();
        deque.pop_front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequePopFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;


    for(auto _ : state)
    {
        state.PauseTiming();
        std::deque<Small> deque(size);
        state.ResumeTiming();
        deque.resize(size*2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeResize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void smallDequeSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::deque<Small> deque1(size);
    std::deque<Small> deque2(size);

    for(auto _ : state)
    {
        deque1.swap(deque2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(smallDequeSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

