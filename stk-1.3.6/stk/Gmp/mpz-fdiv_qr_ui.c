#include "gmp-stklos.h"
#include "gmp.h"
#include "gmp-impl.h"
#include "longlong.h"
#undef ASSERT
#define ASSERT(expr)
/* mpz_fdiv_qr_ui -- Division rounding the quotient towards -infinity.
   The remainder gets the same sign as the denominator.

Copyright (C) 1994, 1995, 1996, 1999 Free Software Foundation, Inc.

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


unsigned long int
#if __STDC__
mpz_fdiv_qr_ui (mpz_ptr quot, mpz_ptr rem, mpz_srcptr dividend, unsigned long int divisor)
#else
mpz_fdiv_qr_ui (quot, rem, dividend, divisor)
     mpz_ptr quot;
     mpz_ptr rem;
     mpz_srcptr dividend;
     unsigned long int divisor;
#endif
{
  mp_size_t dividend_size;
  mp_size_t size;
  mp_ptr quot_ptr;
  mp_limb_t remainder_limb;

  if (divisor == 0)
    DIVIDE_BY_ZERO;

  dividend_size = dividend->_mp_size;
  size = ABS (dividend_size);

  if (quot->_mp_alloc < size)
    _mpz_realloc (quot, size);

  quot_ptr = quot->_mp_d;

  remainder_limb = mpn_divmod_1 (quot_ptr, dividend->_mp_d, size,
				 (mp_limb_t) divisor);

  if (remainder_limb != 0 && dividend_size < 0)
    {
      mpn_incr_u (quot_ptr, (mp_limb_t) 1);
      remainder_limb = divisor - remainder_limb;
    }

  size -= size != 0 && quot_ptr[size - 1] == 0;
  quot->_mp_size = dividend_size >= 0 ? size : -size;

  rem->_mp_d[0] = remainder_limb;
  rem->_mp_size = remainder_limb != 0;

  return remainder_limb;
}
