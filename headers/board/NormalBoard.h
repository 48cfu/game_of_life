/*
 * NormalBoard.h
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */

#ifndef NORMALBOARD_H_
#define NORMALBOARD_H_
#include "Board.h"
#include <iostream>
#include <memory>

namespace board{

	class NormalBoard: public Board {

		public:
			NormalBoard(int dimension);
			NormalBoard(int rows, int columns) ;
			virtual ~NormalBoard();

			virtual void load() override;
			virtual void update() override;
			virtual const std::unique_ptr<std::vector<std::vector<bool>>>& get_board() const;

		protected:
			int alive_neighbors(const int & i, const int & j) const;
			void check_board_state() const;
			size_t get_rows() const;
			size_t get_columns() const;
	};

}


#endif /* NORMALBOARD_H_ */
