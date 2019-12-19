# include <iostream>
void input(int, int, int, int*);

int main()
{
    int N=0, *E, v1, v2;
    input(N, v1, v2, E);



    return 0;
}

void input(int N, int v1, int v2, int* E)
{
    std::cin >> N;
    E = new int[2*N];
    char item = '\0';
    int i = 0;
    while(item != '\n')
    {
        item = std::cin.get();
        if(item - '0' >= 0 and '9' - item >= '0') 
            E[i++] = item - '0';
    }
}