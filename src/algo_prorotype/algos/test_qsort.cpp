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

static bool		sort_optimizations(std::vector<int> &o_stack,
		std::vector<int> &secont_stack, size_t objective_size, size_t &counter,
		bool assending_order)
{
	// 2-swap
	if (objective_size == 2)
	{
		if ((assending_order && o_stack[o_stack.size() - 1]
				> o_stack[o_stack.size() - 2])
				|| (!assending_order && o_stack[o_stack.size() - 1]
				< o_stack[o_stack.size() - 2]))
			operations::swap(o_stack, counter);
		return true;
	}

	// already-sorted
	if (!assending_order) {
		if (std::is_sorted(o_stack.end() - objective_size, o_stack.end()))
			return true;
	}

	if (assending_order) {
		std::vector<int> temp(o_stack.end() - objective_size, o_stack.end());
		std::reverse(temp.begin(), temp.end());
		if (std::is_sorted(temp.begin(), temp.end()))
			return true;
	}

	// 3-swap
	if (objective_size == 3)
	{
		if (assending_order) {
			if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3]
					&& o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
			{
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1]
					&& o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3])
			{
				operations::swap(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 1]
					&& o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2])
			{
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3]
					&& o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
			{
				operations::swap(o_stack, counter);
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2]
					&& o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1])
			{
				operations::swap(o_stack, counter);
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				return true;
			}
		}

		if (!assending_order) {
			if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3]
					&& o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
			{
				operations::swap(o_stack, counter);
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1]
					&& o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3])
			{
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				operations::swap(o_stack, counter);
			}

			if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 1]
					&& o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2])
			{
				operations::swap(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3]
					&& o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
			{
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				return true;
			}

			if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2]
					&& o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3])
			{
				operations::swap(o_stack, counter);
				operations::rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				operations::rev_rotate(o_stack, counter);
				operations::swap(o_stack, counter);
				return true;
			}
		}
	}



//	if (objective_size == 3)
//	{
//
//	}

	return false;
}

static void		sort(std::vector<int> &object_stack,
		std::vector<int> &secont_stack, size_t objective_size, size_t &counter,
		bool assending_order) {
	static size_t	static_call_id { 0 };
	size_t 			call_id { ++static_call_id };

	if (objective_size == 1)
		return;

	if (sort_optimizations(object_stack, secont_stack, objective_size,
			counter, assending_order))
		return;

//	std::cout << "\033[1;36mState at call " << call_id << ":" << std::endl
//			  << "	object = " << object_stack << std::endl
//			  << "	second = " << secont_stack << std::endl
//			  << "	call size = " << objective_size << ", assending: "
//			  << assending_order << "\033[0;0m" << std::endl;

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

//	std::cout << "\033[1;32mState at call " << call_id << ":" << std::endl
//			<< "	object = " << object_stack << std::endl
//			<< "	second = " << secont_stack << std::endl
//			<< "	call size = " << objective_size << ", assending: "
//			<< assending_order << "\033[0;0m" << std::endl;
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