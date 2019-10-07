/*
 * SpecializedBoard.cpp
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */

#include "SpecializedBoard.h"
#include <string>
#include <iostream>
#include <memory>
#include <exception>
#include <fstream>

namespace board {

	SpecializedBoard::SpecializedBoard(const std::string & filename) try: NormalBoard(8) {
		load(filename);
		std::cout << "Transformed into specialized board." << std::endl;
	} catch (const std::invalid_argument & e){
		//cout << e.what() << endl;
		std::cout << "Error in creating the Specialized board. Aborting..." << std::endl;
	} catch(...){
		throw; // forward exception
	}

	SpecializedBoard::~SpecializedBoard(){
		std::cout << "Specialized board destroyed." << std::endl;
	}

	void SpecializedBoard::load(const std::string & filename) {
		std::ifstream inFile;
		std::string path = "D:/Users/Precious/eclipse-workspace/GameOfLife/settings/" + filename + ".txt";
		inFile.open(path);
		if (!inFile) throw std::invalid_argument("File Not Foud: "  + path);
		int rows;
		int columns;
		inFile >> rows;
		inFile >> columns;
		printf("R: %d, C: %d \n", rows, columns);
		//NormalBoard(rows, columns);
		state.reset();
		NormalBoard::state = std::make_unique<std::vector<std::vector<bool>>>(rows, std::vector<bool>(columns, false));
		int i = 0;
		int j = 0;
		while (inFile >> i && inFile>> j) {
			state->at(i).at(j) = true;
		}
		inFile.close();
	}
} /* namespace board */
