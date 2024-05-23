//#include "Models.h"
//
//User::User()
//{
//	id = 0;
//	Password = "";
//	visits;
//}
//
//int User::get_id()
//{
//	return id;
//}
//
//CString User::get_password()
//{
//	return Password;
//}
//
//TArchive<Holl> User::get_visits()
//{
//	return visits;
//}
//
//void User::set_id(int _id)
//{
//	id = _id;
//}
//
//void User::set_password(CString _password)
//{
//	Password = _password;
//}
//
//void User::set_visits(Holls _visits)
//{
//	visits = _visits;
//}
//
//void User::addVisit(Holl& h1)
//{
//	visits.push_front(h1);
//	h1.setstates(3);
//}
//
//void User::delletVisit(int index, Holl& h1)
//{
//	visits.remove_by_index(index);
//	h1.setstates(1);
//}
//
//bool User::login(int login, CString password, const TArchive<User>& user)
//{
//	for (int i = 0; i < user.size(); i++)
//	{
//		User newuser = user[i];
//		int NL = newuser.get_id();
//		CString NP = newuser.get_password();
//		if (login == NL && password == NP)
//		{
//			return true;
//		}
//		else
//		{
//			continue;
//		}
//	}
//	return 0;
//}
//
//User* User::registrate(int login, CString password, TArchive<User>& user)
//{
//	this->id = login;
//	this->Password = password;
//	user.push_front(*this);
//	return this;
//}