#ifndef _TASK_1_INCLUDE_TASK_1_COMPETITION_H_
#define _TASK_1_INCLUDE_TASK_1_COMPETITION_H_

#include <task_1/performance.h>

class Competition
{
public:
  Competition();
  Competition(const char *name);
  Competition(const char *name, Performance *performance_pointer, int performance_size);
  Competition(const Competition &copy);
  Competition &operator=(const Competition &copy);
  ~Competition();

  void AddPerformance(const Performance &performance);

  const char *GetName();
  Competition &SetName(const char *name);

  void Print();
  void PrintShortly();

  friend std::ostream& operator<< (std::ostream &out, const Competition &obj);
  friend std::istream& operator>> (std::istream &in, Competition &obj);

private:
  char *name_;
  Performance *performance_pointer_;
  int performance_size_;
}; //Class (Competition)

#endif //Header Guard