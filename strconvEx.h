/* strconvQt.h v1.0.0              */
/* Last Modified: 2021/05/22 15:48 */
#ifndef STRCONVEX_H
#define STRCONVEX_H

#include "strconv.h"

extern "C" void __wgetmainargs(int *, wchar_t ***, wchar_t ***, int, int *);

static inline std::vector<wchar_t *> get_wide_args()
{
  int argc, si = 0;
  wchar_t **argv, **env;
  __wgetmainargs(&argc, &argv, &env, 0, &si);
  std::vector<wchar_t *> result;
  for (int i = 0; i < argc; i++)
  {
    result.push_back(argv[i]);
  }
  return result;
}

static inline std::vector<char *> get_utf8_args()
{
  int argc, si = 0;
  wchar_t **argv, **env;
  __wgetmainargs(&argc, &argv, &env, 0, &si);
  std::vector<char *> result;
  for (int i = 0; i < argc; i++)
  {
    result.push_back(strdup(wide_to_utf8(argv[i]).c_str()));
  }
  return result;
}

static inline std::vector<char *> get_ansi_args()
{
  int argc, si = 0;
  wchar_t **argv, **env;
  __wgetmainargs(&argc, &argv, &env, 0, &si);
  std::vector<char *> result;
  for (int i = 0; i < argc; i++)
  {
    result.push_back(strdup(wide_to_ansi(argv[i]).c_str()));
  }
  return result;
}

#endif /* STRCONVEX_H */
