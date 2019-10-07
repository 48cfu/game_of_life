/*
 * PrettyPrint.h
 *
 *  Created on: 5 Oct 2019
 *      Author: Precious
 */

#ifndef PRETTYPRINT_H_
#define PRETTYPRINT_H_
#include <vector>
#include <iostream>

namespace printer {

	class PrettyPrint {
	public:
		//function for printing to board
		virtual void print(const std::vector<std::vector<bool>> &) const = 0;
		virtual ~PrettyPrint () {};
	};


} /* namespace pretty */

#endif /* PRETTYPRINT_H_ */
