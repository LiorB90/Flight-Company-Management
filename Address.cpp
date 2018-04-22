#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "Address.h"

//constructor with value - pCountry has a default !!!! - must be at the end!!!!
CAddress::CAddress(unsigned int uiHouseNumber,const char* pStreet,const char* pCity):
	m_uiHouseNumber(uiHouseNumber),
	m_pStreet(NULL),
	m_pCity(NULL)
{
	//SetStreet(pStreet);
	//SetCity(pCity);
	UpdateAddress(pCity, pStreet, uiHouseNumber);
}
/**********************************************************************************************************/
//Copy constructor
CAddress::CAddress(const CAddress& address):
	m_pStreet(NULL),
	m_pCity(NULL)
{
	*this = address;
}
/**********************************************************************************************************/
CAddress::~CAddress(void)
{
	delete []m_pStreet;
	delete []m_pCity;
}
/**********************************************************************************************************/
void CAddress::SetStreet(const char* pStreet)
{
	if (!pStreet)
		return;

	if (m_pStreet != NULL)			//If not the first time need to delete what was already allocated by previous new!!!
		delete []m_pStreet;

	m_pStreet=new char[strlen(pStreet)+1];

	strcpy(m_pStreet,pStreet);
}
/**********************************************************************************************************/
void CAddress::SetCity(const char* pCity)
{
	if (!pCity)
		return;

	if (m_pCity != NULL)		//If not the first time need to delete what was already allocated by previous new!!!
		delete []m_pCity;

	m_pCity = new char[strlen(pCity)+1];
	strcpy(m_pCity,pCity);
}
/**********************************************************************************************************/
void	CAddress::UpdateAddress(const char* city,const char* street,
			unsigned int uiNumber){	
	m_uiHouseNumber = uiNumber;
	SetStreet(street);
	SetCity(city);
}
/**********************************************************************************************************/
bool CAddress::operator == (const CAddress & other) const
{
	return ((m_uiHouseNumber == other.m_uiHouseNumber) && (!strcmp(m_pStreet , other.m_pStreet)) && (!strcmp(m_pCity , other.m_pCity)));
}
/**********************************************************************************************************/
bool CAddress::operator != (const CAddress & other) const
{
	return !(*this == other);
}
/**********************************************************************************************************/
const CAddress & CAddress::operator = (const CAddress & address)
{
	if (this != &address && &address!=NULL)
	{
		//m_uiHouseNumber = address.m_uiHouseNumber;
		//SetCity(address.m_pCity);
		//SetStreet(address.m_pStreet);
		UpdateAddress(address.m_pCity, address.m_pStreet, address.m_uiHouseNumber);
	}
	return *this;
}
/**********************************************************************************************************/
ostream & operator << (ostream & out, const CAddress & address)
{
	if ((address.m_pCity == NULL) || (address.m_pStreet == NULL))
		out << "Error in address information" << endl;
	else
	{
		out << address.m_pStreet << "  " << address.m_uiHouseNumber << ", " << address.m_pCity<<" ";
	}
	return out;
}
/**********************************************************************************************************/
istream & operator >> (istream & in, CAddress & address) 
{
	char tempStreet[100], tempCity[100];
	cout << "Please enter house number street name and city name: " << endl;
	in >> address.m_uiHouseNumber >> tempStreet >> tempCity;

	address.SetStreet(tempStreet);
	address.SetCity(tempCity);
	return in;
}
/**********************************************************************************************************/
