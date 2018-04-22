#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "CrewMember.h"

int CCrewMember::m_siLastID = START_ID;
/**********************************************************************************************************/
bool CCrewMember::UpdateMinutes(int num)
{
	if (num >= 0)
	{
		m_iMinutes += num;
		return true;
	}
	return false;	
}
/**********************************************************************************************************/
CCrewMember::CCrewMember(const char* name,int min) :
	m_pName(NULL),
	m_iMinutes(min)
{
	SetName(name);
	m_iID = m_siLastID++;
}
/**********************************************************************************************************/
CCrewMember::CCrewMember(const CCrewMember& other): 
	m_pName(NULL)
{
	*this = other;
}
/**********************************************************************************************************/
CCrewMember::~CCrewMember()
{
	delete [] m_pName;
}
/**********************************************************************************************************/
const CCrewMember & CCrewMember::operator=(const CCrewMember & crew)
{
	if ((!(this == &crew)) && (&crew!=NULL))
	{
		SetName(crew.m_pName);
		UpdateMinutes(crew.m_iMinutes);
		m_iID = crew.m_iID;
	}
	return *this;
}

/**********************************************************************************************************/
bool  CCrewMember::operator+=(int num)
{
	return UpdateMinutes(num);
}
/**********************************************************************************************************/
bool CCrewMember::operator == (const CCrewMember & crew)  const
{
	//return IsEqual(crew);
	if (!strcmp(crew.GetName(), GetName()))
		return true;
	return false;
}
/**********************************************************************************************************/
void	CCrewMember::Print(ostream& out) const
{
	if (m_pName)
		out  << m_pName << " minutes "<< m_iMinutes <<" ";
	else
		out << "Error in Crewmember " << endl;
}
/**********************************************************************************************************/
//bool CCrewMember::IsEqual(const CCrewMember& other)
//{
//	if(!strcmp(other.GetName(),GetName()))
//		return true;
//	return false;
//}
/**********************************************************************************************************/
void	CCrewMember::SetName(const char* name)
{
	if (m_pName)
		delete [] m_pName;
	if (name)
	{
		m_pName = new char[strlen(name)+1];
		strcpy(m_pName,name);
	} else
		m_pName = NULL;
}
/**********************************************************************************************************/
void CCrewMember::TakeOff(int min) 
{
	UpdateMinutes(min);
}
/**********************************************************************************************************/
void CCrewMember::CrewGetPresent() const
{
	cout << CCrewMember::GetName() << ": thanking the company for receiving the holiday gift " << endl;
}
