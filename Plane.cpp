#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "Plane.h"

int CPlane::m_siLastNum = START_NUM;
/**********************************************************************************************************/
void CPlane::print(ostream & out) const
{
	if (this->m_pDegem)
		out << "Plane " << this->m_iNum << " degem " << this->m_pDegem << " seats " << this->m_iSeats << endl;
	else
		out << "Error in plane info" << endl;
}
/**********************************************************************************************************/
CPlane::CPlane(int seats,const char* degem) :
	m_pDegem(NULL)
{
	if(seats < 0)
		m_iSeats = 0;
	else
		m_iSeats = seats;
	m_iNum =  m_siLastNum++;
	SetDegem(degem);
}
/**********************************************************************************************************/
CPlane::CPlane(const CPlane& other) :
	m_pDegem(NULL)
{
	/*m_iSeats = other.m_iSeats;
	m_iNum =  other.m_iNum;
	SetDegem(other.m_pDegem);*/
	*this = other;
}
/**********************************************************************************************************/
CPlane::~CPlane()
{
	delete []m_pDegem;
}
/**********************************************************************************************************/
const CPlane & CPlane::operator++()//prefix
{
	m_iSeats++;
	return *this;
}
/**********************************************************************************************************/
CPlane  CPlane::operator++(int)//postfix
{
	CPlane temp(*this);
	m_iSeats++;
	return temp;
}
/**********************************************************************************************************/
const CPlane & CPlane::operator=(const CPlane & plane)
{
	if ((!(this == &plane)) && (&plane!=NULL))
	{
		m_iSeats = plane.m_iSeats;
		m_iNum = plane.m_iNum;
		SetDegem(plane.m_pDegem);
	}
	return *this;
}
/**********************************************************************************************************/
bool CPlane::operator==(const CPlane & plane)
{
	if (m_iNum == plane.m_iNum)
		return true;
	return false;
}
/**********************************************************************************************************/
//bool CPlane::IsEqual(const CPlane& other) const
//{
//	if(m_iNum == other.m_iNum)
//		return true;
//
//	return false;
//
//}
/**********************************************************************************************************/
void	CPlane::SetDegem(const char* degem)
{
	if (m_pDegem)
		delete [] m_pDegem;
	if (degem)
	{
		m_pDegem = new char[strlen(degem)+1];
		strcpy(m_pDegem,degem);
	} else
		m_pDegem = NULL;
}
/**********************************************************************************************************/
ostream & operator<<(ostream & out, const CPlane & plane) 
{
	// TODO: insert return statement here
	plane.print(out);
	return out;
}
/**********************************************************************************************************/
/*
void CPlane::Print(ostream& out) const
{
if (m_pDegem)
out << "Plane " << m_iNum << " degem " << m_pDegem << " seats " << m_iSeats << endl;
else
out << "Error in plane info" << endl;

}
*/
