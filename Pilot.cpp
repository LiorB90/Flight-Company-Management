#include "Pilot.h"
#include "Address.h"


bool CPilot::UpdateMinutes(int num)
{
	if(m_bIsCaptain)
		return CCrewMember::UpdateMinutes(num + num / 10);
	else
		return CCrewMember::UpdateMinutes(num);
}
/**********************************************************************************************************/
CPilot::CPilot(const char* name, bool ispilot, const CAddress* address, int min):
	CCrewMember(name,min),
	m_bIsCaptain(ispilot),
	m_pCAddress(NULL)
{
	if(address)
		m_pCAddress = new CAddress(*address);
}
/**********************************************************************************************************/
CPilot::CPilot(const CPilot & pilot):
CCrewMember(pilot),
m_pCAddress(NULL)
{	
	if(pilot.m_pCAddress)
		m_pCAddress = new CAddress(*pilot.m_pCAddress);
	m_bIsCaptain = pilot.m_bIsCaptain;

}
/**********************************************************************************************************/
CPilot::~CPilot()
{
	delete m_pCAddress;
}
/**********************************************************************************************************/
void CPilot::PilotsToSimulator()  const
{
	cout << "Pilot " << CCrewMember::GetName() << ": got the message will come soon" << endl;
}
/**********************************************************************************************************/
//void CPilot::CrewGetPresent()  const
//{
//	cout << CCrewMember::GetName()<< ": thanking the company for receiving the holiday gift" << endl;
//
//}
/**********************************************************************************************************/
void CPilot::CrewGetUniform()  const
{
cout<< CCrewMember::GetName() << ": this is the fifth time I get a new uniform - this is a waste of money!" << endl;
}
/**********************************************************************************************************/
void CPilot::TakeOff(int min)
{
	if (m_bIsCaptain)
		CCrewMember::TakeOff(min + min / 10);
	else
		CCrewMember::TakeOff(min);
}

/**********************************************************************************************************/
bool CPilot::operator==(const CCrewMember & crew) const
{
	if (typeid(crew) != typeid(CPilot)) //different
		return false;

	if (!CCrewMember::operator ==(crew))
		return false;

	return (m_pCAddress==((CPilot&)crew).m_pCAddress);
}

/**********************************************************************************************************/
const CCrewMember & CPilot::operator = (const CCrewMember& pilot)
{
	if (this == &pilot)
		return *this;
	if ((typeid(pilot) != typeid(CPilot)))
		return *this;
	CCrewMember::operator =(pilot);	
	CPilot& temp = ((CPilot&)pilot);
	m_bIsCaptain = temp.m_bIsCaptain;
	if(temp.m_pCAddress)
		m_pCAddress = new CAddress(*temp.m_pCAddress);
	return *this;
}
/**********************************************************************************************************/
//bool CPilot::IsEqual(const CPilot & pilot)
//{
//	if (CCrewMember::IsEqual(pilot))
//		return (m_pCAddress == pilot.m_pCAddress);
//	return false;
//}
/**********************************************************************************************************/
void CPilot::Print(ostream & out) const
{
	out << "Pilot: ";
	CCrewMember::Print(out);
	if (m_pCAddress)
		out << "Home: " << *m_pCAddress;
	else
		out << "No Address Registarted ";
	if (m_bIsCaptain)
		out << "Captain " << endl;
	else
		out << "Not a Captain " << endl;	
}
