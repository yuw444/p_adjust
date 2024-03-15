#include "../src/pvalue.h"

int main()
{
    double pvalues[10] = {0.01, 0.03, 0.04, 0.02, 0.08, 0.05, 0.10, 1.0, 0.80, 0.70};

    double *adjusted_pvalues = PAdjust(pvalues, 10, "bonferroni");
    printf("\nbonferroni:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);

    adjusted_pvalues = PAdjust(pvalues, 10, "holm");
    printf("\nholm:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);

    adjusted_pvalues = PAdjust(pvalues, 10, "hommel");
    printf("\nhommel:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);

    adjusted_pvalues = PAdjust(pvalues, 10, "hochberg");
    printf("\nhochberg:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);

    adjusted_pvalues = PAdjust(pvalues, 10, "BH");
    printf("\nBH:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);

    adjusted_pvalues = PAdjust(pvalues, 10, "BY");
    printf("\nBY:\n");
    PrintArrayDouble(adjusted_pvalues, 10);
    free(adjusted_pvalues);
    
    return 0;
}
