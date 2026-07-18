class Solution {
public:
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
};