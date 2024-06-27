#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(70);
    try {
        Span sp(30); // Initialize Span with a maximum of 5 elements
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
		sp.addNumberBulk< std::vector<int> >(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		sp.print();
    } catch (const Span::SetFullException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Span::SetTooSmallException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    return 0;
}
