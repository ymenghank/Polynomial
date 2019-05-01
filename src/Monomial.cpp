
#include "Monomial.h"


Monomial::Monomial(double t_coef)
{
	coef = t_coef;
	order = 0;
}


Monomial::Monomial(double t_coef, int t_order)
{
	coef = t_coef;
	order = t_order;
}


Monomial Monomial::operator*(const Monomial& rhs) const
{
	return Monomial(coef * rhs.coef, order + rhs.order);
}


Monomial Monomial::operator-() const
{
	return Monomial(-coef, order);
}


std::ostream& operator<<(std::ostream& os, const Monomial& t_mono)
{
	if (t_mono.order == 0 || t_mono.coef == 0)
	{
		os << t_mono.coef;
	}
	else
	{
		if (t_mono.coef == -1)
		{
			os << '-';
		}
		else if (t_mono.coef != 1)
		{
			os << t_mono.coef;
		}
		os << 'x';
		if (t_mono.order != 1)
		{
			os << '^' << t_mono.order;
		}
	}
	return os;
}






