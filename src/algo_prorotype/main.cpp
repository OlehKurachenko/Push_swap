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
	const size_t test1_size{ 10 };

	std::vector<int>	test1(test1_size);
	for (size_t i{ 0 }; i < test1_size; ++i)
		test1[i] = static_cast<int>(i);
	std::shuffle(test1.begin(), test1.end(), std::default_random_engine(
			static_cast<unsigned int>(std::chrono::system_clock::now()
					.time_since_epoch().count())));

	size_t test1_n = test_qsort(test1);
	std::cout << "\033[1;95mOperation for test 1: " << test1_n << "\033[0;0m" << std::endl;
}