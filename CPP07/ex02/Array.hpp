#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
	private:
		T *_arr;
		size_t _size;

	public:
		Array(): _arr(0) , _size(0) {};

		Array(unsigned int n): _arr(new T[n]()), _size(n) {};

		Array(const Array & cpy) : _arr(new T[cpy._size]()), _size(cpy._size) {
			for (size_t i = 0; i < _size; i++)
				_arr[i] = cpy._arr[i];
		};

		Array & operator=(const Array &src) {
			if (this != &src)
			{
				delete[] _arr;
				_size = src._size;
				_arr = new T[src._size];
				for (size_t i = 0; i < _size; i++)
					_arr[i] = src._arr[i];
			}
			return (*this);
		}
		T & operator[](size_t i) {
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _arr[i];
		}
		~Array() {
			delete[] _arr;
		}
		size_t size() { return _size; };
		void print()
		{
			for (size_t i = 0; i < _size; i++)
				std::cout <<"[" << i << "] = "<< _arr[i] << std::endl;
		};

};
#endif
