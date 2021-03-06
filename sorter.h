/*
 * Copyright (C) 2017 Jussi Pakkanen.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of version 3, or (at your option) any later version,
 * of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #define DLL_PUBLIC __declspec(dllimport)
#else
  #define DLL_PUBLIC __attribute__ ((visibility ("default")))
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef void(*sorter)(void *beginning, int size);

DLL_PUBLIC
sorter build_sorter(const char *type_str, const char *comparer);

#ifdef __cplusplus
}
#endif
