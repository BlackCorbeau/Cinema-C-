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
};
enum Holl_state { Empty = 1, Full =2, Not_Empty=3, Already=4 };
class Holl // обьект создается
{
    Film& f;
    CTime StartTime;
    CTime FinishTime;
    int CountOfSits;
    Holl_state s;
public:
    /*Holl(); //поправить у всех 3-х конструкторах реализацию и написать ее
    Holl(Holl& h);
    Holl(Film& F, CTime starttime, CTime finishtime, int countofsits, Holl_state s);*/

    ~Holl();

    /*Film getFilm();
    CTime getStartTime();
    CTime getFinishTime();
    int getCountOfSits();
    Holl_state getstates();

    void setFilm(Film f);
    void setStartTime(CTime ST);
    void setFinishTime(Film f);
    void setCountOfSits(int count);
    void setstates(int _s);*/
    Holl& operator=(const Holl& h) {
        f = h.f;
        StartTime = h.StartTime;
        FinishTime = h.FinishTime;
        CountOfSits = h.CountOfSits;
        s = h.s;
        return *this;
    }
};

class Admin //обьект создается
{
    int id;
    CString Password;
public:
    Admin(int id, CString password);

    ~Admin();
    int get_id();
    CString get_password();

    void set_id(int i);
    void set_password(CString str);
    Film createFilm();
    Film createFilm(CTime timeofgoes, float rate, CString name, CString type, int costforticket, CDate livebefore);
    void redactFilm(Film& f, int i);
    void deleteFilm(Film& f);

    /*void createHole();
    void redactHole();
    void deleteHoll();

    void seeVisits();
    void addVisitA();
    void deletVisitA();*/

};



//typedef TArchive<Admin> Admins;

//typedef TArchive<Film> Films;

typedef TArchive<Holl> Holls;

//typedef TArchive<Cinema> Cinemas;

class User //обьект создается
{
    int id;
    CString Password;
    Holls visits;
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

//void WriteUsersData(const Users& users, const char* filename)
//{
//    std::ofstream file(filename);
//    if (!file.is_open())
//    {
//    throw std::runtime_error("Failed to open file for writing.");
//    }
//    file << users.size() << '\n';
//    for (int i = 0; i < users.size(); i++)
//    {
//        User newUser = users[i];
//        int __id = newUser.get_id();
//        CString __password = newUser.get_password();
//        TArchive<Holl> _visits = newUser.get_visits();
//        int visitsSize = _visits.size();
//        file << __id << '\n';
//        file << __password << '\n';
//        file << visitsSize << '\n';
//        for (int j = 0; j < visitsSize; j++)
//        {
//            Holl newHall = _visits[j];
//            Film f = newHall.getFilm();
//            CString FilmName = f.getName();
//            CTime start_time = newHall.getStartTime();
//            int _countOfSits = newHall.getCountOfSits();
//            file << FilmName << '\n';
//            file << start_time << '\n';
//            file << _countOfSits << '\n';
//        }
//    }
//    file.close();
//}
//
//
//void readUsersFromFile(Users& users, const char* filename)
//{
//    std::ifstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for reading.");
//    }
//    int count;
//    file >> count;
//    users.reserve(count);
//    for (int i = 0; i < users.size(); i++)
//    {
//        int __id;
//        CString __password;        
//        TArchive<Holl> _visits;
//        int visitsSize;
//        file >> __id;
//        file >> __password ;
//        file >> visitsSize;
//        User newUser = users[i];
//        newUser.set_id(__id);
//        newUser.set_password(__password);
//        TArchive<Holl> __visits;
//        for (int j = 0; j < visitsSize; j++)
//        {
//            Holl newHall;
//            Film f;
//            CString FilmName;
//            CTime start_time;
//            int _countOfSits;
//            file >> FilmName;
//            file >> start_time;
//            file >> _countOfSits;
//            newHall.setFilm(f);
//            f.setName(FilmName);
//            newHall.setStartTime(start_time);
//            newHall.setCountOfSits(_countOfSits);
//            __visits.push_front(newHall);
//        }
//        newUser.set_visits(__visits);
//    }
//    file.close();
//}
//
//void WriteFilmsData(const Films& films, const char* filename)
//{
//    std::ofstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for writing.");
//    }
//    file << films.size() << '\n';
//    for (int i = 0; i < films.size(); i++)
//    {
//        Film newFilm = films[i];
//        CTime TimeOfGoes = newFilm.getTimeOfGoes();
//        float Rate = newFilm.getRate();
//        CString Name = newFilm.getName();
//        CString type = newFilm.getType();
//        int CostForTicket = newFilm.getCostForTicket();
//        CDate liveBefore = newFilm.getliveBefore();
//        file << TimeOfGoes << '\n';
//        file << Rate << '\n';
//        file << Name << '\n';
//        file << type << '\n';
//        file << CostForTicket << '\n';
//        file << liveBefore << '\n';
//    }
//    file.close();
//}
//
//void ReadFilmsFromFile(Films& films, const char* filename)
//{
//    std::ifstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for reading.");
//    }
//    int count;
//    file >> count;
//    films.reserve(count);
//    for (int i = 0; i < films.size(); i++)
//    {
//        Film newFilm;
//        CTime TimeOfGoes;
//        float Rate;
//        CString Name;
//        CString type;
//        int CostForTicket;
//        CDate liveBefore;
//        file >> TimeOfGoes;
//        file >> Rate;
//        file >> Name;
//        file >> type;
//        file >> CostForTicket;
//        file >> liveBefore;
//        newFilm.setTimeOfGoes(TimeOfGoes);
//        newFilm.setRate(Rate);
//        newFilm.setName(Name);
//        newFilm.setType(type);
//        newFilm.setCostForTicket(CostForTicket);
//        newFilm.setliveBefore(liveBefore);
//        films.push_front(newFilm);
//    }
//    file.close();
//}
//void WriteHollsData(const Holls& holls, const char* filename)
//{
//    std::ofstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for writing.");
//    }
//    file << holls.size() << '\n';
//    for (int i = 0; i < holls.size(); i++)
//    {
//        Holl newHoll = holls[i];
//        Film f = newHoll.getFilm();
//        CString FilmName = f.getName();
//        CTime start_time = newHoll.getStartTime();
//        CTime finish_time = newHoll.getFinishTime();
//        int countOfSits = newHoll.getCountOfSits();
//        Holl_state state = newHoll.getstates();
//        file << FilmName << '\n';
//        file << start_time << '\n';
//        file << finish_time << '\n';
//        file << countOfSits << '\n';
//        file << state << '\n';
//    }
//    file.close();
//}
//
//void ReadHollsFromFile(Holls& holls, const char* filename)
//{
//    std::ifstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for reading.");
//    }
//    int count;
//    file >> count;
//    holls.reserve(count);
//    for (int i = 0; i < holls.size(); i++)
//    {
//        Holl newHoll;
//        Film f;
//        CString FilmName;
//        CTime start_time;
//        CTime finish_time;
//        int countOfSits;
//        int state;
//        file >> FilmName;
//        file >> start_time;
//        file >> finish_time;
//        file >> countOfSits;
//        file >> state;
//        newHoll.setFilm(f);
//        f.setName(FilmName);
//        newHoll.setStartTime(start_time);
//        newHoll.setFinishTime(f);
//        newHoll.setCountOfSits(countOfSits);
//        newHoll.setstates(state);
//        holls.push_front(newHoll);
//    }
//    file.close();
//}
//
//void WriteCinemasData(const Cinemas& cinemas, const char* filename)
//{
//    std::ofstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for writing.");
//    }
//    file << cinemas.size() << '\n';
//    for (int i = 0; i < cinemas.size(); i++)
//    {
//        Cinema newCinema = cinemas[i];
//        CString address = newCinema.getadress();
//        TArchive<Holl> holls = newCinema.getHolls();
//        int hollsSize = holls.size();
//        file << address << '\n';
//        file << hollsSize << '\n';
//        for (int j = 0; j < hollsSize; j++)
//        {
//            Holl newHall = holls[j];
//            Film f = newHall.getFilm();
//            CString FilmName = f.getName();
//            CTime start_time = newHall.getStartTime();
//            int _countOfSits = newHall.getCountOfSits();
//            file << FilmName << '\n';
//            file << start_time << '\n';
//            file << _countOfSits << '\n';
//        }
//    }
//    file.close();
//}
//
//void ReadCinemasFromFile(Cinemas& cinemas, const char* filename)
//{
//    std::ifstream file(filename);
//    if (!file.is_open())
//    {
//        throw std::runtime_error("Failed to open file for reading.");
//    }
//    int count;
//    file >> count;
//    cinemas.reserve(count);
//    for (int i = 0; i < cinemas.size(); i++)
//    {
//        Cinema newCinema;
//        CString address;
//        TArchive<Holl> holls;
//        int hollsSize;
//        file >> address;
//        file >> hollsSize;
//        newCinema.setAdress(address);
//        for (int j = 0; j < hollsSize; j++)
//        {
//            Holl newHall;
//            Film f;
//            CString FilmName;
//            CTime start_time;
//            int _countOfSits;
//            file >> FilmName;
//            file >> start_time;
//            file >> _countOfSits;
//            newHall.setFilm(f);
//            f.setName(FilmName);
//            newHall.setStartTime(start_time);
//            newHall.setCountOfSits(_countOfSits);
//            holls.push_front(newHall);
//        }
//        newCinema.setHolls(holls);
//        cinemas.push_front(newCinema);
//    }
//    file.close();
//}