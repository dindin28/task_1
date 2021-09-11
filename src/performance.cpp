#include <task_1/performance.h>

//Initialization of static variables
int Performance::number_of_performance_ = 0;

// performance_type_= 0(false) => team performance
// performance_type_= 1(true) => individual performance

Performance::Performance()
    : performance_type_(true),
      participant_(Participant()),
      sequence_number_(1),
      result_(100)
{
  number_of_performance_++;
}

Performance::Performance(bool performance_type, Participant participant, int sequence_number, int result)
    : performance_type_(performance_type),
      participant_(participant),
      sequence_number_(sequence_number),
      result_(result)
{
  number_of_performance_++;
}

Performance::Performance(const Performance &copy)
    : performance_type_(copy.performance_type_),
      participant_(copy.participant_),
      sequence_number_(copy.sequence_number_),
      result_(copy.result_)
{
  number_of_performance_++;
}

Performance &Performance::operator=(const Performance &copy)
{
  performance_type_ = copy.performance_type_;
  participant_ = copy.participant_;
  sequence_number_ = copy.sequence_number_;
  result_ = copy.result_;

  return *this;
}

Performance::~Performance() {}

//Getters
bool Performance::GetPerformanceType() { return performance_type_; }
int Performance::GetNumberOfCompetitions() { return number_of_performance_; }
Participant Performance::GetParticipant() { return participant_; }
int Performance::GetSequenceNumber() { return sequence_number_; }
int Performance::GetResult() { return result_; }

//Selectors
Performance &Performance::SetPerformanceType(bool performance_type)
{
  performance_type_ = performance_type;
  return *this;
}

Performance &Performance::SetParticipant(Participant participant)
{
  participant_ = participant;
  return *this;
}

Performance &Performance::SetSequenceNumber(int sequence_number)
{
  sequence_number_ = sequence_number;
  return *this;
}

Performance &Performance::SetResult(int result)
{
  result_ = result;
  return *this;
}

void Performance::Print()
{
  // performance_type_= 0(false) => team performance
  // performance_type_= 1(true) => individual performance
  if (performance_type_ == false)
  {
    std::cout << "Team performance. ";
  }
  else
  {
    std::cout << "Individual performance. ";
  }
  std::cout << participant_ << "(" << sequence_number_ << ", " << result_ << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Performance &obj)
{
  // performance_type_= 0(false) => team performance
  // performance_type_= 1(true) => individual performance
  if (obj.performance_type_ == false)
  {
    out << "Team performance. ";
  }
  else
  {
    out << "Individual performance. ";
  }
  out << obj.participant_ << "(" << obj.sequence_number_ << ", " << obj.result_ << ")";
  return out;
}

std::istream &operator>>(std::istream &in, Performance &obj)
{
  //Performance_type
  std::cout << "Enter new performance type (1 - individual; 0 - team): ";
  in >> obj.performance_type_;

  //Participant
  in >> obj.participant_;

  //Sequence number
  std::cout << "Enter new sequence number for participant: ";
  in >> obj.sequence_number_;

  //Result
  std::cout << "Enter new result for participant: ";
  in >> obj.result_;

  return in;
}