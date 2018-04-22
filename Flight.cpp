#include "Flight.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Address.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"

CFlight::CFlight(const CFlightInfo& info,CPlane* pPlane) :
	m_pPlane(pPlane),
	m_FlightInfo(info)
{
	m_iCrewCount = 0;
}
/**********************************************************************************************************/
bool CFlight::AddCrewMember( CCrewMember* pMember)
{
	if(m_iCrewCount == MAX_CREW)
		return false;

	if(IsCrewInFlight(pMember))
		return false;

	m_pCrewArr[m_iCrewCount] = pMember;
	m_iCrewCount++;
	return true;
}
/**********************************************************************************************************/
bool CFlight::TakeOff() const
{
	int p_count = 0, hs_count=0;
	
	if (m_pPlane == NULL)
		return false;
	CCargo* ptemp = dynamic_cast<CCargo*>(m_pPlane);
	if (ptemp)
	{
		for (int i = 0;i < m_iCrewCount;i++)
		{
			CPilot* pitemp = dynamic_cast<CPilot*>(m_pCrewArr[i]);
			if (pitemp)
				p_count++;
		}
		if (p_count == 0)
			return false;
		((CCargo*)m_pPlane)->TakeOff(m_FlightInfo.GetMin());
	}
	else
	{
		for (int i = 0;i < m_iCrewCount;i++)
		{
			CPilot* pitemp = dynamic_cast<CPilot*>(m_pCrewArr[i]);
			if (pitemp)
				p_count++;

			CHost* pshtemp = dynamic_cast<CHost*>(m_pCrewArr[i]);
			if (pshtemp)
				if(((CHost*)m_pCrewArr[i])->GetType()==1)
					hs_count++;
		}
		if (p_count != 1 || hs_count > 1)
			return false;
	}
	for (int i = 0;i < m_iCrewCount;i++)
	{
			m_pCrewArr[i]->TakeOff(m_FlightInfo.GetMin());
	}
}
/**********************************************************************************************************/
//since we keep pointer we can check the address.
bool CFlight::IsCrewInFlight(const CCrewMember* pMember)
{
	for(int i = 0; i < m_iCrewCount; i++)
		if(m_pCrewArr[i] == pMember)
			return true;

	return false;
}
/**********************************************************************************************************/
bool CFlight::operator==(const CFlight & other)const
{
	return (m_FlightInfo == other.m_FlightInfo);
}

/**********************************************************************************************************/
CFlight& CFlight::operator+( CCrewMember * other)
{
	// TODO: insert return statement here
	if (m_iCrewCount == MAX_CREW)
	{
		cout << "cant add " << endl;
		return *this;
	}
	if (IsCrewInFlight(other))
	{
		cout << "already in " << endl;
		return *this;
	}
	m_pCrewArr[m_iCrewCount] = other;
	m_iCrewCount++;
	return *this;
}
/**********************************************************************************************************/
ostream & operator<<(ostream & out, const CFlight & flight)
{
	// TODO: insert return statement here
	if(!flight.m_FlightInfo)
	{		
		out << "No Flight ";
		return out;
	}
	
	out << "Flight ";
	out << flight.m_FlightInfo;
	if (flight.m_pPlane == NULL)
		out << " No plane assign yet ";
	else
		out << *flight.m_pPlane;
		out << " There are " << flight.m_iCrewCount << " crew memebers in flight:" << endl;
	
	for (int i = 0; i < flight.m_iCrewCount; i++)
		flight.m_pCrewArr[i]->Print(out);
	return out;
}
