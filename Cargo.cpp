#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "Cargo.h"



void CCargo::print(ostream & out) const
{
	out << "Cargo ";
	CPlane::print(out);
	out << "M_Weight: " << this->m_fMaxWeight << " ";
	out << "m_Volume: " << this->m_fMaxVolume << endl;
	out << "C_Weight: " << this->m_fCurrentWeight<<" ";
	out << "C_Volume: " << this->m_fCurrentVolume << endl;
}
/**********************************************************************************************************/
CCargo::CCargo(int seats, const char* degem, float weight, float volume):
CPlane(seats,degem),
m_fMaxVolume(volume),
m_fMaxWeight(weight)
{
	m_fCurrentVolume = 0;
	m_fCurrentWeight = 0;
}
/**********************************************************************************************************/
bool CCargo::Load(float weight, float volume)
{
	if(((weight +m_fCurrentWeight)>m_fMaxWeight) || ((volume+m_fCurrentVolume)>m_fMaxVolume))
		return false;
	m_fCurrentWeight += weight;
	m_fCurrentVolume += volume;
	return true;
}
/**********************************************************************************************************/
bool CCargo::TakeOff(unsigned dist) const
{
	
	cout << "Need to Add " << dist << " Minutes to My Log Book " << endl;
	return true;
}
/**********************************************************************************************************/
const CPlane & CCargo::operator=(const CPlane & plane)
{
	if (this == &plane)
		return *this;
	if((typeid(plane) != typeid(CCargo)))
		return *this;
	CPlane::operator=(plane);
	CCargo& car = (CCargo&)plane;
	m_fCurrentWeight= car.m_fCurrentWeight;
	m_fCurrentVolume = car.m_fCurrentVolume;
	m_fMaxWeight = car.m_fMaxWeight;
	m_fMaxVolume = car.m_fMaxVolume;
	return *this;
}

