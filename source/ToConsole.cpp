/*
 * ToConsole.cpp
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */

#include "ToConsole.h"
#include "PrettyPrint.h"
#include <windows.h>
#include <iostream>
#include <array>

namespace printer {
		ToConsole::ToConsole(){
			std::cout << "Console out created." << std::endl;
		}

		ToConsole::~ToConsole() {
			std::cout << "Console out destroyed." << std::endl;
		}

		void ToConsole::print(const std::vector<std::vector<bool>> & board) const {
			clear();
			size_t rows = board.size();
			size_t columns = board[0].size();
			std::array<char, 2> theme = {' ', '@'};

			std::cout << std::endl;
			std::cout << "                      ";
			for (size_t i = 0; i <= columns; i++) std::cout << "__";
			std::cout << std::endl;

			for (size_t i = 0; i < rows; i++){
				std::cout << "                      | ";
				for (size_t j = 0; j < columns; j++){
					std::cout << theme[board[i][j]] << " ";
				}
				std::cout <<'|' <<  std::endl;
			}

			//for (size_t i = 0; i <= columns; i++) std::cout << static_cast<u_char>(175) << static_cast<u_char>(92) ;
			std::cout << "                      ";
			for (size_t i = 0; i <= columns; i++) std::cout << "‾‾";
			std::cout << std::endl;

			//make pause here;
		}

		void ToConsole::pos(short C, short R) const {
			COORD xy ;
			xy.X = C ;
			xy.Y = R ;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
		}
		void ToConsole::clear() const {
			pos(0,0);
			for(int j = 0; j < 8; j++) std::cout << std::string(100, ' ') << std::endl;
			pos(0,0);
		}
} /* namespace printer */
