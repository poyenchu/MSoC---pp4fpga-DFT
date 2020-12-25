// #include <math.h>					//Required for cos and sin functions
#include "dft.h"

#define N 1024							// DFT Size

void dft(volatile DTYPE* out_real, volatile DTYPE* out_imag, volatile DTYPE* sample_real, volatile DTYPE* sample_imag) {
// void dft(stream_DTYPE* sample_real, stream_DTYPE* sample_imag) {
	int i, j, k=0 ;
	DTYPE w;
	DTYPE c, s;

	// Temporary arrays to hold the intermediate frequency domain results
	DTYPE temp_real;
	DTYPE temp_imag;
	// stream_each stream_real_each ;
	// stream_each stream_imag_each ;
	// stream_each streamout_real_each ;
	// stream_each streamout_imag_each ;

	// streamout_real_each.last = 0 ;
	// streamout_imag_each.last = 0 ;

	DTYPE t_real ;
	DTYPE t_imag ;


	DTYPE mem_real[N] ;
	DTYPE mem_imag[N] ;
	DTYPE memout_real[N] ;
	DTYPE memout_imag[N] ;

	for (i = 0; i < N; i += 1) {
		mem_real[i] = sample_real[i];
		mem_imag[i] = sample_imag[i] ;
	}


	// Calculate each frequency domain sample iteratively
	for (i = 0; i < N; i += 1) {
		temp_real = 0;
		temp_imag = 0;

		// (2 * pi * i)/N
		w = (2.0 * 3.141592653589  / N) * (DTYPE)i;

		// Calculate the jth frequency sample sequentially
		for (j = 0; j < N; j += 1) {
			// Utilize HLS tool to calculate sine and cosine values
			// c = cos(j * w);
			// s = -sin(j * w);
			c = cos_table[i * j % N];
			s = sin_table[i * j % N];

			// Multiply the current phasor with the appropriate input sample and keep
			// running sum

			temp_real += (mem_real[j] * c - mem_imag[j] * s);
			temp_imag += (mem_real[j] * s + mem_imag[j] * c);

		}
		memout_real[i] = temp_real ;
		memout_imag[i] = temp_imag ;

	}

	// Perform an inplace DFT, i.e., copy result into the input arrays

	//intfloat tmp_memout_real, tmp_memout_imag ;
	for (k = 0; k < N; k += 1) {
		// tmp_memout_real.f = memout_real[k] ;
		// tmp_memout_imag.f = memout_imag[k] ;
		// streamout_real_each.data = tmp_memout_real.data ;
		// streamout_imag_each.data = tmp_memout_imag.data ;
		// streamout_real_each.last = 0 ;
		// streamout_imag_each.last = 0 ;
		// printf("%d : R=%d, I=%d \n", i, tmp_memout_real.data, tmp_memout_imag.data ) ;
/*
		if( k == N-1 ) {
			streamout_real_each.last = 1 ;
			streamout_imag_each.last = 1 ;
		}
*/
		out_real[k] = memout_real[k] ;
		out_imag[k] = memout_imag[k] ;

	}
	return ;
}
