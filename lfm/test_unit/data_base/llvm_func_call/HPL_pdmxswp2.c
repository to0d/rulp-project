#include "hpl.h"

#ifdef STDC_HEADERS
void HPL_pdmxswp
(
   HPL_T_panel *                    PANEL,
   const int                        M,
   const int                        II,
   const int                        JJ,
   double *                         WORK
)
#else
void HPL_pdmxswp
( PANEL, M, II, JJ, WORK )
   HPL_T_panel *                    PANEL;
   const int                        M;
   const int                        II;
   const int                        JJ;
   double *                         WORK;
#endif
{

   double                     gmax, tmp1;
   double                     * A0, * Wmx, * Wwork;
   HPL_T_grid                 * grid;
   //MPI_Comm                   comm;
   unsigned int               hdim, ip2, ip2_, ipow, k, mask;
   int                        Np2, cnt_, cnt0, i, icurrow, lda, mydist,
                              mydis_, myrow, n0, nprow, partner, rcnt,
                              root, scnt, size_;
/* ..
 * .. Executable Statements ..
 */

#ifdef NLOG
  printf("NLOG: HPL_pdmxswp start\n");
#endif

#ifdef HPL_DETAILED_TIMING
   HPL_ptimer( HPL_TIMING_MXSWP );
#endif
   grid = PANEL->grid; myrow = grid->myrow; nprow = grid->nprow;
/*
 * ip2  : the smallest power of two less than or equal to nprow;
 * hdim : dimension of the hypercube made of those ip2 processes;
 * Np2  : logical flag indicating whether or not nprow is a power of 2;
 */
   //comm    = grid->col_comm; 
   ip2 = (unsigned int)(grid->row_ip2);
   hdim    = (unsigned int)(grid->row_hdim);     n0  = PANEL->jb;
   icurrow = PANEL->prow; Np2 = (int)( ( size_ = nprow - ip2 ) != 0 );
   mydist  = MModSub( myrow, icurrow, nprow );
/*
 * Set up pointers in workspace:  WORK and Wwork  point to the beginning
 * of the buffers of size 4 + 2*N0 to be combined. Wmx points to the row
 * owning the local (before combine) and global (after combine) absolute
 * value max. A0 points to the copy of the current row of the matrix.
 */
   cnt0  = ( cnt_ = n0 + 4 ) + n0; A0 = ( Wmx = WORK + 4 ) + n0;
   Wwork = WORK + cnt0;
/*
 * Wmx[0:N0-1] := A[ilindx,0:N0-1] where ilindx is  (int)(WORK[1])  (row
 * with max in current column). If I am the current process row, pack in
 * addition the current row of A in A0[0:N0-1].  If I do not own any row
 * of A, then zero out Wmx[0:N0-1].
 */
   if( M > 0 )
   {
      lda = PANEL->lda;
NTRACE; HPL_dcopy( n0, Mptr( PANEL->A, II+(int)(WORK[1]), 0, lda ), lda,
                 Wmx, 1 );
      if( myrow == icurrow )
      { 
NTRACE; HPL_dcopy( n0, Mptr( PANEL->A, II, 0, lda ), lda, A0, 1 ); 
      }
   }
   else { for( i = 0; i < n0; i++ ) Wmx[i] = HPL_rzero; }


/*
 * End of HPL_pdmxswp
 */
}
