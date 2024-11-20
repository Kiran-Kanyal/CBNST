// Gauss Seidel
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of unknowns (order of the matrix): ");
    scanf("%d", &n);
    float A[n][n + 1];
    float x[n], x_old[n];
    float allowedErr;
    int i, j, count = 1;
    printf("Enter coefficients of the system and constants for x1, x2, ..., x%d:\n", n);
    for (i = 0; i < n; i++)
    {
        float diagonal = 0;
        float sum = 0;
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &A[i][j]);
            if (i == j)
                diagonal = fabs(A[i][j]);
            else if (j != n)
                sum += fabs(A[i][j]);
        }

        if (diagonal < sum)
        {
            printf("The system does not satisfy the diagonal dominance condition.\n");
            return -1;
        }
    }
    printf("Enter allowed error: ");
    scanf("%f", &allowedErr);

    for (i = 0; i < n; i++)
    {
        x[i] = 0;
        x_old[i] = 0;
    }

    float max_error;
    do
    {
        max_error = 0;
        for (i = 0; i < n; i++)
        {
            float sum = 0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += A[i][j] * x[j];
                }
            }
            x_old[i] = x[i];
            x[i] = (A[i][n] - sum) / A[i][i];

            float error = fabs(x[i] - x_old[i]);
            if (error > max_error)
                max_error = error;
        }

        printf("Iteration %d:\n", count);
        for (i = 0; i < n; i++)
        {
            printf("x%d = %0.4f\t", i + 1, x[i]);
        }
        printf("\n");
        count++;

    } while (max_error > allowedErr);
    printf("Solution converged:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %0.4f\n", i + 1, x[i]);
    }
    return 0;
}

// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int n;
//     printf("Enter the number of unknowns (order of the matrix): ");
//     scanf("%d", &n);

//     float A[n][n + 1];    // Dynamically sized coefficient matrix
//     float x[n], x_old[n]; // Arrays for storing current and previous values of the unknowns
//     float allowedErr;
//     int i, j, count = 1;

//     // Input the augmented matrix (coefficients and constants)
//     printf("Enter coefficients of the system and constants for x1, x2, ..., x%d:\n", n);
//     for (i = 0; i < n; i++)
//     {
//         int diagonal = 0;
//         int sum = 0;
//         for (j = 0; j <= n; j++)
//         {
//             scanf("%f", &A[i][j]);
//             if (i == j)
//                 diagonal = fabs(A[i][j]);
//             else if (j != n)
//                 sum += fabs(A[i][j]);
//         }
//         // Check for diagonal dominance
//         if (diagonal < sum)
//         {
//             printf("The system does not satisfy the diagonal dominance condition.\n");
//             return -1;
//         }
//     }

//     // Input the allowed error for convergence
//     printf("Enter allowed error: ");
//     scanf("%f", &allowedErr);

//     // Initialize initial guesses to 0
//     for (i = 0; i < n; i++)
//     {
//         x[i] = 0;
//         x_old[i] = 0;
//     }

//     float max_error;
//     do
//     {
//         max_error = 0;
//         // Perform Gauss-Seidel iteration for each unknown
//         for (i = 0; i < n; i++)
//         {
//             float sum = 0;
//             // Compute the sum of known terms
//             for (j = 0; j < n; j++)
//             {
//                 if (i != j)
//                 {
//                     sum += A[i][j] * x[j]; // Use updated values for x[j] where available
//                 }
//             }
//             // Update x[i] using the formula
//             x_old[i] = x[i];                  // Save the old value of x[i] for error computation
//             x[i] = (A[i][n] - sum) / A[i][i]; // Update with new value

//             // Calculate the maximum error in this iteration
//             float error = fabs(x[i] - x_old[i]);
//             if (error > max_error)
//                 max_error = error;
//         }

//         // Print the current iteration results
//         printf("Iteration %d:\n", count);
//         for (i = 0; i < n; i++)
//         {
//             printf("x%d = %0.4f\t", i + 1, x[i]);
//         }
//         printf("\n");

//         count++;

//     } while (max_error > allowedErr); // Stop when error is less than allowed error

//     // Print the final result
//     printf("Solution converged:\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("x%d = %0.4f\n", i + 1, x[i]);
//     }

//     return 0;
// }
