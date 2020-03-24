/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Wrap
*/

#if !defined(_WRAP_HPP_)
#define _WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object {
    public:
        Wrap(std::string name = "Wrap");
        virtual bool wrapMeThat(Object &obj);
        Object *openMe();
        bool isGift();
        void isTaken() override;
        bool closeMe();
    protected:
        bool _isOpen = 1;
        Object *_gift;
    private:
};

#endif /* !WRAP_HPP_ */
