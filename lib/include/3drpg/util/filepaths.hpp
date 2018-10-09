#ifndef RPG_INCLUDED_FILEPATHS
#define RPG_INCLUDED_FILEPATHS

#include <string>

namespace rpg {

struct Filepaths {
  static std::string getFullPath(const char* path);
  static std::string getWorkingDir();
};

}

#endif
