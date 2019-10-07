/*
 * ToConsole.h
 *
 *  Created on: 6 Oct 2019
 *      Author: Precious Ugo Abara
 */

#ifndef TOCONSOLE_H_
#define TOCONSOLE_H_
#include "PrettyPrint.h"

namespace printer {

	class ToConsole final: public PrettyPrint {
	public:
		ToConsole();

		virtual ~ToConsole();

		virtual void print(const std::vector<std::vector<bool>> & board) const override;
	private:
		void pos(short C, short R)	const;
		void clear() const;
	};
} /* namespace printer */

#endif /* TOCONSOLE_H_ */
