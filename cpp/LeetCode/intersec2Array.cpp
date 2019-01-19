class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> vec;
        map<int, int> mp1;
        map<int, int> mp2;
        for (int i = 0; i < nums1.size(); ++i) {
            if (mp1.find(nums1[i]) != mp1.end()) {
                map<int, int>::iterator it = mp1.find(nums1[i]);
                it->second = it->second + 1;
            } else {
                mp1.insert(make_pair(nums1[i], 1));
            }

        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (mp2.find(nums2[i]) != mp2.end()) {
                map<int, int>::iterator it = mp2.find(nums2[i]);
                it->second = it->second + 1;
            } else {
                mp2.insert(make_pair(nums2[i], 1));
            }
        }
        
        map<int, int>::iterator it;

        map<int, int>::iterator it1;
        map<int, int>::iterator it2;
        for (it1 = mp1.begin(); it1 != mp1.end(); it1++) {
            it2 = mp2.find(it1->first);
            if (it2 != mp2.end()) {
                if (it2->second > it1->second) {
                    for (int i = 0; i < it1->second; i++) {
                        vec.push_back(it1->first);
                    }
                } else {
                    for (int i = 0; i < it2->second; i++) {
                        vec.push_back(it2->first);
                    }
                }
            }
        }
        return vec;
    }
};
