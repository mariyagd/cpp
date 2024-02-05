/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <vector>
# include <list>
# include <stack>
# include <algorithm>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"
# define BLUE   "\033[96m"
# define VIOLET	"\033[35m"

/* underlying container is the std::deque by default */
template < typename T >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack<T>(void) {}
        MutantStack<T>(MutantStack<T> const & src) : std::stack<T>(src) {}
        ~MutantStack<T>(void) {}

        MutantStack&  operator=(MutantStack const & other) { return (*this); }

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() { return (std::stack<T>::c.begin()); }
        iterator end() { return std::stack<T>::c.end(); }

        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }

        reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
        reverse_iterator rend() { return std::stack<T>::c.rend(); }

        const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
        const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }

        void push(const T& value) { this->c.push_back(value); }  // Overloaded push for a single element

        void push(const std::list<T>& list)  // Overloaded push for std::list
        {
            for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); ++it)
                this->c.push_back(*it);
        }

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MutantStack<T>& obj)
{
    out << BLUE "--Summary for the created stack--" RESET << std::endl;
    out << BLUE "Top: " << obj.top() << RESET << std::endl;
    out << BLUE "Size: " << obj.size() << RESET << std::endl;
    out << BLUE "The stack contains:" << std::endl;

    MutantStack<T> tempStack = obj; // Using a temporary stack to iterate over the elements without modifying the original stack

    while (!tempStack.empty())
    {
        out << BLUE << tempStack.top() << RESET << std::endl;
        tempStack.pop();
    }
    return (out);
}


#endif