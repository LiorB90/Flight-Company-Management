#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "CrewMember.h"
class CAddress;

class CPilot :public CCrewMember
{
protected:
	 bool				UpdateMinutes(int num);
	 //bool				IsEqual(const CPilot & pilot);

public:
	CPilot(const char* name,bool ispilot,const CAddress* address=NULL, int min = 0);
	CPilot(const CPilot& pilot);
	virtual ~CPilot();

	void						PilotsToSimulator()  const;
	void						CrewGetUniform()  const;
	bool						IsCapt() const { return m_bIsCaptain;}
	void						TakeOff(int min);

	bool						operator == (const CCrewMember& crew) const;

	CCrewMember*				clone()const {return new CPilot (*this);}
	//bool 						operator += (int num);
	const		CCrewMember&	operator = (const CCrewMember& crew);
	void						Print(ostream& out) const;


private:
	bool m_bIsCaptain;
	const CAddress* m_pCAddress;

};

