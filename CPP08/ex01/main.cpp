#include "Span.hpp"
#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

// void addMillionRandomNumbers(std::vector<int>& vec) {
//     std::srand(std::time(0)); // Seed the random number generator
//     for (int i = 0; i < 1000000; ++i) {
//         vec.push_back(std::rand()); // Add a random number to the vector
//     }
// }
// int main() {
//     //add num whitout calling multiple addnum functions
// 	// std::vector<int> vec;
// 	// vec.push_back(0);
// 	// vec.push_back(30);
// 	// vec.push_back(40);
// 	// vec.push_back(70);
//     std::vector<int> vec;
//     addMillionRandomNumbers(vec);
//     // vec.push_back(0);
//     try {
//         Span sp(10000000); // Initialize Span with a maximum of 5 elements

//         // sp.addNumber(6);
//         // sp.addNumber(3);
//         // sp.addNumber(17);
//         // sp.addNumber(9);
//         // sp.addNumber(11);
// 		sp.addNumber(vec.begin(), vec.end());
//         std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
// 		// sp.print();
//     } catch (const Span::SetFullException& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     } catch (const Span::SetTooSmallException& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     } catch (...) {
//         std::cerr << "An unexpected error occurred." << std::endl;
//     }

//     return 0;
// }
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
