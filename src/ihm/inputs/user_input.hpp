#pragma once
#define USER_INPUT

#include <iostream>

void wait_for_any_key_pressed();

template<typename T>
std::string get_input_instruction()
{
    std::string message_to_user = "Please enter ";

    if (std::is_same<char, T>::value) {
        return message_to_user + "a character :";
    }
    else if (std::is_same<std::string, T>::value) {
        return message_to_user + "a chain of characters :";
    }
    else if (std::is_same<int, T>::value) {
        return message_to_user + "an integer number :";
    }
    else if (std::is_same<float, T>::value) {
        return message_to_user + "a number :";
    }
    else {
        return message_to_user + "your response :";
    }
}

template<typename T>
T get_input_from_user()
{
    T input;
    while (std::cout << (get_input_instruction<T>() + "\n") && !(std::cin >> input)) {
        std::cin.clear();                                                   //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Error : Invalid input type.\n\n";
    }

    return input;
}