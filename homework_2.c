#include <stdio.h>
#include <stdlib.h>
FILE* f;

int main(void)
{
    printf("enter the number of edge - top\n");
    int v;
    int sv;

    scanf("%d",&sv);
    printf("\n");
    scanf("%d",&v);

    int m[sv][v];

    for (int i = 0; i < sv; i++) // completion
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    f = fopen("text.dot","w");
    if (f == NULL)
        return 0;

    fprintf(f,"graph MyGraf {\n");

    for (int i = 0; i < sv; i++)
    {
        int x1 = -1;
        int x2 = -1;

        for (int j = 0; j < v; j++)
        {
            if (m[i][j] == 1 && x1 == -1 )
                x1 = j+1;
            else if (m[i][j] == 1 && x2 == -1 )
                x2 = j+1;
             else if (m[i][j] == 2 )
                x2 = x1 = j+1;
        }

        fprintf(f,"%d -- %d;\n",x1,x2);
    }

    fprintf(f,"}");

    int kols = sv;

    // finding loops and multiple edges
    for (int i = 0; i < sv; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (m[i][j] == 2)
                kols--;
        }
    }
    int sovp;
    for(int p = 0; p < sv; p++)
    {
        kols++;
        for (int i = 0; i < sv; i++)
        {
            sovp = 0;
            for (int j = 0; j < v; j++)
            {
                if ( m[p][j] == m[i][j])
                sovp++;
            }
            if (sovp == sv)
            kols--;
        }
    }

    if (v == 2)
    {
        if (kols >= 1)
            printf("Åhe graph is connected");
        else
            printf("Åhe graph is not connected");
        return 0;
    }
        if (v == 3)
    {
        if (kols >= 2)
            printf("Åhe graph is connected");
        else
            printf("Åhe graph is not connected");
        return 0;
    }

    if ( kols > (0.5*(v-1)*(v-1)) )
        printf("Åhe graph is connected");
    else
        printf("Åhe graph is not connected");

    return 0;
}

