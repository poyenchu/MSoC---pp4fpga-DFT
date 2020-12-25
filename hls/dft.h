#include <ap_axi_sdata.h>
#include <hls_stream.h>
typedef float DTYPE;

#include "coefficients1024.h"
#define SIZE 1024 		/* SIZE OF DFT */
void dft(volatile DTYPE* out_real, volatile DTYPE* out_imag,volatile DTYPE* XX_R,volatile DTYPE* XX_I);
