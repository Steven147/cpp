# include "adjListGraph.h"

int main()
{
    int N=0, v1, v2, *V;
    int *E;
    std::cin >> N;
    std::cin.get();//吃回车
    
    V = new int[N];
    for(int i = 0; i < N; ++i) V[i] = i;
    
    E = new int[(N-1)*N/2];
    char item = '\0';
    char item0 = '\0';
    int i;
    for(i = 0; item != '\n';){
        item0 = item;
        item = std::cin.get();
        if(item - '0' >= 0 and '9' - item >= 0) {
            if(item0 - '0' >= 0 and '9' - item0 >= 0){
                --i;
                E[i] = E[i]*10 + (item - '0');
                ++i;
            }
            else{
                E[i++] = item - '0';
            }
                
        }
            
    }
    
    std::cin >> v1 >> v2;
    
    adjListGraph<int, int> myGraph(N, V);
    for(int j = 0; j < i; j += 2)
        myGraph.insert(E[j], E[j+1], 1);
    
    
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
