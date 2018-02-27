#include "native.h"

using namespace native;
using namespace std;

int main(){

  Fileclass fileclass("Alexander Obi");
  string name = fileclass.getName();
  string file = fileclass.readFromFile("test.txt");
  cout << name << endl;
  cout << file;
  return 0;
}