#include <3drpg/util/filepaths.hpp>

#ifdef __linux__
#include <unistd.h>
#include <libgen.h>
#include <limits.h>
#endif

namespace rpg {

std::string Filepaths::getFullPath(const char* path) {
#ifdef __linux__
  char result[PATH_MAX];
  ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
  if (count > 0) {
    const char* dir = dirname(result);
    return std::string(dir) + "/" + std::string(path);
  }
  return std::string("");
#elif _WIN32

#else
#error platform not supported!
#endif
}

std::string Filepaths::getWorkingDir() {
  return getFullPath("");
}

}
