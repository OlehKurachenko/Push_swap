//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  as a part of Push_swap_prototype
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#ifndef PUSH_SWAP_PROTOTYPE_ACTIONLIB_H
#define PUSH_SWAP_PROTOTYPE_ACTIONLIB_H

#include <vector>
#include <iostream>

namespace operations {

	void	push(std::vector<int> &from, std::vector<int> &to, size_t &counter);

	void	rotate(std::vector<int> &stack, size_t &counter);

	void	rev_rotate(std::vector<int> &stack, size_t &counter);

	void 	swap(std::vector<int> &stack, size_t &counter);

}

std::ostream &operator<<(std::ostream &ostr, const std::vector<int> &vector);

#endif
