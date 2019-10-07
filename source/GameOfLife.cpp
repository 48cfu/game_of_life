#include <iostream>
#include <memory>
#include <cassert>


#include "Board.h"
#include "NormalBoard.h"

#include "SpecializedBoard.h"
#include "PrettyPrint.h"
#include "ToConsole.h"

using namespace std;
using namespace board;
using namespace printer;

//template<size_t T, typename std::enable_if<std::is_integral<T>::value>::type * = nullptr>

class GameFactory {
private:
	std::unique_ptr<Board> board;
	std::unique_ptr<PrettyPrint> printer;

public:
	GameFactory() try {
		cout << "Choose GAME type: " << endl
			<<	"	1: Normal random" << endl
			<<	"	2: Blinker" << endl
			<<	"	3: Glider" << endl
			<<	"	4: Combination" << endl
			<<	"	5: Gosper Glider Gun" << endl
			<<	"	6: Beacon" << endl
			<<	"	7: R-Pentomio" << endl;

		int choice = 0;
		cout << "Choice: ";
		cin >> choice;
		int rows = 0;
		int columns = 0;
		if (choice == 1) {
			cout << endl << "Input rows and columns \n N M: ";


			cin >> rows;
			cin >> columns;

			cout << endl;

		}
		cout << "\n Choose OUTPUT type: " << endl
			<<	"	1: To Console" << endl
			<<	"	2: To Window" << endl;

		int key = 0;
		cout << "Choice: ";
		cin >> key;
		cout << endl;

		switch (choice){
			case 7: board = std::make_unique<SpecializedBoard>(std::string("r-pentomio")); break;
			case 6: board = std::make_unique<SpecializedBoard>(std::string("beacon")); break;
			case 5: board = std::make_unique<SpecializedBoard>(std::string("GGG")); break;
			case 4: board = std::make_unique<SpecializedBoard>(std::string("combination")); break;
			case 3: board = std::make_unique<SpecializedBoard>(std::string("glider")); break;
			case 2: board = std::make_unique<SpecializedBoard>(std::string("blinker")); break;
			case 1: board = std::make_unique<NormalBoard>(rows, columns); break;
			default: throw std::invalid_argument("Undefined board choice!");
		}

		switch (key){
			case 2:
			case 1: printer = std::make_unique<ToConsole>(); break;
			default: throw std::invalid_argument("Undefined output destination!");
		}

	} catch (const std::invalid_argument & e){
		cout << e.what() << endl;
		cout << "Error in creating the game factory. Aborting..." << endl;
	} catch(const exception &e){
		cout << e.what() << endl;
		cout << "Error in creating the game factory. Aborting..." << endl;
	}
	catch(...){
		cout << "Unknown error in creating the game factory. Aborting..." << endl;
	}

	void display(){
		printer->print(*board->get_board());
		board->update();
	}
	void save(){

	}
};
template <size_t N>
size_t get_array_size(int (&name) [N]){
	return N;
}
int main(int argc, char **argv) {
	try {
		/*using row_type = u_index<5>;
		row_type ii[] = {0, 0, 0, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1};
		int tests[] = {1, 0, -1, 1, 0, -1, 1, 0, -1, 1, 0 ,-1, 1, 0 ,-1};
		size_t total = get_array_size(tests);
		for (size_t i = 0; i < total; i++){
			if (tests[i] < 0){
				int use = -tests[i];
				printf("%d - %d = %d \n", ii[i], -tests[i], ii[i] - use);
			}	else {
				printf("%d + %d = %d \n", ii[i], tests[i], (ii[i] + tests[i]));
			}
		}*/
		cout << "Compiler: " <<__cplusplus << endl;
		GameFactory game{};
		int k = 0;
		while (k < 299){
			game.display();
			k++;
		}
		game.save();
	} catch(...) {
		cout << "Unexpected interruption of game.";
	}
	return 0;
}
