#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

class DNI{
    private:
      int numeroDni;
    public:
      DNI();
      void imprimirDNI();
      bool operator == (const DNI& otroDNI);
      bool operator != (const DNI& otroDNI);
      bool operator > (const DNI& otroDNI);
      bool operator < (const DNI& otroDNI);
      int getNumeroDni() const;
};

      std::ostream& operator << (std::ostream& out, const DNI& otroDNI);
