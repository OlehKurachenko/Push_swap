//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  as a part of Push_swap_prototype
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include "actionlib.h"

void	operations::push(std::vector<int> &from, std::vector<int> &to,
		size_t &counter)
{
	if (!from.empty())
		to.push_back(from.back());
	from.pop_back();
	++counter;
}

void	operations::rotate(std::vector<int> &stack, size_t &counter)
{
	const int 	first_element{ stack.back() };

	stack.pop_back();
	stack.insert(stack.begin(), first_element);
	++counter;
}

void	operations::rev_rotate(std::vector<int> &stack, size_t &counter)
{
	const int 	last_element{ stack.front() };

	stack.erase(stack.begin());
	stack.push_back(last_element);
	++counter;
}

void 	operations::swap(std::vector<int> &stack, size_t &counter)
{
	if (stack.size() >= 2)
	{
		std::swap(stack[stack.size() - 1], stack[stack.size() - 2]);
	}
	++counter;
}

std::ostream &operator<<(std::ostream &ostr, const std::vector<int> &vector)
{
	ostr << '[';
	if (!vector.empty())
	{
		for (size_t i { 0 }; i < vector.size() - 1; ++i)
			ostr << vector[i] << ' ';
		ostr << vector.back();
	}
	ostr << ']';
	return ostr;
}