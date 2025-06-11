//-------> ./includes/Span.hpp <-------//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class	Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		void	addNumber(int number);

		template<typename Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw StorageFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan() const;
		int		longestSpan() const;

		// Exceptions personnalisées
		class StorageFullException : public std::exception
		{
		public:
			const char* what() const throw()
			{
				return "Cannot add number: storage is full!";
			}
		};

		class NotEnoughNumbersException : public std::exception
		{
		public:
			const char* what() const throw()
			{
				return "Not enough numbers to compute span!";
			}
		};
};

#endif //	SPAN_HPP


