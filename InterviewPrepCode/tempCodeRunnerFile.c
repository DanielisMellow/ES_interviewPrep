    int *B[3];
    B[0] = (int *)malloc(3 * sizeof(int));
    B[1] = (int *)malloc(3 * sizeof(int));
    B[2] = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            B[i][j] = j;
    }

    for (int i = 0; i < 3; i++)
    {
        free(B[i]);
    }