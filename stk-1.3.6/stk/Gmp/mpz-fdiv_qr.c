#include "gmp-stklos.h"
#include "gmp.h"
#include "gmp-impl.h"
#include "longlong.h"
#undef ASSERT
#define ASSERT(expr)
/* mpz_fdiv_qr -- Division rounding the quotient towards -infinity.
   The remainder gets the same sign as the denominator.

Copyright (C) 1994, 1995, 1996, 2000 Free Software Foundation, Inc.

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
mpz_fdiv_qr (mpz_ptr quot, mpz_ptr rem, mpz_srcptr dividend, mpz_srcptr divisor)
#else
mpz_fdiv_qr (quot, rem, dividend, divisor)
     mpz_ptr quot;
     mpz_ptr rem;
     mpz_srcptr dividend;
     mpz_srcptr divisor;
#endif
{
  mp_size_t divisor_size = divisor->_mp_size;
  mp_size_t xsize;
  mpz_t temp_divisor;		/* N.B.: lives until function returns! */
  TMP_DECL (marker);

  TMP_MARK (marker);

  /* We need the original value of the divisor after the quotient and
     remainder have been preliminary calculated.  We have to copy it to
     temporary space if it's the same variable as either QUOT or REM.  */
  if (quot == divisor || rem == divisor)
    {
      MPZ_TMP_INIT (temp_divisor, ABS (divisor_size));
      mpz_set (temp_divisor, divisor);
      divisor = temp_divisor;
    }

  xsize = dividend->_mp_size ^ divisor_size;;
  mpz_tdiv_qr (quot, rem, dividend, divisor);

  if (xsize < 0 && rem->_mp_size != 0)
    {
      mpz_sub_ui (quot, quot, 1L);
      mpz_add (rem, rem, divisor);
    }

  TMP_FREE (marker);
}
