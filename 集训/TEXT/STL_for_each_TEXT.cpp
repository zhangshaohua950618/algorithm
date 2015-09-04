	   #include <algorithm>  
    #include <iterator>  
    #include <iostream>  
    #include <vector>  
    using namespace std;  
      
    class GenByTwo {  
        public:  
            GenByTwo (int _seed = 0):seed(_seed){}  
            int operator() () {return seed += 2;}  
      
        private:  
            int seed;  
    };  
      
    void operate(int &rhs)  
    {  
        cout << rhs << " ";  
        rhs += 1;  
    }  
    int main(int argc, char* argv[])  
    {  
        vector<int> v(10);  
   //     generate(v.begin(), v.end(), GenByTwo(2));  
        for_each(v.begin(), v.end(), operate);  
      
        //print  
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));  
      
        return 0;  
    }  
