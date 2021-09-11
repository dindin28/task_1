#include <task_1/date.h>
#include <task_1/participant.h>
#include <task_1/performance.h>
#include <task_1/competition.h>

#include <iostream>

void EditDate(Date &date)
{
  int ch = -1;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      std::cout << date << std::endl;
      std::cout << "1) SetDay" << std::endl;
      std::cout << "2) SetMonth" << std::endl;
      std::cout << "3) SetYear" << std::endl;
      std::cout << "4) Enter new date" << std::endl;
      std::cout << "0) Previous menu" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2 && ch != 3 && ch != 4);
    switch (ch)
    {
    case (1):
    {
      std::cout << "Current day: " << date.GetDay() << std::endl
                << "Enter new: ";
      int day;
      std::cin >> day;
      date.SetDay(day);
      break;
    } //Case (1)
    case (2):
    {
      std::cout << "Current month: " << date.GetMonth() << std::endl
                << "Enter new: ";
      int month;
      std::cin >> month;
      date.SetMonth(month);
      break;
    } //Case (2)
    case (3):
    {
      std::cout << "Current year: " << date.GetYear() << std::endl
                << "Enter new: ";
      int year;
      std::cin >> year;
      date.SetYear(year);
      break;
    } //Case (3)
    case (4):
    {
      std::cout << "Current date: " << date << std::endl
                << "Enter new: " << std::endl;
      Date new_date;
      std::cin >> new_date;
      date = new_date;
      break;
    } //Case (4)
    } //Switch (ch)
  }   //While(ch != 0)
} //Function (EditDate)

void EditParticipant(Participant &participant)
{
  int ch = -1;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      std::cout << participant << std::endl;
      std::cout << "1) SetName" << std::endl;
      std::cout << "2) SetSurname" << std::endl;
      std::cout << "3) SetDate" << std::endl;
      std::cout << "0) Previous menu" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2 && ch != 3);
    switch (ch)
    {
    case (1):
    {
      std::cout << "Current name: " << participant.GetName() << std::endl
                << "Enter new: ";
      std::string name;
      std::cin >> name;
      participant.SetName(name.c_str());
      break;
    } //Case (1)
    case (2):
    {
      std::cout << "Current surname: " << participant.GetSurname() << std::endl
                << "Enter new: ";
      std::string surname;
      std::cin >> surname;
      participant.SetSurname(surname.c_str());
      break;
    } //Case (2)
    case (3):
    {
      std::cout << "Current date: " << participant.GetDate() << std::endl
                << "Enter new: ";
      Date date;
      std::cin >> date;
      participant.SetDate(date);
      break;
    } //Case (3)
    } //Switch (ch)
  }   //While(ch != 0)
} //Function (EditParticipant)

void EditPerformance(Performance &performance)
{
  int ch = -1;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      std::cout << performance << std::endl;
      std::cout << "1) SetPerformanceType" << std::endl;
      std::cout << "2) SetParticipant" << std::endl;
      std::cout << "3) SetSequenceNumber" << std::endl;
      std::cout << "4) SetResult" << std::endl;
      std::cout << "0) Previous menu" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2 && ch != 3 && ch != 4);
    switch (ch)
    {
    case (1):
    {
      std::cout << "Current performance type(0 -> team, 1 -> individual): " << performance.GetPerformanceType() << std::endl
                << "Enter new(0 -> team, 1 -> individual): ";
      bool performance_type;
      std::cin >> performance_type;
      performance.SetPerformanceType(performance_type);
      break;
    } //Case (1)
    case (2):
    {
      std::cout << "Current participant: " << performance.GetParticipant() << std::endl;
      Participant participant;
      std::cin >> participant;
      performance.SetParticipant(participant);
      break;
    } //Case (2)
    case (3):
    {
      std::cout << "Current sequence number: " << performance.GetSequenceNumber() << std::endl
                << "Enter new: ";
      int sequence_number;
      std::cin >> sequence_number;
      performance.SetSequenceNumber(sequence_number);
      break;
    } //Case (3)
    case (4):
    {
      std::cout << "Current result: " << performance.GetResult() << std::endl
                << "Enter new: ";
      int result;
      std::cin >> result;
      performance.SetResult(result);
      break;
    } //Case (4)
    } //Switch (ch)
  }   //While(ch != 0)
} //Function (EditPerformance)

void EditCompetition(Competition &competition)
{
  bool print_shortly = false;
  int ch = -1;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      if (print_shortly == true)
      {
        competition.Print();
      }
      else
      {
        competition.PrintShortly();
      }
      std::cout << "1) Switch (Print : PrintShortly)" << std::endl;
      std::cout << "2) SetName" << std::endl;
      std::cout << "3) AddPerformance" << std::endl;
      std::cout << "0) Previous menu" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2 && ch != 3);
    switch (ch)
    {
    case (1):
    {
      print_shortly = (!print_shortly);
      break;
    } //Case (1)
    case (2):
    {
      std::cout << "Current name: " << competition.GetName() << std::endl
                << "Enter new: ";
      std::string name;
      std::cin >> name;
      competition.SetName(name.c_str());
      break;
    } //Case (2)
    case (3):
    {
      std::cout << "Enter performance to add: " << std::endl;
      Performance performance;
      std::cin >> performance;
      competition.AddPerformance(performance);
      break;
    } //Case (3)
    } //Switch (ch)
  }   //While(ch != 0)
} //Functon (EditCompetition)

int main()
{
  Date date;
  Participant participant;
  Performance performance;
  Competition competition;
  int ch = -1;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      std::cout << "1) Date edit" << std::endl;
      std::cout << "2) Participant edit" << std::endl;
      std::cout << "3) Performance edit" << std::endl;
      std::cout << "4) Competition edit" << std::endl;
      std::cout << "0) Exit" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2 && ch != 3 && ch != 4);
    switch (ch)
    {
    case (1):
    {
      EditDate(date);
      break;
    } //case (1)
    case (2):
    {
      EditParticipant(participant);
      break;
    } //case (2)
    case (3):
    {
      EditPerformance(performance);
      break;
    } //case (3)
    case (4):
    {
      EditCompetition(competition);
      break;
    } //case (4)
    } //Switch (ch)
  }   //While (ch != 0)
  return 0;
}