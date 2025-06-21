// User function Template for C++

int nextPrime(int n){
   jump: n=n+1;
    bool flag=true;
    while(true){

        if(n<=1){
            flag=false;
        }
        else{
            for(int i{2};i<=sqrt(n);i++){
                if(n%i==0){
                    flag=false;
                    goto jump;
                 //  break;
                }
            }
        }
        if(flag==true){
            return n;
        }
    }
}