/*
* Copyright (C) 2005-2011 Team XBMC
* http://www.xbmc.org
*
* This Program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2, or (at your option)
* any later version.
*
* This Program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with XBMC; see the file COPYING. If not, write to
* the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
* http://www.gnu.org/copyleft/gpl.html
*
*/

#pragma once

#include <windows.h>

namespace XbmcThreads
{
  /**
   * A thin wrapper around windows thread specific storage
   * functionality.
   */
  template <typename T> class ThreadLocal
  {
    DWORD key;
  public:
    inline ThreadLocal() {  XBMC_ASSERT_NOTEQUALS(TLS_OUT_OF_INDEXES,TlsAlloc()); }

    inline ~ThreadLocal() { XBMC_ASSERT_TRUE(TlsFree(key));  }

    inline void set(T* val) {  XBMC_ASSERT_TRUE(TlsSetValue(key,(LPVOID)val));  }

    inline T* get() { return (T*)TlsGetValue(key); }
  };
}

