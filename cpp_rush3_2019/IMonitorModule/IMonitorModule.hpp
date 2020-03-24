/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>

enum ModuleType {
    SINGLE_GRAPH,
    DOUBLE_GRAPH,
    TRIPLE_GRAPH,
    PERCENTAGE,
};

class IMonitorModule {
	public:
		virtual ~IMonitorModule();

        virtual std::string getTitle() const = 0;
        virtual void setTitle(const std::string &title) = 0;
        virtual ModuleType getType() const = 0;
        virtual void setType(ModuleType type) = 0;

	protected:
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
