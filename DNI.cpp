#include "DNI.hpp"

DNI::DNI():
numeroDni(0){
  std::string cadenaDni;
      for (int indice = 0; indice < 8 ; indice++){
            cadenaDni += std::to_string(rand() % 10);
           }
            numeroDni = std::stoi(cadenaDni);
}

void DNI::imprimirDNI(){
  std::cout << numeroDni << " " ;
}

bool DNI::operator == (const DNI& otroDNI){
  return numeroDni == otroDNI.numeroDni;
}

bool DNI::operator != (const DNI& otroDNI){
  return numeroDni != otroDNI.numeroDni;
}

bool DNI::operator > (const DNI& otroDNI){
  return numeroDni > otroDNI.numeroDni;
}

bool DNI::operator < (const DNI& otroDNI){
  return numeroDni < otroDNI.numeroDni;
}

int DNI::getNumeroDni() const{
  return numeroDni;
}

std::ostream& operator << (std::ostream& out, const DNI& otroDNI){
  out << otroDNI.getNumeroDni();
  return out;
}
