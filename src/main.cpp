#include <task_1/date.h>
#include <task_1/participant.h>
#include <task_1/performance.h>
#include <task_1/competition.h>

#include <iostream>

int main()
{
  Date date;
  std::cout << date << std::endl;
  Participant participant;
  std::cout << participant << std::endl;
  Performance performance;
  std::cout << performance << std::endl;
  Competition competition;
  competition.Print();
  return 0;
}