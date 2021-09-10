#ifndef _TASK_1_INCLUDE_TASK_1_PARTICIPANT_H_
#define _TASK_1_INCLUDE_TASK_1_PARTICIPANT_H_

#include <iostream>

#include "task_1/date.h"
#include "task_1/participant.h"
//#include <task_1/date.h>

class Participant
{
public:
  Participant();
  Participant(const char *name, const char *surname, const Date &date);
  Participant(const Participant &copy);
  ~Participant();

  //Getters
  const char *GetName();
  const char *GetSurname();
  Date GetDate();

  //Selectors
  Participant &SetName(const char *name);
  Participant &SetSurname(const char *surname);
  Participant &SetDate(const Date &date);

  void Print();
  friend std::ostream &operator<<(std::ostream &out, const Participant &obj);

private:
  char *name_, *surname_;
  Date date_;
}; //Class (Date)

#endif //Header Guard