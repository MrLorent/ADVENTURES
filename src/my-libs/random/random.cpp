#include "random.hpp"

int bernoulli(const float threshold)
{
    float random_value = rand<float>(0.0, 1.0);

    if (random_value < threshold) {
        return 0;
    }
    else {
        return 1;
    }
}

int throw_dice(const unsigned int number_of_faces)
{
    float random_value = rand<float>(0.0, 1.0);

    int i = 1;
    while (random_value > (i / float(number_of_faces)) && i <= static_cast<int>(number_of_faces)) {
        i++;
    }

    return i;
}

int geometric_law(const float p)
{
    const float q      = 1 - p;
    int         nb_try = 0;

    while (bernoulli(q) == 0 && p != 0) {
        nb_try++;
    }

    nb_try++;

    return nb_try;
}

float box_muller(float expectation, float variance)
{
    const float U1 = rand<float>(0.f, 1.f);
    const float U2 = rand<float>(0.f, 1.f);

    const float R     = std::sqrt(-2 * std::log(U1));
    const float THETA = 2 * U2 * M_PI;

    const float X = R * std::cos(THETA);

    return expectation + variance * X;
}

float generalized_erlang(const float lambda, const int k)
{
    float result = 0.f;

    for (int i = 0; i < k; ++i) {
        result += std::log(rand<float>(0, 1));
    }

    return -(1 / lambda) * result;
}