/*
 * NormalBoard.cpp
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */


#include "Board.h"
#include "NormalBoard.h"

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#include <iostream>
#include <memory>
#include <exception>

namespace board{

		NormalBoard::NormalBoard(int dimension): NormalBoard(dimension, dimension){ 	}
		NormalBoard::NormalBoard(int rows, int columns) try {
			if (rows < 8 || columns < 8)
				throw std::invalid_argument("ROWS and COLUMNS should be of minimum size 8");
			Board::state = std::make_unique<std::vector<std::vector<bool>>>(rows, std::vector<bool>(columns, false));
			std::cout << "Normal board created." << std::endl;

			load();
		} catch(...){
			throw; // forward exception
		}

		NormalBoard::~NormalBoard(){
			std::cout << "Normal board destroyed." << std::endl;
		}

		void NormalBoard::load() {

			size_t rows = get_rows();
			size_t columns = get_columns();

			srand(time(0));
			for (size_t i = 0; i < rows; i++){
				for (size_t j = 0; j < columns; j++){
					Board::state->at(i).at(j) = rand() < RAND_MAX/3;
				}
			}

		}

		void NormalBoard::update() {
			//update rules for normal board
			//create new vector
			size_t rows = get_rows();
			size_t columns = get_columns();

			//

			auto real_board = *this->get_board(); //const std::vector<std::vector<bool>> & board

			std::vector<std::vector<bool>> *ptr_vec = new std::vector<std::vector<bool>>(std::move(real_board));
			//std::vector<std::vector<bool>> ptr_vec(std::move(real_board));

			//std::vector<std::vector<bool>> *ptr_vec = new std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, false));
			/*for (size_t i = 0; i < rows; i++){
				for (size_t j = 0; j < columns; j++){
					ptr_vec->at(i).at(j) = realboard
				}
			}*/
			for (size_t i = 0; i < rows; i++){
				//cout << "  ";
				for (size_t j = 0; j < columns; j++){
						int count = alive_neighbors(i, j);

						ptr_vec->at(i).at(j) = std::remove_reference_t<bool>(this->get_board()->at(i).at(j));
						//cout << count << " ";
						if (this->get_board()->at(i).at(j)) { // cell alive
							if (count < 2 || count > 3)
								ptr_vec->at(i).at(j) = false;
						} else{ //cell dead
							if (count == 3) ptr_vec->at(i).at(j) = true;
						}
					}
				//cout << endl;
			}
			Board::state.reset(ptr_vec);
		}

		const std::unique_ptr<std::vector<std::vector<bool>>>& NormalBoard::get_board() const{
			return Board::state;
		}

		int NormalBoard::alive_neighbors(const int & i, const int & j) const{
			int count = 0;
			auto real_board = *this->get_board(); //const std::vector<std::vector<bool>> & board
			size_t rows = get_rows();
			size_t columns = get_columns();

			count += (int)real_board[i - 1 >= 0 ? i - 1 : rows - 1][j - 1 >= 0 ? j - 1 : columns - 1]; 	//i - 1, j - 1
			count += (int)real_board[i - 1 >= 0 ? i - 1 : rows - 1][j];									//i - 1, j
			count += (int)real_board[i - 1 >= 0 ? i - 1 : rows - 1][j + 1 < columns ? j + 1 : 0]; 		//i - 1, j + 1

			//don't count myself
			count += (int)real_board[i][j - 1 >= 0 ? j - 1 : columns - 1]; 								//i, j - 1
			count += (int)real_board[i][j + 1 < columns ? j + 1 : 0]; 									//i, j + 1					//i, j + 1

			count += (int)real_board[i + 1 < rows ? i + 1 : 0][j - 1 >= 0 ? j - 1 : columns - 1]; 		//i + 1, j - 1
			count += (int)real_board[i + 1 < rows ? i + 1 : 0][j];										//i + 1, j
			count += (int)real_board[i + 1 < rows ? i + 1 : 0][j + 1 < columns ? j + 1 : 0]; 			//i + 1, j + 1
			return count;
		}
		void NormalBoard::check_board_state() const {
			if (!Board::state) throw std::invalid_argument("Undefined board state!");
		}
		size_t NormalBoard::get_rows() const{
			NormalBoard::check_board_state();
			return Board::state->size();
		}
		size_t NormalBoard::get_columns() const {
			NormalBoard::check_board_state();
			return Board::state->at(0).size();
		}

}
