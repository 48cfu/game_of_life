/*
 * SpecializedBoard.h
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */

#ifndef SPECIALIZEDBOARD_H_
#define SPECIALIZEDBOARD_H_

#include "NormalBoard.h"
#include <string>

namespace board {

class SpecializedBoard: public NormalBoard {

	public:
		SpecializedBoard(const std::string & filename);

		virtual ~SpecializedBoard();

		virtual void load(const std::string & filename);
	};

} /* namespace board */

#endif /* SPECIALIZEDBOARD_H_ */
