#pragma once
#include <fstream>
#include <sstream>
#include "..\StringLib\TString.h"
#include "..\TimeLib\CDate.h"
#include "..\TimeLib\class.h"
#include "..\TimeLib\functions.h"
#include "..\ArchiveLib\archive.h"

class Film // обьект создается
{
    CTime TimeOfGoes;
    float Rate;
    CString Name;
    CString type;
    int CostForTicket;
    CDate liveBefore;
public:
    Film();
    Film(Film& f);
    Film(CTime timeofgoes, float rate, CString name, CString type, int costforticket, CDate livebefore);

    ~Film();

    CTime getTimeOfGoes();
    float getRate();
    CString getName();
    CString getType();
    int getCostForTicket();
    CDate getliveBefore();

    void setTimeOfGoes(CTime T);
    void setRate(float R);
    void setName(CString str);
    void setType(CString str);
    void setCostForTicket(int cost);
    void setliveBefore(CDate date);

    Film& operator=(const Film& f)
    {
        if (this != &f)
        {
            TimeOfGoes = f.TimeOfGoes;
            Rate = f.Rate;
            Name = f.Name;
            type = f.type;
            CostForTicket = f.CostForTicket;
            liveBefore = f.liveBefore;
        }
        return *this;
    }
};
enum Holl_state { Empty = 1, Full =2, Not_Empty=3, Already=4 };
class Holl // обьект создается
{
    Film f;
    CTime StartTime;
    CTime FinishTime;
    int CountOfSits;
    Holl_state s;
public:
    Holl(); //поправить у всех 3-х конструкторах реализацию и написать ее
    Holl(Holl& h);
    Holl(Film F, CTime starttime, CTime finishtime, int countofsits, Holl_state s);

    ~Holl();

    Film getFilm();
    CTime getStartTime();
    CTime getFinishTime();
    int getCountOfSits();
    Holl_state getstates();

    void setFilm(Film f);
    void setStartTime(CTime ST);
    void setFinishTime(CTime FT);
    void setCountOfSits(int count);
    void setstates(Holl_state _s);
    Holl& operator=(const Holl& h) {
        f = h.f;
        StartTime = h.StartTime;
        FinishTime = h.FinishTime;
        CountOfSits = h.CountOfSits;
        s = h.s;
        return *this;
    }
};

void seeVisits(Holl& h, int acscess_level); // реализовать
void addVisitA(User& us, int acscess_level); // реализовать
void deletVisitA(User& us, int acscess_level); // реализовать

class Admin //обьект создается
{
    int id;
    CString Password;
    CString name;
    CString surename;
    int acscess_level = 1;
public:
    Admin(int id, CString password, CString name, CString surename);

    ~Admin();
    int get_id();
    CString get_password();
    CString get_name();
    CString get_surename();

    void set_name(CString name);
    void set_surename(CString surename);
    void set_id(int i);
    void set_password(CString str);

    Film createFilm();
    Film createFilm(CTime timeofgoes, float rate, CString name, CString type, int costforticket, CDate livebefore);
    void deleteFilm(Film& f);

    Holl createHoll();
    Holl createHoll(Film F, CTime starttime, CTime finishtime, int countofsits, Holl_state s);
    void redactHole(Holl& h, int i); // реализовать 
    void deleteHoll(Holl& h);
};



//typedef TArchive<Admin> Admins;

//typedef TArchive<Film> Films;

typedef TArchive<Holl> Holls;

//typedef TArchive<Cinema> Cinemas;

class User 
{
    int id;
    CString Password;
    CString name;
    CString Surename;
    Holls visits;
    int acscess_level = 0;
public:
    /*User(); 
    User(int id, CString password, Holls visits);

    ~User();

    int get_id();
    CString get_password();
    Holls get_visits();

    void set_id(int _id);
    void set_password(CString _password);
    void set_visits(Holls _visits);

    void addVisit(Holl& h1);
    void delletVisit(int index, Holl& h1);

    bool login(int login, CString password, const TArchive<User>& user);
    User* registrate(int login, CString password, TArchive<User>& user);*/
};

class Cinema //обьект создается
{
    CString adress;
    Holls hols;
public:
    Cinema();
    Cinema(CString adress, Holls holls);

    ~Cinema();

    CString getadress();
    Holls getHolls();
    void setAdress(CString adress);
    void setHolls(Holls holls);
};