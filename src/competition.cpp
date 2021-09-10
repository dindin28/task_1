#include <task_1/competition.h>

#include <cstring>

Competition::Competition()
    : performance_size_(0)
{
  const char *name = "Olympic Games";
  name_ = new char[strlen(name)];
  strcpy(name_, name);
}

Competition::Competition(const char *name)
    : performance_size_(0)
{
  name_ = new char[strlen(name)];
  strcpy(name_, name);
}

Competition::Competition(const char *name, Performance *performance_pointer, int performance_size)
    : performance_size_(performance_size)
{
  //copy name
  name_ = new char[strlen(name)];
  strcpy(name_, name);

  //copy performance_pointer
  performance_pointer_ = new Performance[performance_size];
  for (int i = 0; i < performance_size; i++)
  {
    performance_pointer_[i] = performance_pointer[i];
  }
}

Competition::Competition(const Competition &copy)
    : performance_size_(copy.performance_size_)
{
  //copy name
  name_ = new char[strlen(copy.name_)];
  strcpy(name_, copy.name_);

  //copy performance_pointer
  performance_pointer_ = new Performance[copy.performance_size_];
  for (int i = 0; i < copy.performance_size_; i++)
  {
    performance_pointer_[i] = copy.performance_pointer_[i];
  }
}

Competition::~Competition()
{
  if (strlen(name_) != 0)
  {
    delete[] name_;
  }
  if (performance_size_ != 0)
  {
    delete[] performance_pointer_;
  }
}

void Competition::AddPerformance(const Performance &performance)
{
  Performance *new_ptr = new Performance[performance_size_ + 1];
  for (int i = 0; i < performance_size_; i++)
  {
    new_ptr[i] = performance_pointer_[i];
  }
  new_ptr[performance_size_] = performance;
  delete[] performance_pointer_;
  performance_pointer_ = new_ptr;
  performance_size_++;
}

const char *Competition::GetName() { return name_; }
Competition &Competition::SetName(const char *name)
{
  if (strlen(name_) != 0)
  {
    delete[] name_;
  }
  name_ = new char[strlen(name)];
  strcpy(name_, name);
  return *this;
}

void Competition::Print()
{
  std::cout << name_ << std::endl;
  for (int i = 0; i < performance_size_; i++)
  {
    std::cout << performance_pointer_[i] << std::endl;
  }
}

void Competition::PrintShortly()
{
  std::cout << name_ << std::endl;
  for (int i = 0; i < performance_size_; i++)
  {
    std::cout << performance_pointer_[i].GetParticipant().GetSurname() << std::endl;
  }
}