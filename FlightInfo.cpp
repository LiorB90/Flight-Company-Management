#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "FlightInfo.h"


CFlightInfo::CFlightInfo(const char* dest,unsigned num,unsigned min, unsigned km) :
		m_uiFNum(num),
		m_uiMunites(min),
		m_uiKM(km)
{
	if(strlen(dest) < MAX)
		strcpy(m_sDest,dest);
	else
		m_sDest[0] = 0; //empty string
}

/**********************************************************************************************************/
void CFlightInfo::SetDest(const char* dest)
{
	if(strlen(dest) < MAX)
		strcpy(m_sDest,dest);
	else
		m_sDest[0] = 0; //empty string
}

/**********************************************************************************************************/
bool CFlightInfo::operator!=(const CFlightInfo & other) const
{
	return !(!strcmp(m_sDest , other.m_sDest) && (m_uiFNum == other.m_uiFNum) && (m_uiMunites == other.m_uiMunites) && (m_uiKM == other.m_uiKM));
}
/**********************************************************************************************************/
bool CFlightInfo::operator==(const CFlightInfo & other) const
{
	if (m_uiFNum == other.m_uiFNum)
		return true;
	return false;
}
/**********************************************************************************************************/
/*void	CFlightInfo::Print(ostream& out) const
{
	out << "Flight Info dest: " << m_sDest << " Number " << m_uiFNum;
	out  << " minutes " << m_uiMunites << " KM " << m_uiKM << endl;
}*/
/**********************************************************************************************************/
//bool CFlightInfo::IsEqual(const CFlightInfo& other) const
//{
//	if(m_uiFNum == other.m_uiFNum)
//		return true;
//
//	return false;
//}
/**********************************************************************************************************/
ostream & operator << (ostream & out, const CFlightInfo & info)
{
	out << "Flight Info dest: " << info.m_sDest << " Number " << info.m_uiFNum;
	out << " minutes " << info.m_uiMunites << " KM " << info.m_uiKM << endl;
	return out;
}
