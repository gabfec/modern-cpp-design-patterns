#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main()
{
  Person p = Person::create()
    .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
    .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

  std::cout << p << std::endl;
  getchar();
  return 0;
}
