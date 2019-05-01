
#include "Polynomial.h"

Polynomial::Polynomial(double t_constant)
{
	first = new MonomialNode;
	first->item = Monomial(t_constant, 0);
	first->next = nullptr;
}


Polynomial::Polynomial(const Monomial& t_mono)
{
	first = new MonomialNode;
	first->item = t_mono;
	first->next = nullptr;
}


Polynomial::Polynomial(const Polynomial& other)
{
	first = nullptr;
	*this = other;
}


const Polynomial& Polynomial::operator=(const Polynomial& other)
{
	erase();
	first = new MonomialNode;
	first->item = other.first->item;
	first->next = nullptr;
	MonomialNode* it = first, *it2 = other.first;
	while (it2->next)
	{
		it2 = it2->next;
		it->next = new MonomialNode;
		it = it->next;
		it->item = it2->item;
		it->next = nullptr;
	}
	return *this;
}


void Polynomial::erase()
{
	MonomialNode* next;
	while (first)
	{
		next = first->next;
		delete first;
		first = next;
	}
}


Polynomial& Polynomial::shake()
{
	// 1. Removing leading zeros
	while (first->item.coef == 0 && first->next)
	{
		MonomialNode* it_next = first->next;
		delete first;
		first = it_next;
	}
	
	// 2. Remove other zeros
	for (MonomialNode* it = first; it; it = it->next)
	{
		for (MonomialNode* it_next = it->next; it_next && it_next->item.coef == 0; it_next = it->next)
		{
			it->next = it_next->next;
			delete it_next;
		}
	}
	
	return *this;
}


Polynomial::~Polynomial()
{
	erase();
}


std::ostream& operator<<(std::ostream& os, const Polynomial& t_poly)
{
	for (Polynomial::MonomialNode* it = t_poly.first; it; it = it->next)
	{
		os << it->item;
		if (it->next)
		{
			os << " + ";
		}
	}
	return os;
}


Polynomial Polynomial::operator+(const Polynomial& rhs) const
{
	Polynomial res(0);
	MonomialNode* it_res = res.first, *it_left = first, *it_right = rhs.first;
	while (it_left || it_right)
	{
		if (!it_right || it_left && it_left->item.order < it_right->item.order)
		{
			it_res->item = it_left->item;
			it_left = it_left->next;
		}
		else if (!it_left || it_right && it_left->item.order > it_right->item.order)
		{
			it_res->item = it_right->item;
			it_right = it_right->next;
		}
		else
		{
			it_res->item = Monomial(it_left->item.coef + it_right->item.coef, it_left->item.order);
			it_left = it_left->next;
			it_right = it_right->next;
		}
		if (it_left || it_right)
		{
			it_res->next = new MonomialNode;
			it_res = it_res->next;
		}
		it_res->next = nullptr;
	}	
	return res.shake();
}


Polynomial operator+(const Monomial& mono_lhs, const Monomial& mono_rhs)
{
	return Polynomial(mono_lhs) + Polynomial(mono_rhs);
}


Polynomial operator-(const Monomial& mono_lhs, const Monomial& mono_rhs)
{
	return Polynomial(mono_lhs) - Polynomial(mono_rhs);
}


Polynomial Polynomial::operator-() const
{
	Polynomial res(*this);
	for (MonomialNode* it = res.first; it; it = it->next)
	{
		it->item = -(it->item);
	}
	return res;
}


Polynomial Polynomial::operator-(const Polynomial& rhs) const
{
	return (*this) + (-rhs);
}


Polynomial Polynomial::operator*(const Polynomial& rhs) const
{
	Polynomial res(0);
	for (MonomialNode* it = first; it; it = it->next)
	{
		if (it->item.coef == 0)
			continue;
		Polynomial subproduct(rhs);
		for (MonomialNode* it2 = subproduct.first; it2; it2 = it2->next)
		{
			it2->item.coef *= it->item.coef;
			it2->item.order += it->item.order;
		}
		res = res + subproduct;
	}
	return res.shake();
}






