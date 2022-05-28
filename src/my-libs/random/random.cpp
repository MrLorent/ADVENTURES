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

int random_choose(std::vector<int> universe, std::vector<float> probability)
{
    float random_value = rand<float>(0.0, 1.0);

    int   i  = 0;
    float p1 = probability[0];
    while (random_value > p1 && i < int(universe.size())) {
        i++;
        p1 += probability[i];
    }

    return universe[i];
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

float generalized_erlang(const float t, const std::vector<float>& lambdas)
{
    float result = 0.f;

    for (float lambda : lambdas) {
        result += lambda * std::exp(-t * lambda);
    }

    return result;
}