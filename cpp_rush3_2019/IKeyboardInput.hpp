/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IKeyboardInput
*/

#ifndef IKEYBOARDINPUT_HPP_
#define IKEYBOARDINPUT_HPP_

enum keyboard {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    F12
};

class IKeyboardInput {
	public:
		virtual ~IKeyboardInput();

        virtual const keyboard getKey() const = 0;
        virtual void setKey(keyboard key) =0;

	protected:
	private:
};

#endif /* !IKEYBOARDINPUT_HPP_ */
