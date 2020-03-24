/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Box
*/

#if !defined(_BOX_HPP_)
#define _BOX_HPP_
#include "Object.hpp"
#include "Wrap.hpp"

class Box : public Wrap {
	public:
		Box(std::string name = "Box");
        void set_in_paper(bool _bool) { _isInPaper = _bool;}
	protected:
		bool _isInPaper;
};

#endif /* !BOX_HPP_ */
