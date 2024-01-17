/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:02:49 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 13:08:56 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// initialization of static attribut
const size_t Brain::_size = 100;

Brain::Brain( void ) : _ideas(new std::string[_size]) {
	
	std::cout << "Brain Default constructor called" << std::endl;
	for (size_t i = 0; i < _size; i++)
		this->_ideas[i] = "";
	return;
}

Brain::~Brain( void ) {

	std::cout << "Brain Destructor called" << std::endl;
	delete [] this->_ideas;
	return;
}

Brain::Brain( const Brain& src ) : _ideas(0) {

	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain	&Brain::operator=( const Brain& rhs ) {
	
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		if (this->_ideas)
			delete [] this->_ideas;
		this->_ideas = new std::string[_size];
		for (size_t i = 0; i < _size; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

// for testing-------------------------------------------------
void	Brain::setIdeas( size_t index, std::string const idea ) {

	if (index < _size)
	{
		this->_ideas[index] = idea;
		std::cout << ITALIC <<"You added ideas[" << index << "] : " 
					<< BLUE << idea << END << std::endl;
	}
	else
		std::cout << ITALIC << "Invalid index" << END << std::endl;
	return;
}

std::string	Brain::getIdeas( size_t index ) const {

	if (index < _size)
		return this->_ideas[index];
	return "";
}

size_t	Brain::getIdeasSize( void ) const {

	return this->_ideas->size();
}

size_t	Brain::getSizeMax( void ) const {

	return _size;
}

std::ostream& operator<<( std::ostream& stream, Brain const& brain )
{
	size_t	count(0);

	for (size_t i = 0; i < brain.getSizeMax(); i++)
		if (brain.getIdeas(i) == "")
			count++;
	if (count == brain.getSizeMax())
	{
		stream << "All ideas are empty" << std::endl;
		return stream;
	}
	for (size_t i = 0; i < brain.getSizeMax(); i++)
		if (brain.getIdeas(i) != "")
			stream << "Idea [" << i << "] : " << brain.getIdeas(i) << std::endl;
	return stream;
}
