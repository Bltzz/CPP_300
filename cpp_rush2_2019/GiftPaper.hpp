/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** GiftPaper
*/

#if !defined(_GIFTPAPER_HPP_)
#define _GIFTPAPER_HPP_

#include "Box.hpp"

class GiftPaper : public Wrap {
	public:
        GiftPaper(std::string name = "Gift_Paper");
	protected:
        Object *_box;
	private:
};

#endif /* !GIFTPAPER_HPP_ */
