/*
 * u_index.h
 *
 *  Created on: 5 Oct 2019
 *      Author: Precious Ugo Abara
 */

#ifndef U_INDEX_H_
#define U_INDEX_H_

#include <iostream>
using namespace std;

struct u_index{
	int index = 0;
	size_t T;
	u_index(size_t start, size_t range): T {range} {
		index = start % T;
	}
	int& operator++(int){
		if (++index == T) index = 0;
		return index;
	}
	int & operator--(int){
		if (--index < 0) {
			index = T - 1;
		}

		return index;
	}
	bool operator== (int type){
		return index == type;
	}

	operator int () const {
		return index;
	}

	/*operator size_t() const {
		return static_cast<size_t>(index);
	}*/

	int operator+ (int amount) const{
		if (amount != 0 && amount != 1) throw std::invalid_argument("Undefined behavior. You can sum 0 or 1");
		int rest = (index + amount) % T;
		return rest;
	}

	int operator- (int amount){
		if (amount != 0 && amount != 1) throw std::invalid_argument("Undefined behavior. You can sum 0 or 1");
		int rest = index - amount;
		if (rest < 0){
			return T - (-rest) % T; //cycles
		}
		return rest;
	}
	bool operator<(const u_index & rhs){
		return index < rhs.index;
	}
	friend ostream& operator << (ostream & os,const u_index & u){
		os << u.index;
		return os;
	}

};


#endif /* U_INDEX_H_ */
