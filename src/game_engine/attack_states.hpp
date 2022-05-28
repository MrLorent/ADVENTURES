#pragma once
#define ATTACK_STATE_HPP

#include <array>

enum class Attack_states : int {
    Critic_failure = 1,
    Success        = 2,
    Critic_success = 3,
};

constexpr std::initializer_list<Attack_states> list_of_attacks_states = {
    Attack_states::Critic_failure,
    Attack_states::Success,
    Attack_states::Critic_success,
};