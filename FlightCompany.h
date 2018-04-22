#pragma once
#include <iostream>
using namespace std;
#include "Plane.h"
#include "Flight.h"
#include "CrewMember.h"
#include "typeinfo.h"
#include "Pilot.h" 
#include "Cargo.h"
#include "Host.h"


class CFlightCompany
{
public:
	CFlightCompany(const char* name);
	~CFlightCompany();


	bool			AddCrewMember(const CCrewMember& member);
	bool			AddFlight(const CFlight& flight);
	bool			AddPlane(const CPlane& plane);

	bool			AddCrewToFlight(int flightNum,int crewNum);

	CFlight*		GetFlightByNum(int num);
	//CCrewMember*	GetCrewByNum(int num);
	CCrewMember*    GetCrewMember(int ind);
	const char*		GetName() const {return m_pName;}
	void			SetName(const char* name);
	CPlane*			GetPlane(int index);

	unsigned int	GetCargoCount() const;
	void			PilotsToSimulator() const;
	void			CrewGetPresent() const;
	void			CrewGetUniform() const;
	void			TakeOff(int num) ;
	CCrewMember**	GetCrewArray(int& count) ;

	void			Print(ostream& out) const;
	

private:

	static const int MAX_CREW = 100;
	static const int MAX_PLANES = 50;
	static const int MAX_FLIGHT = 200;

	char* m_pName;

	CCrewMember*	m_pCrewArr[MAX_CREW];
	CPlane*			m_pPlaneArr[MAX_PLANES];
	CFlight*		m_pFlightArr[MAX_FLIGHT];
	int				m_iCrewCount;
	int				m_iPlaneCount;
	int				m_iFlightCount;

	bool	IsCrewInCompany(const CCrewMember& member);
	bool	IsFlightInCompany(const CFlight& flight);
	bool	IsPlaneInCompany(const CPlane& plane);

	CFlightCompany(const CFlightCompany& other);
	const CFlightCompany operator =(const CFlightCompany& other);
	

};

