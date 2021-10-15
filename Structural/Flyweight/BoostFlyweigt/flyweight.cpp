#include <iostream>
#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>

using namespace boost;
using namespace flyweights;
using namespace std;

// Naive solution
typedef uint32_t key;

struct User
{
  User(const string& first_name, const string& last_name)
    : first_name{add(first_name)}, last_name{add(last_name)} {}

  const string& get_first_name() const
  {
    return names.left.find(last_name)->second;
  }

  const string& get_last_name() const
  {
    return names.left.find(last_name)->second;
  }

  static void info()
  {
    for (auto entry : names.left)
    {
      cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }
  }

  friend ostream& operator<<(ostream& os, const User& obj)
  {
    return os
      << "first_name: " << obj.first_name << " " << obj.get_first_name()
      << " last_name: " << obj.last_name << " " << obj.get_last_name();
  }

protected:
  static bimap<key, string> names;
  static int seed;

  static key add(const string& s)
  {
    auto it = names.right.find(s);
    if (it == names.right.end())
    {
      // add it
      key id = ++seed;
      names.insert(bimap<key, string>::value_type(seed, s));
      return id;
    }
    return it->second;
  }
  key first_name, last_name;
};

int User::seed = 0;
bimap<key, string> User::names{};

void naive_flyweight()
{
  User john_smith{ "John", "Smith" };
  User jane_smith{ "Jane", "Smith" };

  cout << "John " << john_smith << endl;
  cout << "Jane " << jane_smith << endl;

  User::info();
}

// Boost solution

struct User2
{
  flyweight<string> first_name, last_name;

  User2(const string& first_name, const string& last_name)
    : first_name(first_name), last_name(last_name)  {}
};

void boost_flyweight()
{
  User2 john_smith{ "John", "Smith" };
  User2 jane_smith{ "Jane", "Smith" };

  cout << boolalpha;
  cout << (&jane_smith.first_name.get() == &john_smith.first_name.get()) << endl;
  cout << (&jane_smith.last_name.get() == &john_smith.last_name.get()) << endl;
  cout << (&jane_smith.last_name == &john_smith.last_name);
}

int main()
{
  naive_flyweight();
  boost_flyweight();

  return 0;
}
