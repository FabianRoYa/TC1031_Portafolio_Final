// ========================================================
// File: Boat.h
// Author: Fabian Erubiel Rojas Yañez A01706636
// Clase Bat para manejar los datos y vectores.
// ========================================================

#ifndef BOAT_H
#define BOAT_H
#include <string>

using namespace std;

class Boat{
public:
  string date, hour, entry, UBI;
  Boat(string, string, string, string);
  bool operator>(Boat &);
  friend ostream &operator<<(ostream &os, const Boat &boat);
};

Boat::Boat(string d, string h, string e, string U){
  date = d;
  hour = h;
  entry = e;
  UBI = U;
};

bool Boat::operator>(Boat &other){
  if (stoi(date.substr(3, 2)) > stoi(other.date.substr(3, 2))){
    return true;
  }
  else if (stoi(date.substr(3, 2)) < stoi(other.date.substr(3, 2))){
    return false;
  }
  else{
    if (stoi(date.substr(0, 2)) > stoi(other.date.substr(0, 2))){
      return true;
    }
    else{
      return false;
    }
  }
}

ostream &operator<<(ostream &os, const Boat &boat){
  os << boat.date << " " << boat.hour << " " << boat.entry << " " << boat.UBI;
  return os;
}

#endif
