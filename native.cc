#include "native.h"
#include <fstream>

using namespace std;
using namespace native;

Fileclass::Fileclass(string n) {
  name = n;
}

Fileclass::~Fileclass() {

}

string Fileclass::getName() {
  return name;
}

void Fileclass::setName(string n) {
  name = n;
}

string Fileclass::readFromFile(string path) {
  ifstream file;
  file.open(path, ios::in);
  string str;
  string line;
  if(file.is_open()){
    while(getline(file, line)){
      str.append(line);
      str.append("\n");
    }
    file.close();
  } else {
    return "Unable to open file"; 
  }
  return str;
}