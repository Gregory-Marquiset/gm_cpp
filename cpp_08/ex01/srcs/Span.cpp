//-------> ./srcs/Span.cpp <-------//

#include "../includes/Span.hpp"
#include <limits>
#include <cstdlib>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_data.size() >= _maxSize)
        throw Span::StorageFullException();
    _data.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_data.size() + std::distance(begin, end) > _maxSize)
        throw Span::StorageFullException();
    _data.insert(_data.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw Span::NotEnoughElementsException();

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw Span::NotEnoughElementsException();

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}

// Exceptions

const char* Span::StorageFullException::what() const throw()
{
    return "Cannot add more elements: storage is full.";
}

const char* Span::NotEnoughElementsException::what() const throw()
{
    return "Not enough elements to calculate a span.";
}
