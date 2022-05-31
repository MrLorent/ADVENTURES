#include "Character.hpp"

// CONSTRUCTORS
Character::Character()
{
}

Character::Character(Archer archer)
    : _class(archer)
{
}

Character::Character(Knight knight)
    : _class(knight)
{
}

Character::Character(Magician magician)
    : _class(magician)
{
}

// DESTRUCTORS
Character::~Character()
{
}

// GETTERS
std::string Character::get_name() const
{
    auto call_get_name = [](auto& character) { return character.get_name(); };
    return std::visit(call_get_name, _class);
}

std::string Character::get_name_and_title() const
{
    auto call_get_name_and_title = [](auto& character) { return character.get_name_and_title(); };
    return std::visit(call_get_name_and_title, _class);
}

int Character::get_health() const
{
    auto call_get_health = [](auto& character) { return character.get_health(); };
    return std::visit(call_get_health, _class);
}

int Character::get_experience() const
{
    auto call_get_experience = [](auto& character) { return character.get_experience(); };
    return std::visit(call_get_experience, _class);
}

int Character::get_nb_critic_successes() const
{
    auto call_get_nb_critic_successes = [](auto& character) { return character.get_nb_critic_successes(); };
    return std::visit(call_get_nb_critic_successes, _class);
}

int Character::get_nb_throws() const
{
    auto call_get_nb_throws = [](auto& character) { return character.get_nb_throws(); };
    return std::visit(call_get_nb_throws, _class);
}

// SETTERS
void Character::set_name(const std::string& new_name)
{
    std::variant<const std::string> param_name(new_name);

    auto call_set_name = [](auto& character, const std::string new_name) { character.set_name(new_name); };
    std::visit(call_set_name, _class, param_name);
}

void Character::set_health_points(const int new_health_points)
{
    std::variant<const int> param_health_points(new_health_points);

    auto call_set_health_points = [](auto& character, const int new_health_points) { character.set_health_points(new_health_points); };
    std::visit(call_set_health_points, _class, param_health_points);
}

void Character::add_nb_critic_successes(const unsigned int nb_critics)
{
    std::variant<const unsigned int> param_nb_critics(nb_critics);

    auto call_add_nb_critic_successes = [](auto& character, const unsigned int nb_critics) { character.add_nb_critic_successes(nb_critics); };
    std::visit(call_add_nb_critic_successes, _class, param_nb_critics);
}

void Character::add_nb_throws(const unsigned int nb_throws)
{
    std::variant<const unsigned int> param_nb_throws(nb_throws);

    auto call_add_nb_throws = [](auto& character, const unsigned int nb_throws) { character.add_nb_throws(nb_throws); };
    std::visit(call_add_nb_throws, _class, param_nb_throws);
}

// METHODS
void Character::introduce_themself() const
{
    auto call_introduce_themself = [](auto& character) { character.introduce_themself(); };
    std::visit(call_introduce_themself, _class);
}

int Character::attacks()
{
    auto call_attacks = [](auto& character) { return character.attacks(); };
    return std::visit(call_attacks, _class);
}

float Character::get_damages() const
{
    auto call_get_damages = [](auto& character) { return character.get_damages(); };
    return std::visit(call_get_damages, _class);
}

bool Character::dodges() const
{
    auto call_dodges = [](auto& character) { return character.dodges(); };
    return std::visit(call_dodges, _class);
}

void Character::add_experience(const int experience)
{
    std::variant<const int> param_experience(experience);

    auto call_add_experience = [](auto& character, const int experience) { character.add_experience(experience); };
    std::visit(call_add_experience, _class, param_experience);
}