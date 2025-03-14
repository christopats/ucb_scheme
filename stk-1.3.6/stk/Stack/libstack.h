/******************************************************************************
 *
 * l i b s t a c k  . h
 *
 * Copyright � 1997 Erick Gallesio - I3S-CNRS/ESSI <eg@unice.fr>
 * 
 *
 * Permission to use, copy, and/or distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that both the above copyright notice and this permission notice appear in
 * all copies and derived works.  Fees for distribution or use of this
 * software or derived works may only be charged with express written
 * permission of the copyright holder.  
 * This software is provided ``as is'' without express or implied warranty.
 *
 * This software is a derivative work of other copyrighted softwares; the
 * copyright notices of these softwares are placed in the file COPYRIGHTS
 *
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date: 28-Sep-1997 17:30
 * Last file update:  7-Oct-1997 12:07
 *
 ******************************************************************************/


/* 
   This code has been tested on the following architectures/systems

      I386		Linux 2.0 (ELF)
      sun4x		SunOS 4.1.x & SunOS 5.5.x
      Alpha		OSF1 V4.0
      HP		HP-UX B.10.20
      MIPS32		IRIX 6.2   
*/

#define 		   UNKNOWN_ARCH
#define PROCESSOR 	   "UNKNOWN_ARCH"

#define MAX_EXTERNAL_PARAM 16		/* cannot be changed !!! */

typedef union {
  double d;
  float  f[2];
  int    i[2];
  long   l;
} fake_type;

extern fake_type stk_argv[MAX_EXTERNAL_PARAM];
extern int stk_argc;



/* Macros for pushing arguments */
#define init_ext_call()		stk_argc=0;

#define push_char		push_int
#define push_short		push_int
#define push_string		push_ptr
#define push_int(x)		((stk_argc < MAX_EXTERNAL_PARAM)? 	\
				   (stk_argv[stk_argc++].i[0]=(int) (x),\
				    0) :				\
				    -1)
#define push_long(x)		((stk_argc < MAX_EXTERNAL_PARAM)? 	\
				   (stk_argv[stk_argc++].l=(long) (x),	\
				    0) :				\
				    -1)

#if defined(SUN) || defined(I386)
#  define push_float(x)		((stk_argc < MAX_EXTERNAL_PARAM)? 	 \
				   (stk_argv[stk_argc++].f[0]=(float)(x),\
				    0) :				 \
				    -1)
#  define push_double(x)	((stk_argc < MAX_EXTERNAL_PARAM-1)? 	\
				   (stk_argv[stk_argc].d  =(double)(x),	\
				    stk_argv[stk_argc+1].i[0]=		\
					stk_argv[stk_argc].i[1],	\
				    stk_argc +=2,			\
				    0) :				\
				    -1)
#  define push_ptr		push_int
#endif

#if defined(HP)
#  define push_float(x)		((stk_argc < MAX_EXTERNAL_PARAM)? 	 \
				   (stk_argv[stk_argc++].f[0]=(float)(x),\
				    0) :				 \
				    -1)
#  define push_double		stk_push_double	
#  define push_ptr		push_int
#endif

#if defined(ALPHA)
#  define push_float		stk_push_float
#  define push_double(x)	((stk_argc < MAX_EXTERNAL_PARAM)? 	\
				   (stk_argv[stk_argc++].d=(double) (x),\
				    0) :				\
				    -1)
#  define push_ptr		push_long
#endif

#if defined(MIPS32)
#  define push_float		stk_push_float
#  define push_double		stk_push_double
#  define push_ptr		push_long
#endif




/* Macros for calling functions */
#define call_ext_void		call_ext_int
#define call_ext_char		call_ext_int
#define call_ext_short		call_ext_int
#define call_ext_int	   	call_ext_long
#define call_ext_long(fct)	stk_call_long(fct)

#if defined(I386)
#  define call_ext_float	call_ext_double
#endif

#if defined(SUN)||defined(ALPHA)||defined(HP)|| defined(MIPS32)
#  define call_ext_float(fct)	stk_call_float(fct)
#endif

#define call_ext_double(fct)	stk_call_double(fct)

#if defined(ALPHA)
#  define call_ext_ptr(x)	((void*) call_ext_long(x))
#else
#  define call_ext_ptr(x)	((void*) call_ext_int(x))
#endif

#define call_ext_bool		call_ext_char
#define call_ext_string		call_ext_ptr


#ifdef MIPS32
#  define get_argv(x)		stk_argv[x].i[0]
#else
#  define get_argv(x)		stk_argv[x].l
#endif


/* Prototypes of stack functions. Some of them could be inexistent for a
 * particular machine
 */

extern long   stk_call_long  (void *fct);
extern float  stk_call_float (void *fct);
extern double stk_call_double(void *fct);

extern int    stk_push_float(float f);
extern int    stk_push_double(double d);




/* Utility macro */
#define big_switch 								\
  switch  (stk_argc) {								\
    case 0:  return f();							\
    case 1:  return f(get_argv(0));						\
    case 2:  return f(get_argv(0), get_argv(1));				\
    case 3:  return f(get_argv(0), get_argv(1), get_argv(2));			\
    case 4:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3));	\
    case 5:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4));						\
    case 6:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5));				\
    case 7:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6));			\
    case 8:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7));	\
    case 9:  return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8));						\
    case 10: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9));				\
    case 11: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10));			\
    case 12: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10), get_argv(11));	\
    case 13: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10), get_argv(11),	\
		      get_argv(12));						\
    case 14: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10), get_argv(11),	\
		      get_argv(12), get_argv(13));				\
    case 15: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10), get_argv(11),	\
		      get_argv(12), get_argv(13), get_argv(14));		\
    case 16: return f(get_argv(0), get_argv(1), get_argv(2), get_argv(3),	\
		      get_argv(4), get_argv(5), get_argv(6), get_argv(7),	\
		      get_argv(8), get_argv(9), get_argv(10), get_argv(11),	\
		      get_argv(12), get_argv(13), get_argv(14), get_argv(15));	\
  }
