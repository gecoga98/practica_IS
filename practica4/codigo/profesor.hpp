//clase profesor
#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class Profesor
{
private:
    string userName_;
    string password_;
    int id_;

public:
  //Profesor();

string getUserName(){return userName_;};
string getPassword(){return password_;};
int getId(){return id_;};

void setUserName(string userName){userName_ = userName;};
void setPassword(string password){password_ = password;};
void setId(int id){id_ = id;};

/*
inline bool loginId(std::string username) QUEDA ESTA PARTE SOLO
{
  std::string cad;
  std::string checkUsername;
  std::string checkId;
  std::ifstream fich;
  bool res = false;
  fich.open("profesores.txt", std::ios::in);
  if(!fich.is_open()){std::cout << "Error al abrir el fichero" << '\n';}
  while(getline(fich, cad))
  {
    if(cad.substr(0, n) == username)
    {
      if(cad.substr())
      std::cout << cad.substr(0, n) << '\n';
      res = true;
    }

      }

  }
fich.close();
return res;
};*/

inline bool loginUsername(std::string username)
{
  std::string cad;
  bool res = false;
  std::string checkUsername;
  std::string checkId;
  std::ifstream fich;
  fich.open("profesores.txt", std::ios::in);
  if(!fich.is_open()){std::cout << "Error al abrir el fichero" << '\n';}

  while(getline(fich, cad))  //Leemos linea a linea
  {
    std::size_t n = cad.find(" ");

    if(cad.substr(0, n) == username)
    {
      std::cout << cad.substr(0, n) << '\n';
      res = true;
    }

}
return res;
fich.close();
};

inline bool loginPassword(std::string username, std::string password)
{
  std::string cad;
  bool res = false;
  std::string checkUsername;
  std::string checkId;
  std::ifstream fich;
  fich.open("profesores.txt", std::ios::in);
  if(!fich.is_open()){std::cout << "Error al abrir el fichero" << '\n';}

  while(!fich.eof())  //Leemos linea a linea
  {
    getline(fich, cad);
    std::size_t n = cad.find(" ");
    std::size_t pass = cad.find("-");
  //  std::cout << "solicita" << '\n';
    //std::cout << cad.substr(n+1, pass - n) << '\n';
    if(cad.substr(0, n) == username && cad.substr(n + 1, pass - n - 1) == password)
    {
        std::cout << cad.substr(n+1, pass - n - 1) << '\n';
        res = true;
    }

  }
  return res;
  fich.close();
};

};

#endif
