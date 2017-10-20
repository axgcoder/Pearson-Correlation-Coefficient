 
// Test program for the CSE 6329 Spring 2017 Correlate() function.
// This test program performs the following:
//     1. Prompts the user to enter the size (number of elements) of the data array/s to be processed.
//     2. Prompts the user to enter the data items for the first array.
//     3. Populates the "size" and "ArrayOne[]" parameters with the user-entered data.
//     4. Prompts the user to enter the data items for the second array.
//     3. Populates the "size" and "ArrayTwo[]" parameters with the user-entered data.
//     4. Displays the user-entered inputs:  "size"  and "ArrayOne []", "ArrayTwo []".
//     5. Displays Correlate() outputs: Spearman Coefficient, Correlation Flag inputValidityFlag (Stats() return value).

#include<stdio.h>
#include<math.h>

// Declare Correlate () function
_Bool Correlate (int size, float ArrayOne[], float ArrayTwo[], float *spearmanCoefficient, float *correlationFlag);

int main( )
{
    // Initialize outputs
    float spearmanCoefficient = 0.0;
    float correlationFlag = 0.0;
    
     _Bool inputValidityFlag = 0;
    float ArrayOne[100], ArrayTwo[100];
    
    int i; /* Array index  */

    int size = 0;
   
    
    //Get the size of data set
    
    printf("Enter size of data set\n");
    scanf ("%d", &size);
    printf("\n# elements = %d", size);
    
    //Get input Array One
    printf("\nInput for Array One");
        for(i=0; i <= size-1; i++)
        {
            printf("\nEnter data item: \n");
            scanf("%f", &ArrayOne[i]);
        }

    //Get input Array Two
    printf("Input for Array Two");
        for(i=0; i <= size-1; i++)
        {
            printf("\nEnter data item: \n");
            scanf("%f", &ArrayTwo[i]);
        }

    inputValidityFlag = Correlate (size, ArrayOne, ArrayTwo, &spearmanCoefficient, &correlationFlag);
    printf("\nValidityFlag = %d\n", inputValidityFlag);
    
    if (inputValidityFlag)
    {
        for (i = 0; i <= size-1; i++)
        {
            printf("\nArrayOne[%d] = %10.3f      ArrayTwo[%d] = %10.3f", i, ArrayOne[i], i, ArrayTwo[i]);
        }
        printf("\n Spearman Coefficient = %10.2f", spearmanCoefficient);
        printf("\n Correlation Flag = %10.2f", correlationFlag);
         
    }
    else
    {
        printf("\nInput is invalid; outputs are not displayed\n");
    }
    
    return 1;
}


_Bool Correlate (int size, float arrayOne[], float arrayTwo[], float * spearmanCoefficient, float * correlationFlag)
{
    float meanone=0.0,meantwo=0.0,xxsqr=0.0,yysqr=0.0,xxyy=0.0;
    float xx[100], yy[100];
    int i;
    for(i=0;i<size;i++)
    {
        meanone += arrayOne[i];
    }
    meanone = meanone/size;

    for(i=0;i<size;i++)
    {
        meantwo += arrayTwo[i];
    }
    meantwo = meantwo/size;

    for(i=0;i<size;i++)
    {
        xx[i] = arrayOne[i]-meanone;
        yy[i] = arrayTwo[i]-meantwo;
        xxsqr +=  (xx[i] *  xx[i]);
        yysqr +=  (yy[i] *  yy[i]);
        xxyy  +=  (xx[i]*yy[i]);  

    }
    *spearmanCoefficient = xxyy / sqrt(xxsqr*yysqr);

    if(*spearmanCoefficient>=0.9 || *spearmanCoefficient<=1.0 )
    *correlationFlag = 1.0;
    else if (*spearmanCoefficient>=-0.9 || *spearmanCoefficient<=-1.0 )
   *correlationFlag = -1.0;
    else
    *correlationFlag = 0;
     if(size>0)
     return 1;
     else
     return 0;
}    
    
