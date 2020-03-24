/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** toto.cpp
*/

class toto{
    public:
        toto() = default;
        toto &operator=( const toto&) = delete;
        toto(const toto &) = delete;
        bool operator==(const toto&) const { return  true;}
        bool  operator>( const toto&) const { return  false; }
        bool operator<( const toto&) const { return  false; }
};