# include "adjListGraph.h"

int main()
{
    int N=0, v1, v2, *V;
    int *E;
    //*E2;
//    int E[20] = {0,}, E2[20] = {0,};
    std::cin >> N;
    std::cin.get();//吃回车
    
    V = new int[N];
    for(int i = 0; i < N; ++i) V[i] = i;
    
    E = new int[(N-1)*N/2];
    //E2 = new int[(N-1)*N/2];
    char item = '\0';
    int i;
    for(i = 0; item != '\n';){
        item = std::cin.get();
        if(item - '0' >= 0 and '9' - item >= 0) 
            E[i++] = item - '0';
    }
//    for(int j = 0; j < i; ++j)
//    {
//        E2[j] = E[i - 1 - j];
//    }
//
    std::cin >> v1 >> v2;
    
    adjListGraph<int, int> myGraph(N, V);
//    adjListGraph<int, int> myGraph2(N, V);
    for(int j = 0; j < i; j += 2)
        myGraph.insert(E[j], E[j+1], 1);
    
//    for(int j = 0; j < i; j += 2)
//        myGraph2.insert(E2[j], E2[j+1], 1);
    
//    myGraph.dfs();
//    myGraph2.dfs();
    

    
    
    int road[20], length = 0;
    
    if(myGraph.findRoad(v1, v2, road, length)){
        for(int i = length-1; i >= 0; --i){
            std::cout << road[i] << ' ';
        }
        std::cout << std::endl;
    }
    else std::cout << "false" << std::endl;
    
    if( myGraph.hasLoop()) std::cout << "loop" << std::endl;
    else{
        myGraph.topSort();
    }
    
    
    
    return 0;
}
