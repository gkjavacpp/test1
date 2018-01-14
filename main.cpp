/* SelfAvoidingWalk*/
/*
 Creates an array, creates a random path, initializes at the center of the array.
 Can move from 1 to 0, but not from 1 to 1 or 0 to 1.
 If escaped form the array- quit while loop.
 If cannot move, then deadEnd, then escape from while loop and increase the number of deadEnd by 1.
 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;


int main(int argc, const char * argv[]) {
    
    // dimensions
    int N = 50;
    int T = 1200;
    int deadEnds = 0;
    
    srand(time(NULL));
    
    
#pragma omp parallel for reduction(+:deadEnds)
    for (int k=0; k<T; k++) {
        
            // dynamic allocation
            bool** ary = new bool*[N];
            for(int i = 0; i < N; ++i)
                ary[i] = new bool[N];
    
            // fill
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    ary[i][j] = false;
    
//            // print
//            for(int i = 0; i < N; ++i) {
//                for(int j = 0; j < N; ++j)
//                    cout << ary[i][j];
//                cout << "\n";
//            }
//        cout<<" "<<endl;
        
        
        int x = N/2;
        int y = N/2;
        while (x>0 && x<(N-1) && y>0 && y<(N-1)){
            
            ary[x][y]= true;
            
            if (ary[x-1][y] && ary[x+1][y] && ary[x][y-1] && ary[x][y+1]) {
                deadEnds++;
                break;
                
            }
            
 
            double r = double(rand()%10)/double(10.0);
            
            if (r<0.25) {
                if (!ary[x+1][y]) x++;
                
            }
            else if (r<0.50) {
                if (!ary[x-1][y]) x--;
                
            }
            else if (r<0.75) {
                if (!ary[x][y+1]) y++;
                
            }
            else if (r<1.10) {
                if (!ary[x][y-1]) y--;
                
            }
            
        }
        
                    // print später auskommentieren
                    for(int i = 0; i < N; ++i) {
                        for(int j = 0; j < N; ++j)
                            cout << ary[i][j];
                        cout << "\n";
                    }
                cout<<" "<<endl;
        // free
        for(int i = 0; i < N; ++i)
            delete [] ary[i];
        delete [] ary;
        
        
    }
    cout <<double(rand()%10)/double(10.0) << endl;
    cout <<100*deadEnds/T<< " % dead Ends" << endl;
 
}
