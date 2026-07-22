  #include<iostream>
  #include<bits/stdc++.h>
  using namespace std;

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int n=customers.size();
            int unsatisfied_cust=0;
            int max_unsatisfied_cust=0;
            
            for(int i=0;i<minutes;i++){
                  unsatisfied_cust+=customers[i]*grumpy[i];
            }
                max_unsatisfied_cust=unsatisfied_cust;

                int i=0;
                int j=minutes;

                while(j<n){
                      unsatisfied_cust+=customers[j]*grumpy[j]; // add new element

                      // remove ith element
                       unsatisfied_cust-=customers[i]*grumpy[i];
                       
                       // update maximum unsatisfied customer vale
                       max_unsatisfied_cust=max(unsatisfied_cust,max_unsatisfied_cust);
                    

                       i++;
                       j++;
                }
             
            for(int i=0;i<n;i++){
                 if(grumpy[i]==0){
                     max_unsatisfied_cust+=customers[i];
                 }
            }

            return max_unsatisfied_cust;
    }

    int main(){
         // example usage
         vector<int> customers={1,0,1,2,1,1,7,5};
         vector<int> grumpy={0,1,0,1,0,1,0,1};
         int minutes=3; 

       int  maxSatisfiedCustomers= maxSatisfied(customers,grumpy,minutes);
       cout<<"Maximum satisfied customers are "<<maxSatisfiedCustomers<<endl;
    } 
