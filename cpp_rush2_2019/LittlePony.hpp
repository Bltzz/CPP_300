/*
** EPITECH PROJECT, 2019
** rush2
** File description:
** LittlePony
*/

#if !defined(_LITTLEPONY_HPP_)
#define _LITTLEPONY_HPP_

#include "Toy.hpp"

class LittlePony : public Toy {
    public:
        LittlePony(std::string name);
        void isTaken() override;
    protected:
        bool _isInBox;
};

#endif /* !LITTLEPONY_HPP_ */
