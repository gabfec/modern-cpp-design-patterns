#pragma once
#include <algorithm>

struct ChatRoom
{
  vector<Person*> people;

  void broadcast(const string& origin, const string& message);
  void join(Person* p);
  void message(const string& origin, const string& who, const string& message);
};