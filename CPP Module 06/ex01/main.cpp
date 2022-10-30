#include "data.hpp"

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main() {
  Data d;
  uintptr_t ptr = serialize(&d);
  Data *d2 = deserialize(ptr);

  std::cout <<"Data address:\t\t\t"<< &d << std::endl;
  std::cout <<"Serialized address:\t\t"<< ptr << std::endl;
  std::cout <<"Serialized address(hex):\t"<< std::hex << "  " << ptr << std::endl;
  std::cout <<"Deserialized serialized address:"<< d2 << std::endl;
  return 0;
}
