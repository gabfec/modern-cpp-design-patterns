#include <iostream>
#include "Observer.hpp"
#include "Observable.hpp"


class Person : public Observable<Person>
{
  int age{0};
public:
  Person()= default;
  explicit Person(int age) : age(age) {}

  int get_age() const
  {
    return age;
  }

  void set_age(int age)
  {
    if (this->age == age) return;

    auto old_can_vote = get_can_vote();
    this->age = age;
    notify(*this, "age");

    if (old_can_vote != get_can_vote())
      notify(*this, "can_vote");
  }

  bool get_can_vote() const {
    return age >= 16;
  }
};

// observer & observable

struct ConsolePersonObserver
  : public Observer<Person>
{
private:
  void field_changed(Person &source, const std::string &field_name) override
  {
    std::cout << "Person's " << field_name << " has changed to ";
    if (field_name == "age") std::cout << source.get_age();
    if (field_name == "can_vote")
      std::cout << std::boolalpha << source.get_can_vote();
    std::cout << ".\n";
  }
};

int main(int ac, char* av[])
{
  Person p;
  ConsolePersonObserver cp;
  p.subscribe(cp);

  p.set_age(15);
  p.set_age(16);

  return 0;
}