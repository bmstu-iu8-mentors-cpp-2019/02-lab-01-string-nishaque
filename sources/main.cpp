//Copyright 2020 Yulia Timoshenko timoshenkojulie01@gmail.com
#include "string.hpp"

int main() {
  String animal1("cat");
  String name1("black");
  String space(" ");
  String id1;
  String animal3 = animal1;
  id1 = animal1 + name1;
  id1 += space;
  id1 *= 2;
  std::cout << id1 << std::endl;
  size_t liter = id1.Find(String("ck"));
  std::cout << liter << std::endl;
  String animal2("dog");
  String name2("white");
  if (name1 < name2)
    std::cout << "name 1 < name 2" << std::endl;
  if (animal2 > animal1)
    std::cout << "animal 2 > animal 1" << std::endl;
  if (name1 != animal2)
    std::cout << "name 1 != animal 2" << std::endl;
  if (animal3 == animal1)
    std::cout << "animal 3 = animal 1" << std::endl;
  name1.swap(name2);
  std::cout << "name 1: " << name1 << std::endl;
  std::cout << "name 2: " << name2 << std::endl;
  String name3("oooooopink_____");
  std::cout << "name 3 " << name3 << std::endl;
  name3.LTrim('o');
  name3.RTrim('_');
  std::cout << "name 3 " << name3 << std::endl;
  name3.Replace('i', 'u');
  std::cout << "name 3 " << name3 << std::endl;
  std::cout << "name 3 size = " << name3.Size() << std::endl;
  String zero("");
  std::cout << "zero is empty = " << zero.Empty() << std::endl;
}
