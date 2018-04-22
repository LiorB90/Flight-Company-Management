#include "Host.h"



CHost::CHost(const char* name, HostType type, int min) :
	CCrewMember(name, min),
	m_HTType(type)
{
}
/**********************************************************************************************************/
void CHost::CrewGetPresent() const
{
	CCrewMember::CrewGetPresent();
	cout <<" I wasnt expecting it	" << endl;
}
/**********************************************************************************************************/
void CHost::CrewGetUniform() const
{
	cout << CCrewMember::GetName() << ": I think the new uniform is very nice!" << endl;
}
/**********************************************************************************************************/
const CCrewMember & CHost::operator=(const CCrewMember & host)
{
	if (this == &host)
		return *this;
	if ((typeid(host) != typeid(CHost)))
		return *this;
	CCrewMember::operator =(host);
	CHost& temp = (CHost&)host;
	m_HTType = temp.m_HTType;
	return *this;
}
/**********************************************************************************************************/
void CHost::Print(ostream & out) const
{
	char* temp[3] = { "Host Regular","Host Super","Host Calcelan" };
	out << temp[m_HTType]<<" ";	
	CCrewMember::Print(out);
	out << endl;
}

