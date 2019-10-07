/*
 * Board.h
 *
 *  Created on: 5 Oct 2019
 *      Author: preci
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include <memory>


namespace board {

	class Board {
		protected:
			std::unique_ptr<std::vector<std::vector<bool>>> state;
		public:
			virtual void update() = 0;
			virtual void load() = 0;
			virtual const std::unique_ptr<std::vector<std::vector<bool>>>& get_board() const = 0;
			virtual ~Board () {}
	};

} /* namespace pretty */

#endif /* BOARD_H_ */
