## Disclaimer

The following documentation is modified based on the `?stats::p.adjust` in `R Documentation` that authored by `R Core Team and contributors worldwide`. It is used here under [GPL-2.0 License](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html).

## Adjusted Pvalue

* The [p-value](https://en.wikipedia.org/wiki/P-value) adjustment is widely adapted in Statistics when multiple testings occurs. The actual `C` implementation has not been found to the best of my knowledge. This library is aimed to provide a similiar `API` with `R::stats::p.adjust` without `NA` support. 

* The adjustment methods include the [Bonferroni correction](https://en.wikipedia.org/wiki/Bonferroni_correction) ("bonferroni") in which the p-values are multiplied by the number of comparisons.Less conservative corrections are also included by [Holm (1979)](https://en.wikipedia.org/wiki/Holm%E2%80%93Bonferroni_method) ("holm"), [Hochberg (1988)](https://en.wikipedia.org/wiki/Hochberg%27s_step-up_procedure) ("hochberg"), [Hommel (1988)](https://en.wikipedia.org/wiki/Hommel%27s_method) ("hommel"), [Benjamini & Hochberg (1995)](https://en.wikipedia.org/wiki/False_discovery_rate#Benjamini%E2%80%93Hochberg_procedure) ("BH" or its alias "fdr"), and [Benjamini & Yekutieli (2001)](https://en.wikipedia.org/wiki/False_discovery_rate#Benjamini%E2%80%93Yekutieli_procedure) ("BY"), respectively.A pass-through option ("none") is also included.
  
* The first four methods are designed to give strong control of the family-wise error rate.There seems no reason to use the unmodified Bonferroni correction because it is dominated by Holm's method, which is also valid under arbitrary assumptions.

* Hochberg's and Hommel's methods are valid when the hypothesis tests are independent or when they are non-negatively associated (Sarkar, 1998; Sarkar and Chang, 1997).Hommel's method is more powerful than Hochberg's, but the difference is usually small and the Hochberg p-values are faster to compute.

* The "BH" (aka "fdr") and "BY" methods of Benjamini, Hochberg, and Yekutieli control the false discovery rate, the expected proportion of false discoveries amongst the rejected hypotheses.The false discovery rate is a less stringent condition than the family-wise error rate, so these methods are more powerful than the others.

## How to test the library

* With `cmake >= 3.16.0`
    * `mkdir build`
    * `cmake -B ./build -S .`
    * `cd build/`
    * `make`
    * `./p_adjust`
  
* With `gcc (GCC) >= 9.3.0`

    * `gcc test_vary_argument.c ../src/pvalue.c ../src/utils.c -o p_adjust`
    * `./p_adjust`

## How to use the library

* Copy all the `src` files into your project, `#include "/path/to/pvalue.h"`
* Compile your project with `/path/to/pvalue.c /path/to/utils.c`  

## Reference

* Benjamini, Y., and Hochberg, Y. (1995).Controlling the false discovery rate: a practical and powerful approach to multiple testing._Journal of the Royal Statistical Society Series B_, *57*, 289-300. [doi:10.1111/j.2517-6161.1995.tb02031.x](https://doi.org/10.1111/j.2517-6161.1995.tb02031.x).

* Benjamini, Y., and Yekutieli, D. (2001).The control of the false discovery rate in multiple testing under dependency._Annals of Statistics_, *29*, 1165-1188. [doi:10.1214/aos/1013699998](https://doi.org/10.1214/aos/1013699998).

* Holm, S. (1979).A simple sequentially rejective multiple test procedure._Scandinavian Journal of Statistics_, *6*, 65-70. <https://www.jstor.org/stable/4615733>.

* Hommel, G. (1988).A stagewise rejective multiple test procedure based on a modified Bonferroni test._Biometrika_, *75*, 383-386. [doi:10.2307/2336190](https://doi.org/10.2307/2336190).

* Hochberg, Y. (1988).A sharper Bonferroni procedure for multiple tests of significance._Biometrika_, *75*, 800-803. [doi:10.2307/2336325](https://doi.org/10.2307/2336325).

* Shaffer, J. P. (1995).Multiple hypothesis testing._Annual Review of Psychology_, *46*, 561-584. [doi:10.1146/annurev.ps.46.020195.003021](https://doi.org/10.1146/annurev.ps.46.020195.003021).(An excellent review of the area.)

* Sarkar, S. (1998).Some probability inequalities for ordered MTP2 random variables: a proof of Simes conjecture._Annals of Statistics_, *26*, 494-504. [doi:10.1214/aos/1028144846](https://doi.org/10.1214/aos/1028144846).

* Sarkar, S., and Chang, C. K. (1997).The Simes method for multiple hypothesis testing with positively dependent test statistics._Journal of the American Statistical Association_, *92*, 1601 1608. [doi:10.2307/2965431](https://doi.org/10.2307/2965431).

* Wright, S. P. (1992).Adjusted P-values for simultaneous inference._Biometrics_, *48*, 1005-1013 [doi:10.2307/2532694](https://doi.org/10.2307/2532694).(Explains the adjusted P-value approach.)

## Contact:

Please report the bug through the `Issues` or contact ywang@mcw.edu for further assistance.
