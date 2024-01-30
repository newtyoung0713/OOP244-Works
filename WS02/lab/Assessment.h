#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H
#include <iostream>
#include <cstdio>
namespace seneca {
  struct Assessment {
    double* m_mark;
    char* m_title;
  };

  bool read(int& value, FILE* fptr);

  bool read(double& value, FILE* fptr);

  bool read(char* cstr, FILE* fptr);

  bool read(Assessment& assess, FILE* fptr);

  void freeMem(Assessment*& aptr, int size);

  int read(Assessment*& aptr, FILE* fptr);

}
#endif // !SENECA_ASSESSMENT_H