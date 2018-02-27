#include <iostream>

using namespace std;

namespace native {

  class Fileclass {

    private:
      string name;
    public:
      string getName();
      void setName(string n);
      string readFromFile(string file);
      Fileclass (string n);
      Fileclass ();
      ~Fileclass ();
  };

}