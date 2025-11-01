class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        for ( int i = 0; i < nums1.size(); i++)
        {
            bool check = false;
            for (int j = 0; i < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    check = true;
                }
                if (check)
                {
                    if ( nums1[i] < nums2[j])
                    {
                        nge.push_back(nums2[j]);
                        check = false;
                    }
                    
                }
            }
            if (check == false)
            {
                nge.push_back(-1);
            }
            
        }
        return nge;
    }
};