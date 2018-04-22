#pragma once


#include <iostream>
using namespace std;

class CAddress
{
public:	
	CAddress(unsigned int uiHouseNumber,const char* pStreet,const char* pCity="Tel Aviv");
	CAddress(const CAddress& address);	
	virtual~CAddress();


	unsigned int		GetHouseNumber()const{return m_uiHouseNumber;}
	const char*			GetStreet()const {return m_pStreet;}
	const char*			GetCity()const {return m_pCity;}
	const CAddress&		GetCurrentAddress() const { return *this; }
	
	
	bool				operator==(const CAddress& other) const;
	bool				operator!=(const CAddress& other) const;
	const CAddress&		operator = (const CAddress& address);
	friend ostream&		operator << (ostream& out, const CAddress& address);
	friend istream&		operator >> (istream &in, CAddress& address);


	void				UpdateAddress(const char* city,const char* street,unsigned int uiNumber);

private:
	unsigned int	m_uiHouseNumber;
	char*			m_pStreet;
	char*			m_pCity;

	void	SetStreet(const char* pStreet);
	void	SetCity(const char* pCity);
};