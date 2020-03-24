/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex05.hpp
*/

#pragma once
#include <exception>
#include <iostream>
#include <iomanip>

template <typename T>
class array{
    public:
        array() : _array(nullptr), _size(0) {}
        array(unsigned int n) : _array(new T[n]), _size(n) {
            for(unsigned int j = 0; j < _size; j++)
                _array[j] = 0;
        }
        array(array &arr){
            _size = arr._size;
            _array = new T[arr._size];
            for(unsigned int j = 0; j < _size; j++)
                _array[j] = 0;
            for (unsigned int i = 0; i < arr._size; i++){
                this->_array[i] = arr._array[i];
            }
        }

        array &operator=(array const &arr){
                if (_array){
                    delete[] _array;
                }
                _array = new T[arr._size];
                _size = arr._size;
                for (unsigned int i = 0; i < arr._size; i++){
                    _array[i] = arr._array[i];
                }
            return *this;
        }

        T &operator[](unsigned int const pos){
            T *tmp;
            if (pos >= _size){
                tmp = new T[pos + 1];
                for (unsigned int i = 0; i < _size; i++)
                    tmp[i] = this->_array[i];

                delete[] this->_array;
                _array = tmp;
                this->_size = pos + 1;
            }
            return _array[pos];
        }

        T &operator[](unsigned int const pos) const{
            if (pos >= size)
                throw std::exception();
            return _array[pos];
        }

        unsigned int size() const {return this->_size;}

        void dump() const{

            std::cout << "[";
            for (unsigned int i = 0; i < _size; i++){
                if (_array && _array[i]){
                    std::cout << std::fixed;
                    std::cout << std::setprecision(1);
                    std::cout << _array[i] ;
                } else std::cout << 0;
            if (i + 1 < _size)
                std::cout <<  ", ";
            }
            std::cout << "]" <<std::endl;
        }

        template <typename U>
        array<U> const &convertTo(U (*conv)(T const &tmp)){
            array<U> *new_arr = new array<U>(this->_size);
            for (unsigned int i = 0; i < this->_size; i++)
                (*new_arr)[i] = conv(_array[i]);
             return *new_arr;
        }

        ~array(){
            if (_array)
                delete[] _array;
        }

    private:
        T *_array;
        unsigned int _size;
};



template<> void array<bool>::dump() const {
    std::cout << "[";
        for (unsigned int i = 0; i < this->_size; i++){
            if (_array[i] == true)
                std::cout << "true";
            else std::cout << "false";
            if (i + 1 < _size)
                std::cout <<  ", ";
        }
        std::cout << "]" <<std::endl;
}

