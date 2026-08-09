 int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxarea = 0; 
        while(left < right){
            int width = right -left ;
            int height = min(heights[left],heights[right]);
            int mw = width * height;
            maxarea = max(mw,maxarea);
            if(heights[left]< heights[right]){
                left ++;
            } else {
                right -- ;
            } 
        } return maxarea;
    }