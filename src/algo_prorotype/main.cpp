//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  as a part of Push_swap_prototype
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include "actionlib/actionlib.h"
#include "algos/algos.h"

#include <random>
#include <chrono>

int main() {
	const size_t test_stack_size{ 3 };

	const size_t number_of_tests{ 10000 };
	size_t worst_case{ 0 };
	size_t best_case{ 0 };
	size_t sum{ 0 };

	std::vector<int>	test1(test_stack_size);
	for (size_t i{ 0 }; i < test_stack_size; ++i)
		test1[i] = static_cast<int>(i);

	sum = worst_case = best_case = test_inplace_qsort(test1);

	for (size_t i{ 1 }; i < number_of_tests; ++i)
	{
		std::shuffle(test1.begin(), test1.end(), std::default_random_engine(
				static_cast<unsigned int>(std::chrono::system_clock::now()
						.time_since_epoch().count())));

		size_t test_result { test_inplace_qsort(test1) };
		worst_case = std::max(worst_case, test_result);
		best_case = std::min(best_case, test_result);
		sum += test_result;
	}

	std::cout << "\033[1;95m";
	std::cout << "Performance results on stack size " << test_stack_size
			  << " in " << number_of_tests << " runs:" << std::endl;
	std::cout << " worst   : " << worst_case << std::endl;
	std::cout << " best    : " << best_case << std::endl;
	std::cout.precision(10);
	std::cout << " average : " << (static_cast<double>(sum) / number_of_tests)
			                                           << std::endl;
	std::cout << "\033[0;0m";
}