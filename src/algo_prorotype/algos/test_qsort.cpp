//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  as a part of Push_swap_prototype
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include "algos.h"

static void		sort(std::vector<int> &object_stack,
		std::vector<int> &secont_stack, size_t objective_size, size_t &counter,
		bool assending_order) {
	static size_t	static_call_id { 0 };
	size_t 			call_id { ++static_call_id };

	if (objective_size == 1)
		return;

	std::cout << "\033[1;36mState at call " << call_id << ":" << std::endl
			  << "	object = " << object_stack << std::endl
			  << "	second = " << secont_stack << std::endl
			  << "	call size = " << objective_size << ", assending: "
			  << assending_order << "\033[0;0m" << std::endl;

	std::vector<int>	objective(object_stack.end() - objective_size,
			object_stack.end());
	std::sort(objective.begin(), objective.end());
	if (!assending_order)
		std::reverse(objective.begin(), objective.end());
	int median{ objective[objective_size / 2] };

	size_t moved_to_down_of_object{ objective_size / 2 };
	size_t moved_to_second_stack{ objective_size - moved_to_down_of_object };

	for (size_t i{ 0 }; i < objective_size; ++i)
		if ((object_stack.back() < median && assending_order) ||
				(object_stack.back() > median && !assending_order))
			operations::rotate(object_stack, counter);
		else
			operations::push(object_stack, secont_stack, counter);

	sort(secont_stack, object_stack,
			moved_to_second_stack, counter, !assending_order);
	for (size_t i{ 0 }; i < moved_to_second_stack; ++i)
		operations::push(secont_stack, object_stack, counter);

	for (size_t i{ 0 }; i < moved_to_down_of_object; ++i)
		operations::rev_rotate(object_stack, counter);
	sort(object_stack, secont_stack, moved_to_down_of_object,
			counter, assending_order);

	std::cout << "\033[1;32mState at call " << call_id << ":" << std::endl
			<< "	object = " << object_stack << std::endl
			<< "	second = " << secont_stack << std::endl
			<< "	call size = " << objective_size << ", assending: "
			<< assending_order << "\033[0;0m" << std::endl;
}

size_t			test_qsort(std::vector<int> stack)
{
	size_t				operations_number{ 0 };
	std::vector<int>	stack_a(stack);
	std::vector<int>	stack_b;

	sort(stack_a, stack_b, stack_a.size(), operations_number, true);
	std::reverse(stack_a.begin(), stack_a.end());
	if (!std::is_sorted(stack_a.begin(), stack_a.end()))
	{
		std::cerr << "Not sorted!" << std::endl;
		std::cerr << "Before :" << stack << std::endl;
		std::cerr << "After  :" << stack_a << std::endl;
	}
	return operations_number;
}