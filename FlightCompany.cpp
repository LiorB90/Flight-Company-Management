#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

#include "FlightCompany.h"


CFlightCompany::CFlightCompany(const char* name) : 
	m_pName(NULL)
{
	SetName(name);
	m_iCrewCount = 0;
	m_iPlaneCount = 0;
	m_iFlightCount = 0;
}
/**********************************************************************************************************/
CFlightCompany::~CFlightCompany()
{
	for(int i = 0; i < m_iPlaneCount; i++)
		delete m_pPlaneArr[i];

	for (int i = 0; i < m_iCrewCount; i++)
		delete m_pCrewArr[i];

	for (int i = 0; i < m_iFlightCount; i++)
		delete m_pFlightArr[i];

	delete [] m_pName;
}
/**********************************************************************************************************/
void	CFlightCompany::SetName(const char* name)
{
	if (m_pName)
		delete [] m_pName;

	if (name)
	{
		m_pName = new char[strlen(name)+1];
		strcpy(m_pName,name);
	} 
	else
		m_pName = NULL;
}
/**********************************************************************************************************/
bool	CFlightCompany::AddCrewMember(const CCrewMember& member)
{
	if(m_iCrewCount == MAX_CREW)
		return false;

	if(IsCrewInCompany(member))
		return false;

	m_pCrewArr[m_iCrewCount]=member.clone();
	m_iCrewCount++;
	return true;
}
/**********************************************************************************************************/
bool	CFlightCompany::AddFlight(const CFlight& flight)
{
	if(m_iFlightCount == MAX_FLIGHT)
		return false;

	if(IsFlightInCompany(flight))
		return false;

	m_pFlightArr[m_iFlightCount] = new CFlight(flight);
	m_iFlightCount++;
	return true;
}
/**********************************************************************************************************/
bool CFlightCompany::AddPlane(const CPlane& plane)
{
	if(m_iPlaneCount == MAX_PLANES)
		return false;

	if(IsPlaneInCompany(plane))
		return false;

	m_pPlaneArr[m_iPlaneCount]=plane.clone();
	m_iPlaneCount++;
	return true;
}
/**********************************************************************************************************/
bool	CFlightCompany::IsCrewInCompany(const CCrewMember& member)
{
	for (int i = 0; i < m_iCrewCount; i++)
	{
		if(*m_pCrewArr[i] == member)
		return true;
	}
	return false;
}
/**********************************************************************************************************/
bool	CFlightCompany::IsFlightInCompany(const CFlight& flight)
{
	for(int i = 0; i < m_iFlightCount; i++)
		if(*m_pFlightArr[i] == flight)
			return true;
	return false;
}
/**********************************************************************************************************/
bool	CFlightCompany::IsPlaneInCompany(const CPlane& plane)
{
	for(int i = 0; i < m_iPlaneCount; i++)
		if(*m_pPlaneArr[i]==(plane))
			return true;
	return false;
}
/**********************************************************************************************************/
bool	CFlightCompany::AddCrewToFlight(int flightNum,int crewNum)
{
	CFlight* pF = GetFlightByNum(flightNum);
	if(!pF)
		return false;

	CCrewMember* pMember = GetCrewMember(crewNum);//Changed because the search func was changed
	if(!pMember)
		return false;

	pF->AddCrewMember(pMember);
	return true;
}
/**********************************************************************************************************/
CFlight* CFlightCompany::GetFlightByNum(int num)
{
	for(int i = 0; i < m_iFlightCount; i++)
		if(m_pFlightArr[i]->GetFlightNum() == num)
			return m_pFlightArr[i];
	return NULL;
}
/**********************************************************************************************************/
CCrewMember * CFlightCompany::GetCrewMember(int ind)
{
	if(m_iCrewCount>=ind && ind>=0)
		return m_pCrewArr[ind];
	return NULL;
}
/**********************************************************************************************************/
//CCrewMember*	CFlightCompany::GetCrewByNum(int num)
//{
//	for(int i = 0; i < m_iCrewCount; i++)
//		if(m_pCrewArr[i]->GetID() == num)
//			return m_pCrewArr[i];
//	return NULL;
//
//}
/**********************************************************************************************************/
void	CFlightCompany::Print(ostream& out) const
{
	if (!m_pName)
	{
		out << "Error in company Name" << endl;
		return;
	}

	out << "Flight company: " << m_pName << endl;
	out << "There are " <<  m_iCrewCount << " Crew members: "<<endl;
	for (int i = 0; i < m_iCrewCount; i++)
	{
			m_pCrewArr[i]->Print(out);
	}
		
	out << "There are " << m_iPlaneCount << " Planes: " << endl;
	for (int i = 0; i < m_iPlaneCount; i++)
	{
			out<< *m_pPlaneArr[i];
	}

	out << "There are " << m_iFlightCount << " Flights: " << endl;
	for (int i = 0; i < m_iFlightCount; i++)
		out << *m_pFlightArr[i];
}
/**********************************************************************************************************/  
CCrewMember** CFlightCompany::GetCrewArray(int & count) 
{
	count = m_iCrewCount;
	return m_pCrewArr;
}
/**********************************************************************************************************/
CPlane*		CFlightCompany::GetPlane(int index)
{
	if(index < 0 || index >= m_iPlaneCount)
		return NULL;

	return m_pPlaneArr[index];

}
/**********************************************************************************************************/
unsigned int CFlightCompany::GetCargoCount() const
{
	unsigned count = 0;
	for (int i = 0;i < m_iPlaneCount;i++)
	{
		if (typeid(*m_pPlaneArr[i]) == typeid(CCargo))
			count++;
	}
	return count;
}
/**********************************************************************************************************/
void CFlightCompany::PilotsToSimulator() const
{
	for (int i = 0;i < m_iCrewCount;i++)
	{
		if (typeid(*m_pCrewArr[i]) == typeid(CPilot))
			((CPilot*)m_pCrewArr[i])->PilotsToSimulator();
	}
}
/**********************************************************************************************************/
void CFlightCompany::CrewGetPresent() const
{
	for (int i = 0;i < m_iCrewCount; i++)
	{
			m_pCrewArr[i]->CrewGetPresent();
	}
}
/**********************************************************************************************************/
void CFlightCompany::CrewGetUniform() const
{
	for (int i = 0;i < m_iCrewCount; i++)
	{
			m_pCrewArr[i]->CrewGetUniform();
	}
}
/**********************************************************************************************************/
void CFlightCompany::TakeOff(int num) 
{
	CFlight* temp = GetFlightByNum(num);
	temp->TakeOff();
}
/**********************************************************************************************************/

