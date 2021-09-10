#include <task_1/date.h>
#include <task_1/participant.h>
#include <task_1/performance.h>

#include <iostream>

int main()
{
  Date date;
  Participant participant;
  std::cout << date << std::endl;
  participant.Print();
  Performance performance;
  performance.Print();
  return 0;
}