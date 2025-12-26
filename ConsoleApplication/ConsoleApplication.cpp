// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);
bool isBadVersion(int version)
{
    return version == 5;
}
class Solution {
public:
    int firstBadVersion(int n) {
        int lw = 1;
        int hg = n;
        int mid;
        int ans = -1;
        while (lw < hg) {
            mid = lw + (hg - lw) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                hg = mid - 1;
            }
            else {
                lw = mid + 1;
            }

        }
        return ans;
    }
    int searchInsert(std::vector<int>& nums, int target) {
        int lw = 0;
        int hg = nums.size() - 1;
        int ans = -1;
        while (lw <= hg) {
            int mid = lw + (hg - lw) / 2;
            ans = mid;
            if (nums[mid] == target) {
                break;
            }
            if (nums[mid] < target) {
                lw = mid + 1;
            }
            else {
                hg = mid - 1;
            }
        }
        return ans;
    }
    int searchRot(std::vector<int>& nums, int target) {
        int lw = 0;
        int hg = nums.size() - 1;
        int ans = -1;
        if (nums[0] == target) {
            return 0;
        }
        if (nums[nums.size() - 1] == target) {
            return nums.size() - 1;
        }
        if (nums.size() <= 2) {
            return ans;
        }
        while (lw <= hg) {
            int mid = lw + (hg - lw) / 2;;
            bool b = nums[mid] == target;
            std::cout << mid << ". " << "Is " << nums[mid] << " equals " << target << " == " << b << '\n' << nums[mid] << " " << target << '\n';
            std::cout << '\n';
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[0]) {
                if (nums[mid] > target && target > nums[0]) {
                    hg = mid - 1;
                }
                else {
                    lw = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target < nums[0]) {
                    lw = mid + 1;
                }
                else {
                    hg = mid - 1;
                }
            }
        }
        return ans;
    }
    int parseInt(std::string str) {
        int d = std::powf(10, str.length());
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            d = d / 10;
            if (d == 0) {
                d = 1;
            }
            int c = str[i] - '0';
            int n = c * d;
            res += n;
        }
        return res;
    }
    int findPeakElement(std::vector<int>& nums) {
        int lw = 0;
        int hg = nums.size() - 1;
        int ans = -1;
        if (nums.size() < 3) {
            if (nums[lw] > nums[hg]) {
                return lw;
            }
            else {
                return hg;
            }
        }
        if (nums[lw] > nums[hg]) {
            ans = lw;
        }
        else {
            ans = hg;
        }
        while (lw <= hg) {
            int mid = lw + (hg - lw) / 2;
            if (mid > 0 && mid < nums.size() - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
            }
            if (nums[mid + 1] > nums[mid]) {
                lw = mid + 1;
            }
            else {
                hg = mid - 1;
            }
        }
        return ans;
    }
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> smap;
        std::unordered_map<char, int> tmap;
        for (int i = 0; i < s.length(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            bool b = smap.count(s[i]) == tmap.count(s[i]) && smap[s[i]] == tmap[s[i]];
            std::cout << "s=" << s << " i=" << i << " l=" << s.length() << " __ " << "smap[" << s[i] << "]=" << smap[s[i]] << " == tmap[" << s[i] << "]=" << tmap[s[i]] << " is " << b << '\n';
            if (!b) {
                return false;
            }
        }
        return true;
    }
    bool isValidBraces(std::string s) {
        std::vector<char>op = { '(','{','[' };
        std::vector<char>cl = { ')','}',']' };
        std::vector<char>stack;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '(':
            case '{':
            case '[':
                stack.push_back(s[i]);
                break;
            case ')':
                if (stack.size() == 0||stack.back() != op[0]) {
                    return false;
                }
                stack.pop_back();
                break;
            case '}':
                if (stack.size() == 0|| stack.back() != op[1]) {
                    return false;
                }
                stack.pop_back();
                break;
            case ']':
                if (stack.size() == 0|| stack.back() != op[2]) {
                    return false;
                }
                stack.pop_back();
                break;
            }
        }
        return stack.size()==0;
    }
};
int main()
{
    std::string a = "aaca";
    std::string t = "ccac";
    std::unordered_map<char, int> smap;
    std::unordered_map<char, int> tmap;
    for (int i = 0; i < a.length(); i++) {
        smap[a[i]] = smap[a[i]]++;
        tmap[t[i]] = tmap[t[i]]++;
    }
    std::cout << "a: a=" << smap['a'] << " c=" << smap['c'] << '\n';
    std::cout << "t: a=" << tmap['a'] << " c=" << tmap['c'] << '\n';
    auto solution = Solution();
    std::cout << "isAnagram " << solution.isAnagram(a, t) << '\n';
    std::string bracesStr = "]";
    std::cout <<"Is braces string " << bracesStr << " valid: " << solution.isValidBraces(bracesStr) << '\n';
    //std::cout << "Hello World!\n";
    //std::vector<int> arr = { 5, 0, 1, 2, 3, 4};
    std::vector<int> arr = { 4, 5, 6, 7, 8, 1, 2, 3 };
    //std::vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
    //std::vector<int> arr = { 5, 1, 2, 3, 4 };
    int s = arr.size();
    std::cout << "vector size: " << s << '\n';
    int bs = solution.searchInsert(arr, 1);
    std::cout << "binary search: " << bs << '\n';
    int res = solution.firstBadVersion(10);
    std::cout << "first bad version: " << res << '\n';
    int rotmin = solution.searchRot(arr, 8);
    std::cout << "rotated target " << rotmin << '\n';
    std::string input = "15 1";
    std::cout << input << std::endl;
    int n1 = -1;
    std::string buf;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            int b = solution.parseInt(buf);
            if (n1 == -1) {
                n1 = b;
            }
            buf = "";
        }
        else {
            buf += input[i];
        }
        if (n1 == -1 && i == input.length() - 1) {
            n1 = solution.parseInt(buf);
            buf = "";
        }
    }

    std::cout << "tasks: " << n1 + solution.parseInt(buf) << '\n';

    std::vector<int> peak = { 3, 4, 3, 2, 1 };
    int pk = solution.findPeakElement(peak);
    std::cout << "peak element: " << pk << '\n';
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

