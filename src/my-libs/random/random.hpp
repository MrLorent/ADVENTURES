#pragma once
#define RANDOM_HPP

#include <time.h>
#include <random>
#include <vector>

template<typename T>
T rand(T min, T max)
{
    static std::mt19937_64                generator(std::random_device{}());
    std::uniform_real_distribution<float> distribution(min, max);

    return distribution(generator);
}

int   bernoulli(const float threshold);
int   throw_dice(const unsigned int number_of_faces);
int   geometric_law(const float p);
float box_muller(float expectation, float variance);
float generalized_erlang(const float lambda, const int k);