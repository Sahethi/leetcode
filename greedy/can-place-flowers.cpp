class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int size = flowerbed.size();

        if(size == 1){
            if(flowerbed[0] == 1 && n==0) return true;
            else if(flowerbed[0] == 1) return false;
            else if(n == 1 && flowerbed[0] == 0) return true;
            else if(n == 0 && flowerbed[0] == 0) return true;
            return false;
        }

        for(int i=0; i<size; i++){
            if(flowerbed[i] == 0){
                if(i > 0 && i < size-1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    //dont do anything
                    n--;
                    flowerbed[i] = 1;
                }
                if(i == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
                if(i == size-1 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
                if(n <= 0) return true;
            }
            
        }   

        return false;
    }
};