#pragma once
#include <iostream>
using namespace std;
#include "Plane.h"

class CCargo :	public CPlane
{
protected:
	void		print(ostream& out) const;

public:

	CCargo(int seats, const char* degem,float maxweight, float maxvolume);
	// no allocation so no need for copy constractor or distractor or =

	bool				Load(float weight, float volume);
	bool				TakeOff(unsigned dist) const;
	CCargo*				clone()const { return new CCargo(*this); }
	const	CPlane&		operator = (const CPlane& plane);

private:
	float m_fCurrentWeight;
	float m_fCurrentVolume;
	float m_fMaxWeight;
	float m_fMaxVolume;
};


