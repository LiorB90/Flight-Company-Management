#pragma once
#include <iostream>
using namespace std;

class CFlightInfo
{
public:
	CFlightInfo(const char* dest,unsigned n,unsigned min, unsigned km);
	// no allocation so no need for copy,operator =, or distractor
	
	

	void					SetDest(const char* dest);
	const char*				GetDest() const {return m_sDest;}
	void					SetFNum(unsigned n) { m_uiFNum = n;}
	unsigned				GetFNum() const {return m_uiFNum;}
	void					SetMin(unsigned m) {m_uiMunites = m;}
	unsigned				GetMin() const {return m_uiMunites;}
	void					SetKM(unsigned km) {m_uiKM = km;}
	unsigned				GetKM() const {return m_uiKM;}

	
	friend  ostream&		operator << (ostream& out, const CFlightInfo& info);
	bool					operator!=(const CFlightInfo& other) const;
	bool					operator == (const CFlightInfo& other) const;

	operator int() const { return m_uiMunites;}


	//void		Print(ostream& out) const;
	//bool		IsEqual(const CFlightInfo& other) const;


private:
	static const int MAX = 100;
	char			m_sDest[MAX];
	unsigned		m_uiFNum;
	unsigned		m_uiMunites;
	unsigned		m_uiKM;

};

