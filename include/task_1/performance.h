#ifndef _TASK_1_INCLUDE_TASK_1_PERFORMANCE_H_
#define _TASK_1_INCLUDE_TASK_1_PERFORMANCE_H_

#include <task_1/participant.h>

class Performance
{
public:
  Performance();
  Performance(bool performance_type, Participant participant, int sequence_number, int result);
  Performance(const Performance &copy);
  ~Performance();

  //Getters
  bool GetPerformanceType();
  int GetNumberOfCompetitions();
  Participant GetParticipant();
  int GetSequenceNumber();
  int GetResult();

  //Selectors
  Performance &SetPerformanceType(bool performance_type);
  Performance &SetParticipant(Participant participant);
  Performance &SetSequenceNumber(int sequence_number);
  Performance &SetResult(int result);

  void Print();

  friend std::ostream& operator<< (std::ostream &out, const Performance &obj);
  friend std::istream& operator>> (std::istream &in, Performance &obj);

private:
  // performance_type_= 0(false) => team performance
  // performance_type_= 1(true) => individual performance
  bool performance_type_;
  static int number_of_performance_;
  Participant participant_;
  int sequence_number_, result_;
}; //Class (Performance)

#endif //Header Guard