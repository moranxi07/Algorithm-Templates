
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct City {
    int south;
    int north;
};

int main() {
    int n;
    cin >> n;
    
    vector<City> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i].south >> cities[i].north;
    }
    
    sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
        return a.south < b.south;
    });
    
    // 提取北岸坐标
    vector<int> norths;
    for(int i = 0; i < n; i++) {
        norths.push_back(cities[i].north);
    }
    
    // 对北岸坐标求 LIS（使用二分法）
    vector<int> lis;
    for(int i = 0; i < n; i++) {
        int x = norths[i];
        
        int l = 0, r = (int)lis.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(lis[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if(l == (int)lis.size()) {
            lis.push_back(x);
        } else {
            lis[l] = x;
        }
    }
    
    cout << lis.size() << endl;
    return 0;
}