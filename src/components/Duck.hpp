/*
** EPITECH PROJECT, 2022
** DuckHunt
** File description:
** Duck
*/

#ifndef DUCK_HPP_
#define DUCK_HPP_

struct Duck {
    enum class Color { Black, Blue, Brown, Count };

    int id;
    Color color;

    Duck(int pId = 0, Color pColor = Color::Black) : id(pId), color(pColor)
    {
    }
};

#endif /* !DUCK_HPP_ */
