#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "CrewMember.h"

class CHost :	public CCrewMember
{
public:
	enum HostType { eRegular, eSuper, eCalcelan };
	CHost(const char* name, HostType type, int min = 0);
	// no allocation.
	//Therefor no need for destructor, copy constructor and operator =


	HostType			GetType() const{ return m_HTType; }
	void				CrewGetPresent() const;
	void				CrewGetUniform()  const;
	const CCrewMember&	operator = (const CCrewMember& crew);
	CCrewMember*		clone()const { return new CHost(*this); }


	void				Print(ostream& out) const;


private:
	HostType m_HTType;

};

