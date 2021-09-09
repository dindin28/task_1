#include <task_1/participant.h>

#include <cstring>

Participant::Participant()
    : date_(15, 8, 2002)
{
  strcpy(name_, "Dima");
  strcpy(surname_, "Shtrikker");
}

Participant::Participant(const char *name, const char *surname, const Date &date)
    : date_(date)
{
  strcpy(name_, name);
  strcpy(surname_, surname);
}

Participant::Participant(const Participant &copy)
    : date_(copy.date_)
{
  strcpy(name_, copy.name_);
  strcpy(surname_, copy.surname_);
}

Participant::~Participant()
{
  if (strlen(name_) != 0)
  {
    free(name_);
  }
  if (strlen(surname_) != 0)
  {
    free(surname_);
  }
}

//Getters
const char *Participant::GetName() { return name_; }
const char *Participant::GetSurname() { return surname_; }
Date Participant::GetDate() { return date_; }

//Selectors
Participant &Participant::SetName(const char *name)
{
  if (strlen(name_) != 0)
  {
    free(name_);
  }
  strcpy(name_, name);
  return *this;
}

Participant &Participant::SetSurname(const char *surname)
{
  if (strlen(surname_) != 0)
  {
    free(surname_);
  }
  strcpy(surname_, surname);
  return *this;
}

Participant &Participant::SetDate(const Date &date)
{
  date_ = date;
  return *this;
}

void Participant::Print()
{
  std::cout << name_ << " : "
            << surname_ << " ("
            << date_ << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Participant &obj)
{
  out << obj.name_ << " : "
            << obj.surname_ << " ("
            << obj.date_ << ")";
  return out;
}