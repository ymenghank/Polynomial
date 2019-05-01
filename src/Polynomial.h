
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <ostream>

#include "Monomial.h"


class Polynomial
{
public:
	Polynomial(double=0);
	Polynomial(const Monomial&);
	Polynomial(const Polynomial&);
	~Polynomial();
	
	const Polynomial& operator=(const Polynomial&);

	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator-() const;
	Polynomial operator-(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
	
	template<class T> T operator()(const T& x) const
	{
		int order = 0;
		T res(0), term(1);
		for (MonomialNode* it = first; it; it = it->next)
		{
			for (; order < it->item.order; ++order)
			{
				term = term * x;
			}
			res = res + (term * it->item.coef);
		}
		return res;
	}
	
	
protected:
	struct MonomialNode
	{
		Monomial item;
		MonomialNode* next;
	};

	MonomialNode* first;
	
	void erase();
	Polynomial& shake();
};


Polynomial operator+(const Monomial&, const Monomial&);

Polynomial operator-(const Monomial&, const Monomial&);



#endif