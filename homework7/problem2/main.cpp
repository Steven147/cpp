# include "adjListGraph.h"

int main()
{
    int N=0, v1, v2, *V, *E;
    std::cin >> N;
    
    V = new int[N];
    for(int i = 0; i < N; ++i) V[i] = i;
    
    E = new int[2*N];
    char item = '\0';
    for(int i = 0; item != '\n';){
        item = std::cin.get();
        if(item - '0' >= 0 and '9' - item >= '0') 
            E[i++] = item - '0';
    }

    adjListGraph<int, int> myGraph(N, V);

    return 0;
}
