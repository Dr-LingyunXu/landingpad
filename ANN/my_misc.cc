/**********************************************************************/
/*                                                                    */
/*  Copyright (c) 1994                                                */
/*  Larry D. Pyeatt                                                   */
/*  Computer Science Department                                       */
/*  Colorado State University                                         */
/*                                                                    */
/*  Permission is hereby granted to copy all or any part of           */
/*  this program for free distribution.   The author's name           */
/*  and this copyright notice must be included in any copy.           */
/*                                                                    */
/*  Contact the author for commercial licensing.                      */


#include <stddef.h>
#include <sys/types.h>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <my_misc.h>

/***********************************************************************/
/*    Taken directly (almost) from numerical recipes in C.             */

#define INITIAL_SEED time(NULL)
//#define INITIAL_SEED 84985438
#define IA      16807
#define IM      2147483647
#define AM      (1.0/IM)
#define IQ      127773
#define IR      2836
#define NTAB    32
#define NDIV    (1+(IM-1)/NTAB)
#define EPS     1.2e-7
#define RNMX    (1.0-EPS)

float ran1()
     /*
	"Minimal" random number generator of Park and Miller with 
	Bays-Durham shuffle and added safeguards.  Returns a uniform 
	random deviate between 0.0 and 1.0 (exclusive of the endpoint 
	values).  RNMX should approximate the largest floating 
	value that is less than 1.
	*/
{
  int j;
  long k;
  static long iy=0;
  static long iv[NTAB];
  float temp;
  static int firstcall = 1;
  static long idum;

  if(firstcall)
    {
      idum = INITIAL_SEED;
      firstcall = 0;
    }

  if (idum <= 0 || !iy)
    {       /*Initialize*/
      /* Be sure to prevent idum=0 */
      /*      if (-(idum) < 1) idum=1;
              else idum = -(idum);
              */
      if(idum==0)
        idum = INITIAL_SEED;
      if(idum<0)
        idum=-idum;

      /* Load the shuffle table (after 8 warm-ups) */
      for (j=NTAB+7; j>=0; j--)
        {
	  k=(idum)/IQ;
	  idum = IA*(idum-k*IQ)-IR*k;
	  if (idum < 0) idum += IM;
	  if (j < NTAB) iv[j] = idum;
        }
      iy=iv[0];
    }

  k = (idum)/IQ;       /* Start here when not initializing */
  idum = IA*(idum-k*IQ)-IR*k; /* Compute idum=(IA*idum) % IM without
				   overflows by Schrage's method */
  if (idum < 0) idum+=IM;
  j=iy/NDIV;            /* Will be in the range 0..NTAB-1 */
  iy=iv[j];             /* Output previously stored value and refill the
			   shuffle table */

  iv[j] = idum;

  temp = AM*iy;
  if ((temp) > RNMX) return RNMX;       /* Because users don't expect */
  else return temp;                           /*   endpoint values */

}

