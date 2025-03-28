#include "gmp-stklos.h"
#include "gmp.h"
#include "gmp-impl.h"
#include "longlong.h"
#undef ASSERT
#define ASSERT(expr)
/* mpz_neg(mpz_ptr dst, mpz_ptr src) -- Assign the negated value of SRC to DST.

Copyright (C) 1991, 1993, 1994, 1995 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */


void
#if __STDC__
mpz_neg (mpz_ptr w, mpz_srcptr u)
#else
mpz_neg (w, u)
     mpz_ptr w;
     mpz_srcptr u;
#endif
{
  mp_ptr wp, up;
  mp_size_t usize, size;

  usize = u->_mp_size;

  if (u != w)
    {
      size = ABS (usize);

      if (w->_mp_alloc < size)
	_mpz_realloc (w, size);

      wp = w->_mp_d;
      up = u->_mp_d;

      MPN_COPY (wp, up, size);
    }

  w->_mp_size = -usize;
}
