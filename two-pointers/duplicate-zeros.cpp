class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int n = arr.size();
        int lengthToFill = 0;
        int read = 0;

        while (lengthToFill < n) {
            if (arr[read] == 0) {
                if (lengthToFill == n - 1) {
                    arr[n - 1] = 0; 
                    n--;
                    break;
                }
                lengthToFill += 2;
            } else {
                lengthToFill += 1;
            }
            read++;
        }


        read--;           
        int write = n - 1;

        while (read >= 0) {
            if (arr[read] == 0) {
                arr[write] = 0;
                arr[write - 1] = 0;
                write -= 2;
            } else {
                arr[write] = arr[read];
                write -= 1;
            }
            read--;
        }
    }
};