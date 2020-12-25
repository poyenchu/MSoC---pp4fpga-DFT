# MSoC - [pp4fpga] DFT



<br />
<p align="center">  
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [Usage](#usage)
* [References](#References)
* [Contributing](#contributing)


<!-- ABOUT THE PROJECT -->
## About The Project
Using high level synthesis to accelerate 1024-DFT and implementation on Zedboard.  

**Directory structure**
* **README.md** - introduce the project, usage and reference 
* **hls/** - source files for HLS project 
  * dft.h
  * coefficients1024.h
  * dft.cpp
  * dft_test.cpp
  * directives.tcl
* **vivado/**  -  bitstream from vivado 
  * DFT.bit
  * DFT.hwh
* **python/**  -  Run on zedboard 
  * DFT.ipynb 

<!-- USAGE EXAMPLES -->
## Usage
1. HLS <br>
(1) create the hls project <br>
(2) add dft.cpp, dft.h, coefficients1024.h to source <br>
(3) add dft_test.cpp to Testbench <br>
(4) Set directives from directive.tcl <br>
(5) C-Sim, synthesis and Co-sim could work <br>

2. System on board <br>
(1) fpga board setup <br>
    We use **Xilinx ZedBoard Evaluation and Development Kit** to evaulate this project <br>
(2) put DFT.bit and DFT.hwh on Zedboard <br>
(3) python DFT.ipynb <br>

## References
1. https://github.com/KastnerRG/pp4fpgas/tree/master/examples

<!-- CONTRIBUTING -->
## Contributing
Code modification and use AXI-Master protocol
