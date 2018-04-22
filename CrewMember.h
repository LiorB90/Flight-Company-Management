#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;
class CCrewMember
{
protected:
	virtual bool		UpdateMinutes(int min);
	//virtual bool		IsEqual(const CCrewMember& other);

public:
	const static int START_ID = 1000;

	CCrewMember(const char* name,int min=0);
	CCrewMember(const CCrewMember& other);
	virtual ~CCrewMember(void);


	int								GetMinutes() const {return m_iMinutes;}
	const char*						GetName() const {return m_pName;}
	void							SetName(const char* name);
	int								GetID() const {return m_iID;}
	virtual void					TakeOff(int min) ;
	virtual	void					CrewGetUniform()const=0;
	virtual	CCrewMember*			clone()const=0;
	virtual void					CrewGetPresent() const;


	virtual const	CCrewMember&	operator = (const CCrewMember& crew);
	
	bool 							operator += (int num);
	virtual bool					operator == (const CCrewMember& crew) const;


	virtual void					Print(ostream& out) const;	


private:
	static int	m_siLastID;
	int			m_iID;
	char*		m_pName;
	int			m_iMinutes;
};