/*
program that calculates all the n^m ordenations with repeated elements
transforming the string into a numerical system.
if your processor is 32 bit dont change anything.. if its 64 bit.. read the first line of the source
actually this is insecure and only supports 2^64 combinations but i think 2^64 is enough :p hehe
NOTE: I RECOMMEND REDIRECTING THE OUTPUT TO A FILE.. IT WILL BE EXPONENTIANLLY FASTER
compile in this way:
$ gcc -lm -O3 -funroll-loops -pipe -fomit-frame-pointer -ffast-math -o ord_rep ord_rep.c
run in this way:
$ ./ord_rep ABC 2
by
rduarte@ciencias.unam.mx
*/
typedef unsigned long long _ulong;  /* 64-BIT change "long" instead of "long long" if you can run/create 64 bit executables */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void *convierte (int num, unsigned char base, unsigned char len,unsigned char *dst);
void rx_print (unsigned char *num_base_n, unsigned char *alpha, unsigned int cs, unsigned char *dst);


void *
convierte (int num, unsigned char base, unsigned char len, unsigned char *dst)
{
  int i;
  for (i = (len - 1); i >= 0; i--)
    {
      dst[i] = num % base;
      num = num / base;
    }
  return dst;
}

void
rx_print (unsigned char *num_base_n, unsigned char *alpha, unsigned int cs, unsigned char *dst)
{
  unsigned int i;
  for (i = 0; i < cs; i++)
    dst[i] = alpha[num_base_n[i]];
  printf ("%s\n", dst);
  return;
}


int
main (int argc, char **argv)
{
  int m, n;
  _ulong i,t;
  unsigned char *subset, *final, *alpha;
  if (argc < 3)
    exit (printf("Error:\narg[1] must be the alphabet without spaces\narg[2] must be the cardinality of each subset of the alphabet\nrduarte@ciencias.unam.mx\n"));
  n = strlen (argv[1]);
  m = atoi (argv[2]);
  t = (_ulong)pow (n, m);
  alpha = argv[1];
  subset = (char *) malloc (m + 1);
  final = (char *) malloc (m + 1);
  memset (subset, 0x0, m + 1);
  memset (final, 0x0, m + 1);
  for (i = 0; i < t; i++)
    {
      convierte (i, n, m, subset);
      rx_print (subset, alpha, m, final);
    }
  free(final);
  free (subset);
  printf("Calculated %Ld ordenations\n",t);
  return 0;
}
