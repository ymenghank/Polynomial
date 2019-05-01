
#ifndef _MONOMIAL_H_
#define _MONOMIAL_H_

#include <ostream>

class Monomial
{
public:
	double coef;
	int order;
	
	Monomial(double=0);
	Monomial(double, int);
	
	Monomial operator*(const Monomial&) const;
	Monomial operator-() const;
	
	friend std::ostream& operator<<(std::ostream&, const Monomial&);
	
};



#endif