#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>
MateriaSource::MateriaSource()
{
	// std::cout <<"MateriaSource default constructor called" <<std::endl;
	for(int i = 0; i < 4; i++)
		_learntMaterias[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &cpy)
{
	// std::cout <<"MateriaSource copy constructor called" <<std::endl;
	for(int i = 0; i < 4; i++)
		_learntMaterias[i] = NULL;
	*this = cpy;
}
const MateriaSource & MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _learntMaterias[i];
			_learntMaterias[i] = NULL;
			learnMateria(src._learntMaterias[i]);
		}
	}
	return *this;
}
MateriaSource::~MateriaSource()
{
	// std::cout <<"MateriaSource destructor called" <<std::endl;
	for (int i = 0; i < 4; i++)
		delete _learntMaterias[i];
}


void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	if (m == NULL)
		return ;
	while (i < 4 && _learntMaterias[i] != NULL)
		i++;
	if (i < 4)
		_learntMaterias[i] = m;
}

AMateria*  MateriaSource::createMateria(std::string const & type)
{
	AMateria *materia_template = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (_learntMaterias[i] != NULL && _learntMaterias[i]->getType() == type)
		{
			materia_template = _learntMaterias[i];
			break ;
		}
	}
	if (materia_template != NULL)
		return (materia_template->clone());
	return (0);
}
