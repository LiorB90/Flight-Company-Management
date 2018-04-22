#pragma once
#include "FlightInfo.h"
class CPlane;
class CCrewMember;
class CCargo;
class CPilot;
class CHost;

class CFlight
{
public:
	CFlight(const CFlightInfo& info,CPlane* pPlane = NULL);
	//All members that are pointers are actuallly reference, no allocation.
	//Therefor no need for destructor, copy constructor and operator =

	void				SetPlane(CPlane* pPlane) {m_pPlane = pPlane;} //saving the pointer
	int					GetFlightNum() const {return m_FlightInfo.GetFNum();}


	bool				AddCrewMember( CCrewMember* pMember);
	const CFlightInfo&  GetFlightInfo() const {return m_FlightInfo;}
	bool				TakeOff() const;
	

	bool				operator==(const CFlight& other)const;
	CFlight& 	        operator+( CCrewMember* other) ;
	friend ostream&		operator << (ostream& out, const CFlight& flight);

private:
	static const int MAX_CREW = 10;

	CFlightInfo		m_FlightInfo;
	CPlane*			m_pPlane;
	 CCrewMember*	m_pCrewArr[MAX_CREW];
	int				m_iCrewCount;


	bool IsCrewInFlight(const CCrewMember* pMember);
};

