// 
//  Created by Oleh Kurachenko
//         aka okurache
//  on 2018-06-12T02:15:06Z as a part of push_swap_prototype
//  
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include "algos.h"

//static bool		sort_optimizations(std::vector<int> &o_stack,
//                                      std::vector<int> &secont_stack, size_t objective_size, size_t &counter,
//                                      bool assending_order)
//{
//    // 2-swap
//    if (objective_size == 2)
//    {
//        if ((assending_order && o_stack[o_stack.size() - 1]
//                                > o_stack[o_stack.size() - 2])
//            || (!assending_order && o_stack[o_stack.size() - 1]
//                                    < o_stack[o_stack.size() - 2]))
//            operations::swap(o_stack, counter);
//        return true;
//    }
//
//    // already-sorted
//    if (!assending_order) {
//        if (std::is_sorted(o_stack.end() - objective_size, o_stack.end()))
//            return true;
//    }
//
//    if (assending_order) {
//        std::vector<int> temp(o_stack.end() - objective_size, o_stack.end());
//        std::reverse(temp.begin(), temp.end());
//        if (std::is_sorted(temp.begin(), temp.end()))
//            return true;
//    }
//
//    // 3-swap
//    if (objective_size == 3)
//    {
//        if (assending_order) {
//            if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3]
//                && o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
//            {
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1]
//                && o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3])
//            {
//                operations::swap(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 1]
//                && o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2])
//            {
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3]
//                && o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
//            {
//                operations::swap(o_stack, counter);
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2]
//                && o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1])
//            {
//                operations::swap(o_stack, counter);
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                return true;
//            }
//        }
//
//        if (!assending_order) {
//            if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3]
//                && o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
//            {
//                operations::swap(o_stack, counter);
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 1]
//                && o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 3])
//            {
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//            }
//
//            if (o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 1]
//                && o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2])
//            {
//                operations::swap(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3]
//                && o_stack[o_stack.size() - 3] < o_stack[o_stack.size() - 2])
//            {
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                return true;
//            }
//
//            if (o_stack[o_stack.size() - 1] < o_stack[o_stack.size() - 2]
//                && o_stack[o_stack.size() - 2] < o_stack[o_stack.size() - 3])
//            {
//                operations::swap(o_stack, counter);
//                operations::rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                operations::rev_rotate(o_stack, counter);
//                operations::swap(o_stack, counter);
//                return true;
//            }
//        }
//    }



//	if (objective_size == 3)
//	{
//
//	}
//
//    return false;
//}

static void		sort(std::vector<int> &stack_a,
                        std::vector<int> &stack_b, size_t objective_size, size_t &counter,
                        bool is_a) {
    static size_t	static_call_id { 0 };
    size_t 			call_id { ++static_call_id };


//	std::cout << "\033[1;36mState at call " << call_id << ":" << std::endl
//			  << "	a = " << stack_a << std::endl
//			  << "	b = " << stack_b << std::endl
//			  << "	call size = " << objective_size << ", assending: "
//			  << is_a << "\033[0;0m" << std::endl;

    if (objective_size == 1) {
        if (!is_a)
            operations::push(stack_b, stack_a, counter);
        return;
    }

    if (objective_size == 2) {
        if (is_a) {
            if (stack_a[stack_a.size() - 1] > stack_a[stack_a.size() - 2])
                operations::swap(stack_a, counter);
            return;
        }
        if (stack_b[stack_b.size() - 1] < stack_b[stack_b.size() - 2])
            operations::swap(stack_b, counter);
        operations::push(stack_b, stack_a, counter);
        operations::push(stack_b, stack_a, counter);
        return;
    }

    if (!is_a) {
        if (std::is_sorted(stack_b.end() - objective_size, stack_b.end())) {
            for (size_t i{ 0 }; i < objective_size; ++i)
                operations::push(stack_b, stack_a, counter);
            return;
        }
    }

    if (is_a) {
        std::vector<int> temp(stack_a.end() - objective_size, stack_a.end());
        std::reverse(temp.begin(), temp.end());
        if (std::is_sorted(temp.begin(), temp.end()))
            return;
    }

    if (objective_size >= 7) {
        if (is_a) {
            if (std::is_sorted(stack_a.end() - objective_size, stack_a.end())) {
                for (size_t i{0}; i < objective_size; ++i)
                    operations::push(stack_a, stack_b, counter);
                for (size_t i{0}; i < objective_size; ++i)
                    operations::rotate(stack_b, counter);
                for (size_t i{0}; i < objective_size; ++i) {
                    operations::rev_rotate(stack_b, counter);
                    operations::push(stack_b, stack_a, counter);
                }
                return;
            }
        }

        if (!is_a) {
            std::vector<int> temp(stack_b.end() - objective_size, stack_b.end());
            std::reverse(temp.begin(), temp.end());
            if (std::is_sorted(temp.begin(), temp.end())) {
                for (size_t i{0}; i < objective_size; ++i)
                    operations::rotate(stack_b, counter);
                for (size_t i{0}; i < objective_size; ++i) {
                    operations::rev_rotate(stack_b, counter);
                    operations::push(stack_b, stack_a, counter);
                }
                return;
            }

        }
    }


    std::vector<int>    &object_stack = (is_a) ? stack_a : stack_b;

    std::vector<int>	objective(object_stack.end() - objective_size,
                                  object_stack.end());
    std::sort(objective.begin(), objective.end());
    int median{ objective[objective_size / 2] };

    size_t less_median{ objective_size / 2 };
    size_t more_eq_median{ objective_size - less_median };

    size_t moved_down_stack{ (is_a) ? more_eq_median : less_median };
    size_t moved_to_other_stack{ (is_a) ? less_median : more_eq_median };

    for (size_t i{ 0 }; i < objective_size; ++i)
        if (object_stack.back() < median) {
            if (is_a)
                operations::push(stack_a, stack_b, counter);
            else
                operations::rotate(object_stack, counter);
        } else {
            if (is_a)
                operations::rotate(object_stack, counter);
            else
                operations::push(stack_b, stack_a, counter);
        }

    if (object_stack.size() != moved_down_stack)
        for (size_t i{ 0 }; i < moved_down_stack; ++i)
            operations::rev_rotate(object_stack, counter);

    sort(stack_a, stack_b, more_eq_median, counter, true);
    sort(stack_a, stack_b, less_median, counter, false);

//    sort(secont_stack, object_stack,
//         moved_to_second_stack, counter, !assending_order);
//    for (size_t i{ 0 }; i < moved_to_second_stack; ++i)
//        operations::push(secont_stack, object_stack, counter);
//
//    for (size_t i{ 0 }; i < moved_to_down_of_object; ++i)
//        operations::rev_rotate(object_stack, counter);
//    sort(object_stack, secont_stack, moved_to_down_of_object,
//         counter, assending_order);

//	std::cout << "\033[1;32mState at call " << call_id << ":" << std::endl
//			<< "	object = " << object_stack << std::endl
//			<< "	second = " << secont_stack << std::endl
//			<< "	call size = " << objective_size << ", assending: "
//			<< assending_order << "\033[0;0m" << std::endl;
}

size_t			test_inplace_qsort(const std::vector<int> &stack)
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
