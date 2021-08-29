#include <iostream>
#include <vector>
#include <memory>

struct GraphicObject
{
  virtual void draw() = 0;
};

struct Circle : GraphicObject
{
  void draw() override
  {
    std::cout << "Circle" << std::endl;
  }
};

struct Square : GraphicObject
{
  void draw() override
  {
    std::cout << "Square" << std::endl;
  }
};

struct Group : GraphicObject
{
  std::string name;
  std::vector<GraphicObject*> objects;

  explicit Group(const std::string& name)
    : name{name}
  {
  }

  void draw() override
  {
    std::cout << "Group " << name.c_str() << " contains:" << std::endl;
    for (auto& o : objects)
      o->draw();
  }
};

int main()
{
  Group root("root");
  Circle c;
  root.objects.push_back(&c);

  Group subgroup("sub");
  Square s1, s2;
  subgroup.objects.push_back(&s1);
  subgroup.objects.push_back(&s2);

  root.objects.push_back(&subgroup);

  root.draw();

  return 0;
}